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

static int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*get_var_name(char *str, int i, int *len)
{
	int	j;

	j = i;
	while (str[j] && is_var_char(str[j]))
		j++;
	*len = j - i;
	return (ft_substr(str, i, *len));
}

static int	calc_new_len(char *str, char **env)
{
	int		i;
	int		len;
	int		var_len;
	char	*name;
	char	*value;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			name = get_var_name(str, i + 1, &var_len);
			value = env_get(env, name);
			if (value)
				len += ft_strlen(value);
			free(name);
			i += var_len + 1;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*check_env(char *str, char **env)
{
	char	*result;
	int		i;
	int		j;
	int		var_len;
	char	*name;
	char	*value;

	if (!ft_strchr(str, '$'))
		return (ft_strdup(str));
	result = malloc(sizeof(char) * (calc_new_len(str, env) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			name = get_var_name(str, i + 1, &var_len);
			value = env_get(env, name);
			if (value)
			{
				ft_strlcpy(result + j, value, ft_strlen(value) + 1);
				j += ft_strlen(value);
			}
			free(name);
			i += var_len + 1;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

void	replace_var_env(t_token *tokens, char **env)
{
	char	*new_value;

	while (tokens)
	{
		if (tokens->value && ft_strchr(tokens->value, '$'))
		{
			new_value = check_env(tokens->value, env);
			if (new_value)
			{
				free(tokens->value);
				tokens->value = new_value;
			}
		}
		tokens = tokens->next;
	}
}

t_token	*parsing(char **parsed_env)
{
	(void)parsed_env;
	char	*line;
	t_token	*tokens;

	line = readline("> ");
    add_history(line);
    rl_on_new_line();
	// if (!line)
	// 	return (1);
	tokens = lexer(line);
	if (!tokens)
		return (NULL);
	if (syntax_check(tokens))
		return (free_all(tokens, line), NULL);
	replace_var_env(tokens, parsed_env);
	free(line);
	return (tokens);
}
