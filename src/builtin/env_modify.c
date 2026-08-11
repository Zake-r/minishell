/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:19:36 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 14:21:34 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**env_add_new(char **env, char *new_entry, int count)
{
	char	**new_env;
	int		idx;

	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
	{
		free(new_entry);
		return (env);
	}
	idx = 0;
	while (idx < count)
	{
		new_env[idx] = env[idx];
		idx++;
	}
	new_env[count] = new_entry;
	new_env[count + 1] = NULL;
	free(env);
	return (new_env);
}

char	**env_set(char **env, char *name, char *value)
{
	int		idx;
	int		count;
	char	*new_entry;

	new_entry = build_entry(name, value);
	if (!new_entry)
		return (env);
	idx = env_find_index(env, name);
	if (idx != -1)
	{
		free(env[idx]);
		env[idx] = new_entry;
		return (env);
	}
	count = 0;
	while (env[count])
		count++;
	return (env_add_new(env, new_entry, count));
}

char	**env_unset(char **env, char *name)
{
	int	idx;
	int	count;

	idx = env_find_index(env, name);
	if (idx == -1)
		return (env);
	free(env[idx]);
	count = 0;
	while (env[count])
		count++;
	idx++;
	while (idx < count)
	{
		env[idx - 1] = env[idx];
		idx++;
	}
	env[count - 1] = NULL;
	return (env);
}
