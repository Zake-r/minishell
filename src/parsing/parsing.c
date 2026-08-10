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
	char 	*status_str;

	if (!ft_strchr(str, '$'))
		return (ft_strdup(str));
	result = malloc(sizeof(char) * (calc_new_len(str, env) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			status_str = ft_itoa(g_exit_status);
			ft_strlcpy(result + j, status_str, ft_strlen(status_str) + 1);
			j += ft_strlen(status_str);
			free(status_str);
			i += 2;
		}
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

void	replace_var_env(char **value, char **env, int is_trim)
{
	char	*new_value;

	if (*value && ft_strchr(*value, '$') && !is_trim)
	{
		new_value = check_env(*value, env);
		if (new_value)
		{
			free(*value);
			*value = new_value;
		}
	}
}

void remove_quote_if_needed(t_token *tokens, char **env)
{    
	char *tmp;
	int is_trim;

	is_trim = 0;
	while (tokens)
	{
		if ((tokens->value)[0] == '"' || (tokens->value)[0] == '\'')	
		{
			if ((tokens->value)[0] == '"')
				tmp = ft_strtrim(tokens->value, "\"");
			if ((tokens->value)[0] == '\'')
				tmp = ft_strtrim(tokens->value, "\'");
			if ((tokens->value)[0] == '\'')
				is_trim = 1;
			free(tokens->value);
			tokens->value = tmp;
			
		}
		replace_var_env(&tokens->value, env, is_trim);
		tokens = tokens->next;
		is_trim = 0;
	}
}

t_token	*parsing(char *line, char **parsed_env)
{
	(void)parsed_env;
	t_token	*tokens;

	tokens = lexer(line);
	if (!tokens)
		return (NULL);
	if (syntax_check(tokens))
		return (free_all(tokens, line), NULL);
	remove_quote_if_needed(tokens, parsed_env);
	free(line);
	return (tokens);
}
