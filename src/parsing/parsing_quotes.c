/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:18:59 by jbusquet          #+#    #+#             */
/*   Updated: 2026/08/12 00:18:59 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	handle_quote_or_var(t_unit_ctx *ctx, int i, t_unit_out *out)
{
	int		var_len;
	char	*name;
	char	*val;

	if (*ctx->quote == 0 && is_quote(ctx->str[i]))
	{
		*ctx->quote = ctx->str[i];
		return (1);
	}
	if (*ctx->quote != 0 && ctx->str[i] == *ctx->quote)
	{
		*ctx->quote = 0;
		return (1);
	}
	if (ctx->str[i] == '$' && *ctx->quote != '\''
		&& (ft_isalpha(ctx->str[i + 1]) || ctx->str[i + 1] == '_'))
	{
		name = get_var_name(ctx->str, i + 1, &var_len);
		val = env_get(ctx->env, name);
		if (val)
			out->value = ft_strdup(val);
		free(name);
		return (var_len + 1);
	}
	return (0);
}

int	next_unit(t_unit_ctx *ctx, int i, t_unit_out *out)
{
	int	ret;

	out->value = NULL;
	out->is_literal = 0;
	if (ctx->str[i] == '$' && *ctx->quote != '\'' && ctx->str[i + 1] == '?')
	{
		out->value = ft_itoa(g_exit_status);
		return (2);
	}
	ret = handle_quote_or_var(ctx, i, out);
	if (ret)
		return (ret);
	out->is_literal = 1;
	out->literal = ctx->str[i];
	return (1);
}

int	calc_expanded_len(char *str, char **env)
{
	t_unit_ctx	ctx;
	t_unit_out	out;
	int			i;
	int			len;
	char		quote;

	ctx.str = str;
	ctx.quote = &quote;
	ctx.env = env;
	i = 0;
	len = 0;
	quote = 0;
	while (str[i])
	{
		i += next_unit(&ctx, i, &out);
		if (out.value)
		{
			len += ft_strlen(out.value);
			free(out.value);
		}
		else if (out.is_literal)
			len++;
	}
	return (len);
}

static void	fill_expanded(char *result, char *str, char **env)
{
	t_unit_ctx	ctx;
	t_unit_out	out;
	int			i;
	int			j;
	char		quote;

	ctx.str = str;
	ctx.quote = &quote;
	ctx.env = env;
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		i += next_unit(&ctx, i, &out);
		if (out.value)
		{
			ft_strlcpy(result + j, out.value, ft_strlen(out.value) + 1);
			j += ft_strlen(out.value);
			free(out.value);
		}
		else if (out.is_literal)
			result[j++] = out.literal;
	}
	result[j] = '\0';
}

char	*expand_and_unquote(char *str, char **env)
{
	char	*result;

	result = malloc(sizeof(char) * (calc_expanded_len(str, env) + 1));
	if (!result)
		return (NULL);
	fill_expanded(result, str, env);
	return (result);
}
