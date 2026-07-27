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

void    builtin_cd(t_ast *ast, char **env)
{
    if (ast->args[1] == NULL)
    {
        chdir(getenv("HOME"));
    }
    else
    {
        chdir(ast->args[1]);
    }
}

void    builtin_pwd(void)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
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

void    builtin_export(t_ast *ast, char **env)
{
    env_set(ast->args[i]);
}

void    builtin_unset(t_ast *ast, char *env)
{
    int i = 1;
    while (ast->args[i])
    {
        env_unset(env, ast->args[i]);
        i++;
    }
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

void    exec_builtin(t_ast *ast, char **env)
{
    if (strcmp(ast->args[0], "cd") == 0)
        builtin_cd(ast, env);
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