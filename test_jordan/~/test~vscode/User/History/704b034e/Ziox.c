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

#include "../../../inc/minishell.h"

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

char	*extract_word(char **line)
{
	char	*start;
	char	*word;
	int		len;

	start = *line;
	while (**line && **line != ' ' && **line != '\t' && **line != '|'
		&& **line != '<' && **line != '>')
		(*line)++;
	len = *line - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}
