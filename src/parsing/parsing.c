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

static int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

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

static int	next_unit(char *str, int i, char *quote, char **env,
		char **value_out, int *is_literal, char *literal_out)
{
	int		var_len;
	char	*name;
	char	*val;

	*value_out = NULL;
	*is_literal = 0;
	if (*quote == 0 && is_quote(str[i]))
	{
		*quote = str[i];
		return (1);
	}
	if (*quote != 0 && str[i] == *quote)
	{
		*quote = 0;
		return (1);
	}
	if (str[i] == '$' && *quote != '\'' && str[i + 1] == '?')
	{
		*value_out = ft_itoa(g_exit_status);
		return (2);
	}
	if (str[i] == '$' && *quote != '\''
		&& (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
	{
		name = get_var_name(str, i + 1, &var_len);
		val = env_get(env, name);
		if (val)
			*value_out = ft_strdup(val);
		free(name);
		return (var_len + 1);
	}
	*is_literal = 1;
	*literal_out = str[i];
	return (1);
}

static int	calc_expanded_len(char *str, char **env)
{
	int		i;
	int		len;
	char	quote;
	char	*value;
	int		is_literal;
	char	lit;

	i = 0;
	len = 0;
	quote = 0;
	while (str[i])
	{
		i += next_unit(str, i, &quote, env, &value, &is_literal, &lit);
		if (value)
		{
			len += ft_strlen(value);
			free(value);
		}
		else if (is_literal)
			len++;
	}
	return (len);
}

char	*expand_and_unquote(char *str, char **env)
{
	char	*result;
	int		i;
	int		j;
	char	quote;
	char	*value;
	int		is_literal;
	char	lit;

	result = malloc(sizeof(char) * (calc_expanded_len(str, env) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		i += next_unit(str, i, &quote, env, &value, &is_literal, &lit);
		if (value)
		{
			ft_strlcpy(result + j, value, ft_strlen(value) + 1);
			j += ft_strlen(value);
			free(value);
		}
		else if (is_literal)
			result[j++] = lit;
	}
	result[j] = '\0';
	return (result);
}

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
			t_token *to_free = tmp;
			tmp = tmp->next;
			if (prev)
				prev->next = tmp;
			else
				*tokens = tmp;
			free_token(to_free);
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
	(void)parsed_env;
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
