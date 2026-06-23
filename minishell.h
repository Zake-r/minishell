#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/readline.h>

typedef struct s_token
{
    char    **tab;
    int     infile;
    int     outfile;
} t_token;

int     count_pipe(char *s);
int     count_word_to_pipe(char *s);
t_token *parse_line(char *line, int nb_cmd);
void    execute(t_token *tokens, int nb_cmd, char **env);
void    free_tokens(t_token *tokens, int nb_cmd);
int     is_builtin(char *cmd);
void    exec_builtin(t_token *token, char **env);

#endif