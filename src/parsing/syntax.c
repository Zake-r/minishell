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

int	is_redirection(t_type type)
{
	return (type == REDIR_IN
		|| type == REDIR_OUT
		|| type == APPEND
		|| type == HEREDOC);
}

static int	syntax_error_token(char *token)
{
	if (!token)
	{
		g_exit_status = 2;
		write(2, "bash: syntax error near unexpected token `newline'\n", 51);
		return (1);
	}
	g_exit_status = 2;
	write(2, "bash: syntax error near unexpected token `", 42);
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
	return (1);
}

static int	check_first(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == PIPE)
	{
		syntax_error_token(token->value);
		return (1);
	}
	return (0);
}

static int	check_tokens(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE && token->next
			&& token->next->type == PIPE)
			return (syntax_error_token(token->next->value), 1);
		if (is_redirection(token->type))
		{
			if (!token->next)
				return (syntax_error_token(NULL), 1);
			if (token->next->type == PIPE
				|| is_redirection(token->next->type))
				return (syntax_error_token(token->next->value), 1);
		}
		token = token->next;
	}
	return (0);
}

int	syntax_check(t_token *tokens)
{
	if (check_first(tokens))
		return (1);
	if (check_tokens(tokens))
		return (1);
	return (0);
}
