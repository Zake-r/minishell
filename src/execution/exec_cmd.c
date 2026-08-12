/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:11 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/12 15:41:59 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	status_to_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

static void	print_exec_error(char *arg, char *msg)
{
	write(2, "bash: ", 6);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
}

static void	handle_cmd_not_found(t_ast *ast)
{
	if (errno == EACCES)
	{
		print_exec_error(ast->args[0], "Permission denied\n");
		free_ast(ast);
		exit(126);
	}
	print_exec_error(ast->args[0], "command not found\n");
	free_ast(ast);
	exit(127);
}

static void	exec_cmd_child(t_ast *ast, char ***env)
{
	char	*cmd;

	cmd = verif_command(ast->args[0], *env);
	if (!cmd)
		handle_cmd_not_found(ast);
	execve(cmd, ast->args, *env);
	if (errno == EISDIR)
		print_exec_error(ast->args[0], "Is a directory\n");
	else if (errno == EACCES)
		print_exec_error(ast->args[0], "Permission denied\n");
	else
		print_exec_error(ast->args[0], "command not found\n");
	free(cmd);
	free_ast(ast);
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	exit(127);
}

void	exec_cmd(t_ast *ast, char ***env)
{
	pid_t	pid;
	int		status;

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
		exec_cmd_child(ast, env);
	signal(SIGINT, handle_ctrlc_inprocess);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_ctrlc);
	g_exit_status = status_to_exit_code(status);
}
