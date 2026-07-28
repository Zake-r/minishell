/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:54:17 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/19 14:54:17 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_arg_char(char c, t_flags *flags)
{
	int	space;
	int	count;

	space = 0;
	if (flags->width > 1)
		space = flags->width - 1;
	count = 0;
	if (flags->minus >= 1)
	{
		write(1, &c, 1);
		count++;
		while (space-- > 0)
			count += write(1, " ", 1);
	}
	else
	{
		while (space-- > 0)
			count += write(1, " ", 1);
		write(1, &c, 1);
		count++;
	}
	return (count);
}
