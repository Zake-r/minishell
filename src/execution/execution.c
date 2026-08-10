#include "../../inc/minishell.h"

void	free_one_ast_node(t_ast *ast)
{
	int	i;

	i = 0;
	if (ast->args)
	{
		while (ast->args[i])
		{
			free(ast->args[i]);
			i++;
		}
		free(ast->args);
	}
	free(ast);
}

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	free_ast(ast->right);
	free_ast(ast->left);
	free_one_ast_node(ast);
}

/*
** Convertit un status de waitpid() en exit code bash-like :
** - process terminé normalement -> WEXITSTATUS
** - process tué par un signal -> 128 + numéro du signal
*/
int	status_to_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

void	exec_cmd(t_ast *ast, char ***env)
{
	pid_t	pid;
	char	*cmd;
	int		status;

	cmd = NULL;
	if (is_builtin(ast->args[0]))
	{
		exec_builtin(ast, env);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		free_ast(ast);
		return ;
	}
	if (pid == 0)
	{
		cmd = verif_command(ast->args[0], *env);
		if (!cmd)
		{
			fprintf(stderr, "bash: %s: command not found\n", ast->args[0]);
			free_ast(ast);
			exit(127);
		}
		execve(cmd, ast->args, *env);
		perror("erreur execve");
		free(cmd);
		free_ast(ast);
		if (errno == EACCES)
			exit(126);
		exit(127);
	}
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
	free(cmd);
}

void	exec_pipe(t_ast *ast, char ***env)
{
	pid_t	pid_l;
	pid_t	pid_r;
	int		fd[2];
	int		status_r;

	if (pipe(fd) == -1)
	{
		perror("erreur pipe");
		g_exit_status = 1;
		return ;
	}
	pid_l = fork();
	if (pid_l == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		free_ast(ast);
		return ;
	}
	if (pid_l == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_ast(ast->left, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	pid_r = fork();
	if (pid_r == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		free_ast(ast);
		return ;
	}
	if (pid_r == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exec_ast(ast->right, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_l, NULL, 0);
	waitpid(pid_r, &status_r, 0);
	g_exit_status = status_to_exit_code(status_r);
}

void	exec_redirout(t_ast *ast, char ***env)
{
	int		fd;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		free_ast(ast);
		return ;
	}
	if (pid == 0)
	{
		fd = open(ast->right->args[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(ast->right->args[0]);
			free_ast(ast);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		exec_ast(ast->left, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}

void	exec_append(t_ast *ast, char ***env)
{
	int		fd;
	pid_t	pid;
	char	*filename;
	int		status;

	filename = ast->right->args[0];
	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		return ;
	}
	if (pid == 0)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror(filename);
			free_ast(ast);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		exec_ast(ast->left, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}

void	exec_redirin(t_ast *ast, char ***env)
{
	int		fd;
	pid_t	pid;
	char	*filename;
	int		status;

	filename = ast->right->args[0];
	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		return ;
	}
	if (pid == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			perror(filename);
			free_ast(ast);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		exec_ast(ast->left, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}

void	exec_heredoc(t_ast *ast, char ***env)
{
	int		fd[2];
	pid_t	pid;
	char	*line;
	char	*delim;
	int		status;

	delim = ast->right->args[0];
	if (pipe(fd) == -1)
	{
		perror("error pipe");
		g_exit_status = 1;
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		return ;
	}
	if (pid == 0)
	{
		signal(SIGINT, handle_ctrlc_heredoc);
		while (1)
		{
			line = readline("heredoc> ");
			if (!line || ((ft_strlen(line) == ft_strlen(delim))
					&& (!ft_strncmp(line, delim, ft_strlen(delim)))))
			{
				free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exec_ast(ast->left, env);
		free_ast(ast);
		exit(g_exit_status);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}

void	exec_ast(t_ast *ast, char ***env)
{
	if (!ast)
		return ;
	else if (ast->type == WORD)
		exec_cmd(ast, env);
	else if (ast->type == PIPE)
		exec_pipe(ast, env);
	else if (ast->type == REDIR_OUT)
		exec_redirout(ast, env);
	else if (ast->type == REDIR_IN)
		exec_redirin(ast, env);
	else if (ast->type == APPEND)
		exec_append(ast, env);
	else if (ast->type == HEREDOC)
		exec_heredoc(ast, env);
}