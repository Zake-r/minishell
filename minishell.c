#include "minishell.h"

/* ── helpers ── */

int count_pipe(char *s)
{
    int count = 0;
    while (*s)
    {
        if (*s == '|')
            count++;
        s++;
    }
    return (count);
}

int count_word_to_pipe(char *s)
{
    int count = 0;
    while (*s && *s != '|')
    {
        while (*s == ' ')
            s++;
        if (*s && *s != '|')
            count++;
        while (*s != ' ' && *s != '\0' && *s != '|')
            s++;
    }
    return (count);
}

/* ── builtins ── */

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

/* ── parsing ── */

t_token *parse_line(char *line, int nb_cmd)
{
    t_token *tokens = (t_token *)malloc(sizeof(t_token) * nb_cmd);
    char    *cursor = line;

    for (int i = 0; i < nb_cmd; i++)
    {
        int nw = count_word_to_pipe(cursor);
        tokens[i].tab = (char **)malloc(sizeof(char *) * (nw + 1));
        tokens[i].tab[nw] = NULL;
        tokens[i].infile = -1;
        tokens[i].outfile = -1;

        int j = 0;
        while (*cursor && *cursor != '|')
        {
            while (*cursor == ' ')
                cursor++;
            if (*cursor == '\0' || *cursor == '|')
                break ;
            char *start = cursor;
            while (*cursor != ' ' && *cursor != '\0' && *cursor != '|')
                cursor++;
            int len = cursor - start;
            tokens[i].tab[j] = (char *)malloc(len + 1);
            strncpy(tokens[i].tab[j], start, len);
            tokens[i].tab[j][len] = '\0';
            j++;
        }
        if (*cursor == '|')
            cursor++;
    }
    return (tokens);
}

/* ── exécution ── */

void execute(t_token *tokens, int nb_cmd, char **env)
{
    /* cas simple : une seule commande builtin, on l'exécute dans le parent */
    if (nb_cmd == 1 && is_builtin(tokens[0].tab[0]))
    {
        exec_builtin(&tokens[0], env);
        return ;
    }

    int (*pipes)[2] = (int (*)[2])malloc(sizeof(int[2]) * (nb_cmd - 1));
    for (int i = 0; i < nb_cmd - 1; i++)
        pipe(pipes[i]);

    for (int i = 0; i < nb_cmd; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            if (i > 0)
                dup2(pipes[i - 1][0], STDIN_FILENO);
            if (i < nb_cmd - 1)
                dup2(pipes[i][1], STDOUT_FILENO);

            for (int k = 0; k < nb_cmd - 1; k++)
            {
                close(pipes[k][0]);
                close(pipes[k][1]);
            }

            /* builtin dans un pipe : on l'exécute dans l'enfant */
            if (is_builtin(tokens[i].tab[0]))
            {
                exec_builtin(&tokens[i], env);
                exit(0);
            }
            execve(tokens[i].tab[0], tokens[i].tab, env);
            perror(tokens[i].tab[0]);
            exit(1);
        }
    }

    for (int k = 0; k < nb_cmd - 1; k++)
    {
        close(pipes[k][0]);
        close(pipes[k][1]);
    }
    for (int i = 0; i < nb_cmd; i++)
        wait(NULL);

    free(pipes);
}

/* ── libération ── */

void free_tokens(t_token *tokens, int nb_cmd)
{
    for (int i = 0; i < nb_cmd; i++)
    {
        for (int j = 0; tokens[i].tab[j]; j++)
            free(tokens[i].tab[j]);
        free(tokens[i].tab);
    }
    free(tokens);
}

/* ── main ── */



int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;

    while (1)
    {
        char    *line = readline("> ");
        if (!line)
            return (0);
        add_history(line);
        rl_on_new_line();
        int     nb_cmd = count_pipe(line) + 1;
        t_token *tokens = parse_line(line, nb_cmd);
        int i = 0;
        execute(tokens, nb_cmd, env);

        free_tokens(tokens, nb_cmd);
        free(line);
    }
    return (0);
}