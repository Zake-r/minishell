/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:55:27 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 22:30:14 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**find_path(char **env)
{
	char	*path;
	char	**path_splited;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	path_splited = ft_split(path + 5, ':');
	return (path_splited);
}

char	*test_cmd(char *cmd, char **path)
{
	int		i;
	char	*final_cmd;
	char	*cmd_with_dash;

	i = 0;
	cmd_with_dash = ft_strjoin("/", cmd);
	while (path[i])
	{
		final_cmd = ft_strjoin(path[i], cmd_with_dash);
		if (access(final_cmd, X_OK) == 0)
		{
			free(cmd_with_dash);
			return (final_cmd);
		}
		free(final_cmd);
		i++;
	}
	free(cmd_with_dash);
	return (NULL);
}

char	*verif_command(char *cmd, char **env)
{
	char	**path;
	char	*final_cmd;

	if (is_path(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = find_path(env);
	if (!path)
		return (NULL);
	final_cmd = test_cmd(cmd, path);
	free_split(path);
	return (final_cmd);
}
