/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:51:26 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 13:07:27 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_fully_quoted(char *str)
{
	int	len;

	if (!str || !*str)
		return (0);
	if (str[0] != '"' && str[0] != '\'')
		return (0);
	len = ft_strlen(str);
	if (len < 2 || str[len - 1] != str[0])
		return (0);
	return (1);
}

static void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

static t_token	*unlink_token(t_token **tokens, t_token *prev, t_token *tmp)
{
	t_token	*next;

	next = tmp->next;
	if (prev)
		prev->next = next;
	else
		*tokens = next;
	free_token(tmp);
	return (next);
}

void	remove_quote_if_needed(t_token **tokens, char **env)
{
	t_token	*tmp;
	t_token	*prev;
	char	*orig;
	char	*new_value;

	prev = NULL;
	tmp = *tokens;
	while (tmp)
	{
		orig = tmp->value;
		new_value = expand_and_unquote(orig, env);
		if (!new_value)
			return ;
		if (new_value[0] == '\0' && !is_fully_quoted(orig))
		{
			free(new_value);
			tmp = unlink_token(tokens, prev, tmp);
			continue ;
		}
		free(tmp->value);
		tmp->value = new_value;
		prev = tmp;
		tmp = tmp->next;
	}
}

t_token	*parsing(char *line, char **parsed_env)
{
	t_token	*tokens;

	tokens = lexer(line);
	if (!tokens)
		return (NULL);
	if (syntax_check(tokens))
		return (free_all(tokens, line), NULL);
	remove_quote_if_needed(&tokens, parsed_env);
	if (!tokens)
		return (free(line), NULL);
	free(line);
	return (tokens);
}
