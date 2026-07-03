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

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}	t_token;

int		parsing(void);

t_token	*lexer(char *line);
t_token	*new_token(t_type type, char *value);
void	add_token(t_token **lst, t_token *new);
char	*extract_word(char **line);

int		syntax_check(t_token *tokens);

void	free_all(t_token *tokens, char *line);

#endif
