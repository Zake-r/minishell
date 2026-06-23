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

/* ── parsing ──
   Remplit un tableau de t_token, un par commande.
   "ls -la | grep foo"
     -> tokens[0].tab = {"ls", "-la", NULL}
        tokens[1].tab = {"grep", "foo", NULL}
*/
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

/* ── exécution ──
   N commandes -> N-1 pipes
   Chaque enfant branche son stdin/stdout via dup2 puis execve.
*/
void execute(t_token *tokens, int nb_cmd, char **env)
{
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

    char    *line = readline("> ");
    if (!line)
        return (0);

    int     nb_cmd = count_pipe(line) + 1;
    t_token *tokens = parse_line(line, nb_cmd);

    execute(tokens, nb_cmd, env);

    free_tokens(tokens, nb_cmd);
    free(line);
    return (0);
}