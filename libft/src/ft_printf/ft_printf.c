/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:32:56 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/18 15:32:56 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_check_args(va_list arg_ptr, const char *format)
{
	int	len_format;

	len_format = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len_format += ft_args_gest(arg_ptr, &format);
		}
		else
			len_format += ft_printf_c(*format++);
	}
	return (len_format);
}

int	ft_printf(const char *format, ...)
{
	int		len_format;
	va_list	arg_ptr;

	if (!format || *format == '\0')
		return (0);
	va_start(arg_ptr, format);
	len_format = ft_check_args(arg_ptr, format);
	va_end(arg_ptr);
	return (len_format);
}
