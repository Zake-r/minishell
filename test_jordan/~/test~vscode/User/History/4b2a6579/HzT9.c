#include "../../inc/minishell.h"

char **dup_env(char **env)
{
	int	count;
	char	**copy;
	int	i;

	count = 0;
	while (env[count])
		count++;

	copy = malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);

	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(env[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[count] = NULL; 
	return (copy);
}

void free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}


char *env_get(char **env, char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int env_find_index(char **env, char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}


char *build_entry(char *name, char *value)
{
	char	*tmp;
	char	*entry;

	tmp = ft_strjoin(name, "=");
	if (!tmp)
		return (NULL);
	entry = ft_strjoin(tmp, value);
	free(tmp);
	return (entry);
}

char **env_set(char **env, char *name, char *value)
{
	int	idx;
	int	count;
	char	*new_entry;
	char	**new_env;

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
	free(env); // seulement le tableau, pas les strings (elles sont réutilisées)
	return (new_env);
}