/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:34:02 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 11:34:02 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// libft:
# include "libft/header.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}	t_type;

typedef struct s_ast
{
	t_type type;
	char **args;
	struct s_ast *left;
	struct s_ast *right;
} t_ast;




void exec_cmd(t_ast *ast, char **env);
void exec_pipe(t_ast *ast, char **env);
void exec_ast(t_ast *ast, char **env);

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}	t_token;

t_token		*parsing(void);

t_token	*lexer(char *line);
t_token	*new_token(t_type type, char *value);
void	add_token(t_token **lst, t_token *new);
char	*extract_word(char **line);

int		syntax_check(t_token *tokens);

void	free_all(t_token *tokens, char *line);


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
void free_ast(t_ast *ast);

/* ── libération ── */

void	print_ast(t_ast *ast);
void	free_tokens(t_token *tokens);

#endif
