/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:44:40 by jbusquet          #+#    #+#             */
/*   Updated: 2026/08/11 23:44:40 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*get_var_name(char *str, int i, int *len)
{
	int	j;

	j = i;
	while (str[j] && is_var_char(str[j]))
		j++;
	*len = j - i;
	return (ft_substr(str, i, *len));
}

int	var_expanded_len(char *str, int *i, char **env)
{
	int		var_len;
	int		len;
	char	*name;
	char	*value;

	name = get_var_name(str, *i + 1, &var_len);
	value = env_get(env, name);
	len = 0;
	if (value)
		len = ft_strlen(value);
	free(name);
	*i += var_len + 1;
	return (len);
}

int	calc_new_len(char *str, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
			len += var_expanded_len(str, &i, env);
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}
