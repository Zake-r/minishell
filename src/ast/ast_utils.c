/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:46:04 by jbusquet          #+#    #+#             */
/*   Updated: 2026/08/11 22:46:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	word_count(t_token *token)
{
	int	count;

	count = 0;
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

t_ast	*create_ast_filename(t_token **tokens)
{
	t_ast	*ast;

	ast = new_ast_node(WORD, 1);
	if (!ast)
		return (NULL);
	ast->args[0] = (*tokens)->value;
	ast->args[1] = NULL;
	*tokens = (*tokens)->next;
	return (ast);
}
