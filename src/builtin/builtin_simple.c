/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:19:33 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 23:01:34 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	builtin_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}

int	builtin_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	builtin_echo(t_ast *ast)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (ast->args[1] && strcmp(ast->args[1], "-n") == 0)
	{
		newline = 0;
		i = 2;
	}
	while (ast->args[i])
	{
		write(1, ast->args[i], ft_strlen(ast->args[i]));
		if (ast->args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(t_ast *ast)
{
	long	code;

	printf("exit\n");
	if (ast->args[1] && ast->args[2])
	{
		write(2, "exit: too many arguments\n", 25);
		g_exit_status = 1;
		return ;
	}
	if (ast->args[1])
	{
		if (!is_numeric(ast->args[1]))
		{
			write(2, "exit: ", 6);
			write(2, ast->args[1], ft_strlen(ast->args[1]));
			write(2, ": numeric argument required\n", 28);
			exit(2);
		}
		code = ft_atoi(ast->args[1]);
		exit((unsigned char)code);
	}
	exit(g_exit_status);
}
