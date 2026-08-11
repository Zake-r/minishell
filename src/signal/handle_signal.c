/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:12:04 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/08/11 22:38:06 by jbossuyt         ###   ########.fr       */
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
