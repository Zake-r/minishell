/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:18 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 13:55:19 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	exec_pipe_left(t_ast *ast, char ***env, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	exec_ast(ast->left, env);
	free_ast(ast);
	exit(g_exit_status);
}

static void	exec_pipe_right(t_ast *ast, char ***env, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	exec_ast(ast->right, env);
	free_ast(ast);
	exit(g_exit_status);
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
		exec_pipe_left(ast, env, fd);
	pid_r = fork();
	if (pid_r == -1)
	{
		perror("erreur fork");
		g_exit_status = 1;
		free_ast(ast);
		return ;
	}
	if (pid_r == 0)
		exec_pipe_right(ast, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_l, NULL, 0);
	waitpid(pid_r, &status_r, 0);
	g_exit_status = status_to_exit_code(status_r);
}