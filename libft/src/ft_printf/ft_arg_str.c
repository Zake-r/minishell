/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:43:07 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/19 17:43:07 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_minus_print(char *str, int len, int space, int count)
{
	write(1, str, len);
	while (space-- > 0)
		write(1, " ", 1);
	return (count);
}

int	ft_arg_str(char *str, t_flags *flags)
{
	int	len;
	int	space;
	int	count;

	if (flags->precision <= 5 && flags->precision >= 0 && !str)
		str = "";
	else if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	space = flags->width - len;
	if (space < 0)
		space = 0;
	count = len + space;
	if (flags->minus)
		return (ft_minus_print(str, len, space, count));
	else
		while (space-- > 0)
			write(1, " ", 1);
	write(1, str, len);
	return (count);
}
