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
	char **parsed_env = dup_env(env);
	//t_env	env_struct;

	(void)argv;
	if (argc != 1)
		return (printf("The number of arguments is incorrect\n"), 1);
/* 	env_struct.env = env;
	env_struct.parsed_env = dup_env(env);
	if (!env_struct.parsed_env)
	{
		perror("dup_env");
		return (1);
	} */
	while (1)
	{
		tokens = parsing();
		if (!tokens)
		return (free_tokens(tokens), 1);
		ast = create_ast(&tokens);
		// printf("\n===== AST =====\n");
		// print_ast(ast, 0, 1);
		exec_ast(ast, &parsed_env);
		free_ast(ast);
	}
	free_env(parsed_env);
	return (0);
}
