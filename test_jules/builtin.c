#include "../minishell.h"

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

void    builtin_cd(t_token *token)
{
    if (token->tab[1] == NULL)
        chdir(getenv("HOME"));
    else
        chdir(token->tab[1]);
}

void    builtin_pwd(void)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

void    builtin_echo(t_token *token)
{
    int i = 1;
    int newline = 1;

    if (token->tab[1] && strcmp(token->tab[1], "-n") == 0)
    {
        newline = 0;
        i = 2;
    }
    while (token->tab[i])
    {
        printf("%s", token->tab[i]);
        if (token->tab[i + 1])
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
}

void    builtin_export(t_token *token, char **env)
{
    (void)env;
    int i = 1;
    while (token->tab[i])
    {
        putenv(token->tab[i]);
        i++;
    }
}

void    builtin_unset(t_token *token)
{
    int i = 1;
    while (token->tab[i])
    {
        unsetenv(token->tab[i]);
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

void    exec_builtin(t_token *token, char **env)
{
    if (strcmp(token->tab[0], "cd") == 0)
        builtin_cd(token);
    else if (strcmp(token->tab[0], "pwd") == 0)
        builtin_pwd();
    else if (strcmp(token->tab[0], "echo") == 0)
        builtin_echo(token);
    else if (strcmp(token->tab[0], "export") == 0)
        builtin_export(token, env);
    else if (strcmp(token->tab[0], "unset") == 0)
        builtin_unset(token);
    else if (strcmp(token->tab[0], "env") == 0)
        builtin_env(env);
    else if (strcmp(token->tab[0], "exit") == 0)
        exit(0);
}