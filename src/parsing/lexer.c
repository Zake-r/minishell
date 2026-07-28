/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:38:27 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 11:38:27 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	handle_redirect_in(char **line, t_token **tokens)
{
	if (*(*line + 1) == '<')
	{
		add_token(tokens, new_token(HEREDOC, "<<"));
		*line += 2;
	}
	else
	{
		add_token(tokens, new_token(REDIR_IN, "<"));
		(*line)++;
	}
}

static void	handle_redirect_out(char **line, t_token **tokens)
{
	if (*(*line + 1) == '>')
	{
		add_token(tokens, new_token(APPEND, ">>"));
		*line += 2;
	}
	else
	{
		add_token(tokens, new_token(REDIR_OUT, ">"));
		(*line)++;
	}
}

static int	handle_operator(char **line, t_token **tokens)
{
	if (**line == '|')
	{
		add_token(tokens, new_token(PIPE, "|"));
		(*line)++;
	}
	else if (**line == '<')
		handle_redirect_in(line, tokens);
	else if (**line == '>')
		handle_redirect_out(line, tokens);
	else
		return (0);
	return (1);
}

t_token	*lexer(char *line)
{
	t_token	*tokens;
	char	*word;

	tokens = NULL;
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (!*line)
			break ;
		if (!handle_operator(&line, &tokens))
		{
			word = extract_word(&line);
			add_token(&tokens, new_token(WORD, word));
			free(word);
		}
	}
	return (tokens);
}
