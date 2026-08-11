/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:21 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 13:55:22 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	exec_redirection_child(t_ast *ast, char ***env)
{
	t_ast	*cmd_node;

	cmd_node = apply_redirections(ast);
	if (!cmd_node)
	{
		free_ast(ast);
		exit(1);
	}
	exec_ast(cmd_node, env);
	free_ast(ast);
	exit(g_exit_status);
}

void	exec_redirection(t_ast *ast, char ***env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		return ;
	}
	if (pid == 0)
		exec_redirection_child(ast, env);
	waitpid(pid, &status, 0);
	g_exit_status = status_to_exit_code(status);
}