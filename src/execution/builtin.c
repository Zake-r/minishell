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

	old_pwd = getcwd(NULL, 0);
	if (ast->args[1] == NULL)
	{
		target = env_get(*env, "HOME");
		if (target == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			free(old_pwd);
			return (1);
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

int	builtin_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}

int	builtin_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	builtin_echo(t_ast *ast)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (ast->args[1] && strcmp(ast->args[1], "-n") == 0)
	{
		newline = 0;
		i = 2;
	}
	while (ast->args[i])
	{
		printf("%s", ast->args[i]);
		if (ast->args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}

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
		fprintf(stderr, "export: `%s': not a valid identifier\n", arg);
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
			fprintf(stderr, "unset: `%s': not a valid identifier\n",
				ast->args[i]);
			status = 1;
		}
		else
			*env = env_unset(*env, ast->args[i]);
		i++;
	}
	return (status);
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(t_ast *ast)
{
	long	code;

	printf("exit\n");
	if (ast->args[1] && ast->args[2])
	{
		fprintf(stderr, "exit: too many arguments\n");
		g_exit_status = 1;
		return ;
	}
	if (ast->args[1])
	{
		if (!is_numeric(ast->args[1]))
		{
			fprintf(stderr, "exit: %s: numeric argument required\n",
				ast->args[1]);
			exit(2);
		}
		code = ft_atoi(ast->args[1]);
		exit((unsigned char)code);
	}
	exit(g_exit_status);
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