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
#include <errno.h>

extern int	g_exit_status;


typedef enum e_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}	t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_ast
{
	t_type			type;
	char			**args;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_env
{
	char **env;
	char **parsed_env;
}	t_env;

// parsing:
t_token	*parsing(char *line, char **parsed_env);

t_token	*lexer(char *line);
t_token	*new_token(t_type type, char *value);
void	add_token(t_token **lst, t_token *new);
char	*extract_word(char **line);

int		syntax_check(t_token *tokens);

t_ast	*create_ast(t_token **tokens);



/* ── helpers ── */

int		count_pipe(char *s);
int		count_word_to_pipe(char *s);

/* ── builtins ── */
int		is_builtin(char *cmd);
int		builtin_cd(t_ast *ast, char ***env);
int		builtin_pwd(void);
int		builtin_env(char **env);
int		builtin_echo(t_ast *ast);
int		is_valid_identifier(char *str);
int		export_one(char ***env, char *arg);
int		builtin_export(t_ast *ast, char ***env);
int		builtin_unset(t_ast *ast, char ***env);
void	builtin_exit(t_ast *ast);
void	exec_builtin(t_ast *ast, char ***env);


/* ── env ── */
void	free_env(char **env);
char	**dup_env(char **env);
char	*env_get(char **env, char *name);
int		env_find_index(char **env, char *name);
char	*build_entry(char *name, char *value);
char	**env_set(char **env, char *name, char *value);
char	**env_unset(char **env, char *name);


/* ── parsing ── */

t_token	*parse_line(char *line, int nb_cmd);

/* ── exécution ── */
void	exec_cmd(t_ast *ast, char ***env);
void	exec_pipe(t_ast *ast, char ***env);
void	exec_redirection(t_ast *ast, char ***env);
void	exec_heredoc(t_ast *ast, char ***env);
void	exec_ast(t_ast *ast, char ***env);

/* ── redirections ── */
int		apply_one_redir(t_ast *ast);
t_ast	*apply_redirections(t_ast *ast);

/* ── ast/free ── */
void	free_ast(t_ast *ast);
void	free_one_ast_node(t_ast *ast);

/* ── status ── */
int		status_to_exit_code(int status);


/* ── libération ── */

void	exec_cmd(t_ast *ast, char ***env);
void	exec_pipe(t_ast *ast, char ***env);
void	exec_ast(t_ast *ast, char ***env);

// free:
void	free_all(t_token *tokens, char *line);
void	free_tokens(t_token *tokens);

char *verif_command(char *cmd, char **env);
void handle_ctrlc(int num);
void handle_ctrlc_heredoc(int num);




#endif
