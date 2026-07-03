/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:10:14 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/19 18:10:14 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_print_i(t_flags *flags, int len, int i, int len_str)
{
	if (!flags->minus && !flags->zero && flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	else if (!flags->minus && flags->zero && flags->precision != -1
		&& flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	else if (!flags->minus && !flags->zero && !flags->plus && flags->space
		&& i >= 0)
		len += write(1, " ", 1);
	if (flags->plus && i >= 0)
		write(1, "+", 1);
	else if (i < 0)
		write(1, "-", 1);
	if (!flags->minus && flags->precision == -1 && flags->zero
		&& flags->width > len)
		while (flags->width > len)
			len += write(1, "0", 1);
	if (flags->precision != -1 && flags->precision > len_str && i >= 0)
		while (flags->precision-- > len_str)
			write(1, "0", 1);
	else if (flags->precision != -1 && flags->precision > len_str - 1 && i < 0)
		while (flags->precision-- > len_str - 1)
			write(1, "0", 1);
	return (len);
}

void	ft_write_str(char *str, int i, int len_str)
{
	if (i >= 0)
		write(1, str, len_str);
	else
		write(1, str + 1, len_str - 1);
}

int	ft_arg_int(int i, t_flags *flags)
{
	char	*str;
	int		len;
	int		len_str;

	str = ft_itoa(i);
	if (i == 0 && flags->precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	len = ft_strlen(str);
	len_str = len;
	if (flags->precision != -1 && flags->precision > len && i >= 0)
		len = flags->precision;
	else if (flags->precision != -1 && flags->precision > len - 1 && i < 0)
		len = flags->precision + 1;
	if (flags->plus && i >= 0)
		len += 1;
	len = ft_print_i(flags, len, i, len_str);
	ft_write_str(str, i, len_str);
	if (flags->minus && flags->width > len)
		while (flags->width > len)
			len += write(1, " ", 1);
	free(str);
	return (len);
}
