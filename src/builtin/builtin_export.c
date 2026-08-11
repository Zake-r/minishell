/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:19:30 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 22:58:24 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	export_one(char ***env, char *arg)
{
	char	*name;
	char	*equal;
	char	*value;

	if (!is_valid_identifier(arg))
	{
		write(2, "export: `", 9);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier\n", 26);
		return (1);
	}
	equal = ft_strchr(arg, '=');
	if (equal == NULL)
	{
		if (env_get(*env, arg) == NULL)
			*env = env_set(*env, arg, "");
		return (0);
	}
	name = ft_substr(arg, 0, equal - arg);
	value = ft_strdup(equal + 1);
	*env = env_set(*env, name, value);
	free(name);
	free(value);
	return (0);
}

int	builtin_export(t_ast *ast, char ***env)
{
	int	i;
	int	status;
	int	ret;

	if (ast->args[1] == NULL)
		return (builtin_env(*env));
	i = 1;
	status = 0;
	while (ast->args[i])
	{
		ret = export_one(env, ast->args[i]);
		if (ret != 0)
			status = ret;
		i++;
	}
	return (status);
}

int	builtin_unset(t_ast *ast, char ***env)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (ast->args[i])
	{
		if (!is_valid_identifier(ast->args[i]))
		{
			write(2, "unset: `", 8);
			write(2, ast->args[i], ft_strlen(ast->args[i]));
			write(2, "': not a valid identifier\n", 26);
			status = 1;
		}
		else
			*env = env_unset(*env, ast->args[i]);
		i++;
	}
	return (status);
}
