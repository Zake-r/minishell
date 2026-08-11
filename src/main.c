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

int	g_exit_status = 0;

static void	shell_loop(char **parsed_env)
{
	t_token	*tokens;
	t_ast	*ast;
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		rl_on_new_line();
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line == '\0')
			continue ;
		tokens = parsing(line, parsed_env);
		if (!tokens)
			continue ;
		ast = create_ast(&tokens);
		exec_ast(ast, &parsed_env);
		free_ast(ast);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**parsed_env;

	parsed_env = dup_env(env);
	(void)argv;
	if (argc != 1)
		return (printf("The number of arguments is incorrect\n"), 1);
	signal(SIGINT, handle_ctrlc);
	signal(SIGQUIT, SIG_IGN);
	shell_loop(parsed_env);
	free_env(parsed_env);
	return (g_exit_status);
}
