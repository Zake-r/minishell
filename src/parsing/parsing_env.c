/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:48:04 by jbusquet          #+#    #+#             */
/*   Updated: 2026/08/11 23:48:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	copy_status(char *result, int j)
{
	char	*status;

	status = ft_itoa(g_exit_status);
	if (!status)
		return (j);
	ft_strlcpy(result + j, status, ft_strlen(status) + 1);
	j += ft_strlen(status);
	free(status);
	return (j);
}

static int	copy_var(t_copy_ctx *ctx, int i, int *j, char **env)
{
	int		var_len;
	char	*name;
	char	*value;

	name = get_var_name(ctx->str, i + 1, &var_len);
	value = env_get(env, name);
	if (value)
	{
		ft_strlcpy(ctx->result + *j, value, ft_strlen(value) + 1);
		*j += ft_strlen(value);
	}
	free(name);
	return (var_len + 1);
}

static char	*init_result(char *str, char **env)
{
	char	*result;

	if (!ft_strchr(str, '$'))
		return (ft_strdup(str));
	result = malloc(calc_new_len(str, env) + 1);
	return (result);
}

char	*check_env(char *str, char **env)
{
	t_copy_ctx	ctx;
	int			i;
	int			j;

	ctx.str = str;
	ctx.result = init_result(str, env);
	if (!ctx.result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			j = copy_status(ctx.result, j);
			i += 2;
		}
		else if (str[i] == '$'
			&& (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
			i += copy_var(&ctx, i, &j, env);
		else
			ctx.result[j++] = str[i++];
	}
	ctx.result[j] = '\0';
	return (ctx.result);
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
