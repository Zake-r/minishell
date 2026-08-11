/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:11 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 13:55:12 by jbossuyt         ###   ########.fr       */
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

static void	exec_cmd_child(t_ast *ast, char ***env)
{
	char	*cmd;

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
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}