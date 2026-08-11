/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:25 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 22:15:36 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	open_redir_fd(t_ast *ast)
{
	if (ast->type == REDIR_OUT)
		return (open(ast->right->args[0],
				O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (ast->type == APPEND)
		return (open(ast->right->args[0],
				O_WRONLY | O_CREAT | O_APPEND, 0644));
	else if (ast->type == REDIR_IN)
		return (open(ast->right->args[0], O_RDONLY));
	return (-2);
}

int	apply_one_redir(t_ast *ast)
{
	int	fd;

	fd = open_redir_fd(ast);
	if (fd == -2)
		return (1);
	if (fd == -1)
	{
		perror(ast->right->args[0]);
		return (0);
	}
	if (ast->type == REDIR_IN)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

t_ast	*apply_redirections(t_ast *ast)
{
	t_ast	*cmd;

	if (!ast)
		return (NULL);
	if (ast->type != REDIR_OUT && ast->type != REDIR_IN
		&& ast->type != APPEND)
		return (ast);
	cmd = apply_redirections(ast->left);
	if (!cmd)
		return (NULL);
	if (!apply_one_redir(ast))
		return (NULL);
	return (cmd);
}
