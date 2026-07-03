/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:32:13 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 12:32:13 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_redirection(t_type type)
{
	return (type == REDIR_IN
		|| type == REDIR_OUT
		|| type == APPEND
		|| type == HEREDOC);
}

static int	check_first(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == PIPE)
		return (printf("syntax error\n"), 1);
	return (0);
}

static int	check_last(t_token *token)
{
	while (token->next)
		token = token->next;
	if (token->type == PIPE)
		return (printf("syntax error\n"), 1);
	if (is_redirection(token->type))
		return (printf("syntax error\n"), 1);
	return (0);
}

static int	check_tokens(t_token *token)
{
	while (token && token->next)
	{
		if (token->type == PIPE && token->next->type == PIPE)
			return (printf("syntax error\n"), 1);
		if (is_redirection(token->type) && is_redirection(token->next->type))
			return (printf("syntax error\n"), 1);
		if (token->type == PIPE && is_redirection(token->next->type))
			return (printf("syntax error\n"), 1);
		if (is_redirection(token->type) && token->next->type == PIPE)
			return (printf("syntax error\n"), 1);
		token = token->next;
	}
	return (0);
}

int	syntax_check(t_token *tokens)
{
	if (check_first(tokens))
		return (1);
	if (check_last(tokens))
		return (1);
	if (check_tokens(tokens))
		return (1);
	return (0);
}
