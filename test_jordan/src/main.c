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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	while (1)
	{
		if (parsing())
			return (1);
		return (0);
	}
	return (0);
}
