/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:45:22 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 11:45:22 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*new_token(t_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	if (value)
		token->value = ft_strdup(value);
	else
		token->value = NULL;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '|' || c == '<' || c == '>');
}

char	*extract_word(char **line)
{
	char	*start;
	char	quote;

	start = *line;
	quote = 0;
	while (**line)
	{
		if (quote == 0 && is_quote(**line))
		{
			quote = **line;
			(*line)++;
		}
		else if (quote != 0 && **line == quote)
		{
			quote = 0;
			(*line)++;
		}
		else if (quote == 0 && is_separator(**line))
			break ;
		else
			(*line)++;
	}
	return (ft_substr(start, 0, *line - start));
}
