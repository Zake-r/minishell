#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ── structures ── */

typedef struct s_token
{
	char	**tab;
	int		infile;
	int		outfile;
}	t_token;

/* ── helpers ── */

int		count_pipe(char *s);
int		count_word_to_pipe(char *s);

/* ── builtins ── */

int		is_builtin(char *cmd);
void	builtin_cd(t_token *token);
void	builtin_pwd(void);
void	builtin_echo(t_token *token);
void	builtin_export(t_token *token, char **env);
void	builtin_unset(t_token *token);
void	builtin_env(char **env);
void	exec_builtin(t_token *token, char **env);

/* ── parsing ── */

t_token	*parse_line(char *line, int nb_cmd);

/* ── exécution ── */

void	execute(t_token *tokens, int nb_cmd, char **env);

/* ── libération ── */

void	free_tokens(t_token *tokens, int nb_cmd);

#endif