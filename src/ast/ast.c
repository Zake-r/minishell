/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:16:18 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/13 13:16:18 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


int	word_count(t_token *token)
{
	int count = 0;

	while (token && token->type == WORD)
	{
		count++;
		token = token->next;
	}
	return (count);
}


t_ast	*new_ast_node(t_type type, int nb_arg)
{
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (NULL);

	ast->type = type;
	ast->args = NULL;
	ast->left = NULL;
	ast->right = NULL;

	if (nb_arg > 0)
		ast->args = malloc(sizeof(char *) * (nb_arg + 1));

	return (ast);
}


t_ast	*create_ast_word(t_token **tokens)
{
	t_ast	*ast;
	int		nb_arg;
	int		i;

	nb_arg = word_count(*tokens);

	ast = new_ast_node(WORD, nb_arg);
	if (!ast)
		return (NULL);

	i = 0;
	while (*tokens && (*tokens)->type == WORD)
	{
		ast->args[i] = (*tokens)->value;
		*tokens = (*tokens)->next;
		i++;
	}

	ast->args[i] = NULL;

	return (ast);
}


int	is_redirection(t_type type)
{
	return (
		type == REDIR_IN
		|| type == REDIR_OUT
		|| type == APPEND
		|| type == HEREDOC
	);
}


/*
	Création d'une redirection :

	> file

	REDIR_OUT
	├── left  -> commande
	└── right -> WORD(file)

*/
t_ast	*create_redirection(t_ast *cmd, t_token **tokens)
{
	t_ast	*redir;
	t_ast	*file;


	redir = new_ast_node((*tokens)->type, 0);
	if (!redir)
		return (NULL);

	*tokens = (*tokens)->next;


	if (!*tokens || (*tokens)->type != WORD)
		return (NULL);


	file = create_ast_word(tokens);
	if (!file)
		return (NULL);


	redir->left = cmd;
	redir->right = file;


	return (redir);
}


t_ast	*create_command(t_token **tokens)
{
	t_ast	*cmd;

	cmd = create_ast_word(tokens);
	if (!cmd)
		return (NULL);


	while (*tokens && is_redirection((*tokens)->type))
	{
		cmd = create_redirection(cmd, tokens);

		if (!cmd)
			return (NULL);
	}

	return (cmd);
}


t_ast	*create_ast(t_token **tokens)
{
	t_ast	*left;
	t_ast	*right;
	t_ast	*pipe;


	if (!*tokens)
		return (NULL);


	left = create_command(tokens);


	if (*tokens && (*tokens)->type == PIPE)
	{
		*tokens = (*tokens)->next;

		right = create_ast(tokens);

		pipe = new_ast_node(PIPE, 0);
		if (!pipe)
			return (NULL);

		pipe->left = left;
		pipe->right = right;

		return (pipe);
	}


	return (left);
}