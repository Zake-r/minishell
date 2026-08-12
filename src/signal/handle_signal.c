/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:12:04 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/12 15:41:21 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_ctrlc(int num)
{
	(void)num;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_ctrlc_heredoc(int num)
{
	(void)num;
	rl_replace_line("", 0);
	exit(0);
}

void	handle_ctrlc_inprocess(int num)
{
	(void)num;
	write(1, "\n", 1);
}
