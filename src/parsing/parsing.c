#include "minishell.h"

// main
// │
// ├── readline()
// │    retour la ligne
// │
// ├── lexer()
// │    trasforme la ligne en tokens
// │
// ├── syntax_check()
// │    verifie les erreurs
// │
// ├── parser()
// │    construit les commandes
// │
// ├──expand()
// │    remplace $HOME etc.
// │
// ├── execute()
// │    lance les commandes
// │
// └── free()
//      libere le tout

typedef enum e_type
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    APPEND,
    HEREDOC
}   t_type;

typedef struct s_token
{
    t_type          type;
    char            *value;
    struct s_token  *next;
}   t_token;

t_token lexer(char *line)
{
    t_token *tokens;

    tokens = NULL;
    while (*line)
    {
        while (*line || *line == ' ' || *line == '\t')
            line++;
        if (!*line)
            break;

        if ()
    }
    return (tokens) 
}

int    parsing()
{
    char    *line;

    line = readline("> ");
    if (!line)
        return (1);

    tokens = lexer(line);
}






/* ── helpers ── */

int count_pipe(char *s)
{
    int count
    
    count = 0;
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
    int count
    
    count = 0;
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

/* ── parsing ── */

t_token *parse_line(char *line, int nb_cmd)
{
    t_token *tokens;
    char    *cursor;
    int     i;

    tokens = (t_token *)malloc(sizeof(t_token) * nb_cmd);
    cursor = line;
    i = 0;
    while (i < nb_cmd)
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
        i++
    }
    return (tokens);
}

/* ── main ── */

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    int nb_cmd;

    while (1)
    {
        if (parsing())
            return (1);

        execute(tokens, nb_cmd, env);

        free_tokens(tokens, nb_cmd);
        free(line);
    }
    return (0);
}