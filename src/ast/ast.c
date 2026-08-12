/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:16:18 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/13 13:16:18 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_ast	*create_redirection(t_ast *cmd, t_token **tokens)
{
	t_ast	*redir;
	t_ast	*file;
	t_token	*skip;

	redir = new_ast_node((*tokens)->type, 0);
	if (!redir)
		return (NULL);
	skip = *tokens;
	*tokens = (*tokens)->next;
	if (skip->value)
		free(skip->value);
	free(skip);
	if (!*tokens || (*tokens)->type != WORD)
		return (NULL);
	file = create_ast_filename(tokens);
	if (!file)
		return (NULL);
	redir->left = cmd;
	redir->right = file;
	return (redir);
}

static int	count_cmd_words(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == WORD)
		{
			count++;
			tokens = tokens->next;
		}
		else if (is_redirection(tokens->type))
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
		}
		else
			break ;
	}
	return (count);
}

static t_ast	*parse_cmd(t_ast *cmd, t_ast **result, t_token **tokens)
{
	int		i;
	t_token	*tmp;

	i = 0;
	while (*tokens && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
		{
			tmp = *tokens;
			cmd->args[i++] = tmp->value;
			*tokens = (*tokens)->next;
			free(tmp);
		}
		else if (is_redirection((*tokens)->type))
		{
			*result = create_redirection(*result, tokens);
			if (!*result)
				return (NULL);
		}
		else
			break ;
	}
	cmd->args[i] = NULL;
	return (*result);
}

t_ast	*create_command(t_token **tokens)
{
	t_ast	*cmd;
	t_ast	*result;

	cmd = new_ast_node(WORD, count_cmd_words(*tokens));
	if (!cmd)
		return (NULL);
	result = cmd;
	return (parse_cmd(cmd, &result, tokens));
}

t_ast	*create_ast(t_token **tokens)
{
	t_ast	*left;
	t_ast	*right;
	t_ast	*pipe;
	t_token	*skip;

	if (!*tokens)
		return (NULL);
	left = create_command(tokens);
	if (*tokens && (*tokens)->type == PIPE)
	{
		skip = *tokens;
		*tokens = (*tokens)->next;
		if (skip->value)
			free(skip->value);
		free(skip);
		right = create_ast(tokens);
		pipe = new_ast_node(PIPE, 0);
		if (!pipe)
			return (NULL);
		pipe->left = left;
		pipe->right = right;
		return (pipe);
	}
	return (left);
}
