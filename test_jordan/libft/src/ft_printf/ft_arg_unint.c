/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:32:00 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/20 17:32:00 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_print_i(t_flags *flags, int len, int len_str)
{
	if (!flags->minus && !flags->zero && flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	else if (!flags->minus && flags->zero && flags->precision != -1
		&& flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	if (!flags->minus && flags->precision == -1 && flags->zero
		&& flags->width > len)
		while (flags->width > len)
			len += write(1, "0", 1);
	if (flags->precision != -1 && flags->precision > len_str)
		while (flags->precision-- > len_str)
			write(1, "0", 1);
	return (len);
}

int	ft_arg_unint(unsigned int i, t_flags *flags)
{
	char	*str;
	int		len;
	int		len_str;

	str = ft_uitoa(i);
	if (i == 0 && flags->precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	len = ft_strlen(str);
	len_str = len;
	if (flags->precision != -1 && flags->precision > len)
		len = flags->precision;
	len = ft_print_i(flags, len, len_str);
	write(1, str, len_str);
	if (flags->minus && flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	free(str);
	return (len);
}
