/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:39:02 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 11:39:02 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* typedef struct s_ast
{
	t_type type;
	char **args;
	struct s_ast *left;
	struct s_ast *right;
}	t_ast;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}	t_token;
 */

int word_count(t_token *token)
{
	int count = 0;
	while (token && token->type == WORD)
	{
		count++;
		token = token->next;
	}
	return count;
}

t_ast *new_ast_node(t_type type, int nb_arg)
{
	t_ast *ast;
	
	ast = malloc(sizeof(t_ast));
	ast->type = type;
	ast->args = malloc(sizeof(char *) * (nb_arg + 1));
	ast->left = NULL;
	ast->right = NULL;

	return ast;
}

t_ast	*create_ast_word(t_token **tokens)
{
	t_ast	*ast;
	int 	nb_arg = 0;
	int	 	i = 0;

	nb_arg = word_count(*tokens);
	ast = new_ast_node(WORD, nb_arg);
	while (*tokens && (*tokens)->type == WORD)
	{
		ast->args[i] = (*tokens)->value;		
		*tokens = (*tokens)->next;
		i++;
	}
	ast->args[i] = NULL;
	return ast;
}

t_ast	*create_ast(t_token **tokens)
{
	t_ast *ast = NULL;
    t_ast *left = NULL;
    t_ast *right = NULL;

    if (!*tokens)
        return NULL;

    if ((*tokens)->type == WORD) {
        left = create_ast_word(tokens);
        if (!left)
            return NULL;
    }

    if (*tokens && (*tokens)->type == PIPE) {
        *tokens = (*tokens)->next;  
        right = create_ast(tokens);
        if (!right)
            return NULL;
        ast = new_ast_node(PIPE, 0);
        ast->left = left;
        ast->right = right;
    }

	else 
	{
		ast = left;
	}
	return ast;

}




int	main(int argc, char **argv, char **env)
{
	t_token	*tokens;
	t_ast	*ast;

	(void)argc;
	(void)argv;
	while (1)
	{
		tokens = parsing();

		// if (parsing())
		// 	return (1);
		ast = create_ast(&tokens);   
		//print_ast(ast);
		exec_ast(ast, env);
		free_ast(ast);
		return (0);
	}
	return (0);
}
