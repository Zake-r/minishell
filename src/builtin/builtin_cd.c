/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:19:22 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 14:22:12 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtin(char *cmd)
{
	char	*builtins[] = {"cd", "exit", "export", "unset", "pwd", "echo",
			"env", NULL};
	int		i;

	i = 0;
	while (builtins[i])
	{
		if (strcmp(cmd, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	update_pwd(char ***env, char *old_pwd)
{
	char	cwd[4096];

	if (old_pwd)
		*env = env_set(*env, "OLDPWD", old_pwd);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		*env = env_set(*env, "PWD", cwd);
	else
		perror("cd: getcwd");
}

int	builtin_cd(t_ast *ast, char ***env)
{
	char	*target;
	char	*old_pwd;

	if (ast->args[2])
	{
		write(2, "bash: cd: too many arguments\n", 30);
		return (2);
	}
	old_pwd = getcwd(NULL, 0);
	if (ast->args[1] == NULL)
	{
		target = env_get(*env, "HOME");
		if (target == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			free(old_pwd);
			return (2);
		}
	}
	else
		target = ast->args[1];
	if (chdir(target) != 0)
	{
		perror("cd");
		free(old_pwd);
		return (1);
	}
	update_pwd(env, old_pwd);
	free(old_pwd);
	return (0);
}

void	exec_builtin(t_ast *ast, char ***env)
{
	if (strcmp(ast->args[0], "cd") == 0)
		g_exit_status = builtin_cd(ast, env);
	else if (strcmp(ast->args[0], "pwd") == 0)
		g_exit_status = builtin_pwd();
	else if (strcmp(ast->args[0], "echo") == 0)
		g_exit_status = builtin_echo(ast);
	else if (strcmp(ast->args[0], "export") == 0)
		g_exit_status = builtin_export(ast, env);
	else if (strcmp(ast->args[0], "unset") == 0)
		g_exit_status = builtin_unset(ast, env);
	else if (strcmp(ast->args[0], "env") == 0)
		g_exit_status = builtin_env(*env);
	else if (strcmp(ast->args[0], "exit") == 0)
		builtin_exit(ast);
}
