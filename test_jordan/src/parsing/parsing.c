/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:51:26 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 13:07:27 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parsing(void)
{
	char	*line;
	t_token	*tokens;

	line = readline("> ");
	if (!line)
		return (1);
	tokens = lexer(line);
	if (!tokens)
		return (1);
	if (syntax_check(tokens))
		return (free_all(tokens, line), 1);
	free_all(tokens, line);
	return (0);
}
