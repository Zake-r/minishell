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
