#include "../../inc/minishell.h"

char **find_path(char **env)
{
	char *path;
	char **path_splited;
	int i;

	path = NULL;
	i = 0;
	
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break;
		}
		i++;
	}
	path_splited = ft_split(path, ':');
	path_splited[0] = path_splited[0] + 5;
	



	return path_splited;
}

char *test_cmd(char *cmd, char **path)
{
	int i = 0;
	char *final_cmd;
	char *cmd_with_dash;

	cmd_with_dash = ft_strjoin("/", cmd);
	while (path[i])
	{
		final_cmd = ft_strjoin(path[i], cmd_with_dash);
		if (access(final_cmd, F_OK) == 0)
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

char *verif_command(char *cmd, char **env)
{
	char **path = find_path(env);
	char *final_cmd;
	(void)cmd;
	final_cmd = test_cmd(cmd, path);
	return final_cmd;




}


