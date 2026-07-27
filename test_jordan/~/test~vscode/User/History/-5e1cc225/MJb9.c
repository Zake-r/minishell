#include "../../inc/minishell.h"

int is_builtin(char *cmd)
{
    char *builtins[] = {"cd", "exit", "export", "unset", "pwd", "echo", "env", NULL};
    int  i = 0;

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

void	builtin_cd(t_ast *ast, char ***env)
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
			return ;
		}
	}
	else
		target = ast->args[1];
	if (chdir(target) != 0)
	{
		perror("cd");
		free(old_pwd);
		return ;
	}
	update_pwd(env, old_pwd);
	free(old_pwd);
}

void    builtin_pwd(void)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

void    builtin_env(char **env)
{
    int i = 0;
    while (env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }
}


void    builtin_echo(t_ast *ast)
{
    int i = 1;
    int newline = 1;

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

void	export_one(char ***env, char *arg)
{
	char	*name;
	char	*equal;
	char	*value;

	if (!is_valid_identifier(arg))
	{
		fprintf(stderr, "export: `%s': not a valid identifier\n", arg);
		return ;
	}
	equal = ft_strchr(arg, '=');
	if (equal == NULL)
	{
		if (env_get(*env, arg) == NULL)
			*env = env_set(*env, arg, "");
		return ; 
	}
	name = ft_substr(arg, 0, equal - arg);
	value = ft_strdup(equal + 1);
	*env = env_set(*env, name, value);
	free(name);
	free(value);
}

void	builtin_export(t_ast *ast, char ***env)
{
	int	i;

	if (ast->args[1] == NULL)
	{
		builtin_env(*env); 
		return ;
	}
	i = 1;
	while (ast->args[i])
	{
		export_one(env, ast->args[i]);
		i++;
	}
}


void    builtin_unset(t_ast *ast, char ***env)
{
    int i = 1;
    while (ast->args[i])
    {
        *env = env_unset(*env, ast->args[i]);
        i++;
    }
}



void    exec_builtin(t_ast *ast, char **env)
{
    if (strcmp(ast->args[0], "cd") == 0)
        builtin_cd(ast, &env);
    else if (strcmp(ast->args[0], "pwd") == 0)
        builtin_pwd();
    else if (strcmp(ast->args[0], "echo") == 0)
        builtin_echo(ast);
    else if (strcmp(ast->args[0], "export") == 0)
        builtin_export(ast, env);
    else if (strcmp(ast->args[0], "unset") == 0)
        builtin_unset(ast, env);
    else if (strcmp(ast->args[0], "env") == 0)
        builtin_env(env);
    else if (strcmp(ast->args[0], "exit") == 0)
        exit(0);
}