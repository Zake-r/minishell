/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:54:57 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 13:54:58 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void	exec_ast(t_ast *ast, char ***env)
{
	if (!ast)
		return ;
	else if (ast->type == WORD)
		exec_cmd(ast, env);
	else if (ast->type == PIPE)
		exec_pipe(ast, env);
	else if (ast->type == REDIR_OUT || ast->type == REDIR_IN
		|| ast->type == APPEND)
		exec_redirection(ast, env);
	else if (ast->type == HEREDOC)
		exec_heredoc(ast, env);
}