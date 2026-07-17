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

int	main(int argc, char **argv, char **env)
{
	t_token	*tokens;
	t_ast	*ast;

	(void)argv;
	if (argc != 1)
		return (printf("The number of arguments is incorrect\n"), 1);
	while (1)
	{
		tokens = parsing();
		if (!tokens)
		return (free_tokens(tokens), 1);
		ast = create_ast(&tokens);
		// printf("\n===== AST =====\n");
		// print_ast(ast, 0, 1);
		exec_ast(ast, env);
		free_ast(ast);
	}
	return (0);
}
