/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:54:56 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/22 16:54:56 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_type_valide(va_list arg_ptr, const char *format, t_flags *flags)
{
	int	len_format;

	len_format = 0;
	if (*format == 'c')
		len_format = ft_arg_char(va_arg(arg_ptr, int), flags);
	if (*format == 's')
		len_format = ft_arg_str(va_arg(arg_ptr, char *), flags);
	if (*format == 'p')
		len_format = ft_arg_ptr((unsigned long)va_arg(arg_ptr, void *), flags);
	if (*format == 'd' || *format == 'i')
		len_format = ft_arg_int(va_arg(arg_ptr, int), flags);
	if (*format == 'u')
		len_format = ft_arg_unint(va_arg(arg_ptr, unsigned int), flags);
	if (*format == 'x')
		len_format = ft_arg_lowhexa(va_arg(arg_ptr, unsigned int), flags);
	if (*format == 'X')
		len_format = ft_arg_uphexa(va_arg(arg_ptr, unsigned int), flags);
	if (*format == '%')
		len_format = ft_printf_c('%');
	return (len_format);
}

int	ft_arg_valide(char c)
{
	char	*conv;

	conv = "cspdiuxX";
	while (*conv)
	{
		if (*conv == c || '%' == c)
			return (1);
		conv++;
	}
	return (0);
}

int	ft_arg_flags(char c, t_flags *flags)
{
	char	*lst_flags;

	lst_flags = "-0# +";
	while (*lst_flags)
	{
		if (*lst_flags == c)
		{
			if (c == '-')
				flags->minus = 1;
			else if (c == '0')
				flags->zero = 1;
			else if (c == '#')
				flags->hash = 1;
			else if (c == ' ')
				flags->space = 1;
			else if (c == '+')
				flags->plus = 1;
			return (1);
		}
		lst_flags++;
	}
	return (0);
}

int	ft_arg_size(va_list arg_ptr, char *temp, t_flags *flags, int i)
{
	int	*flag;
	int	len;

	if (i)
		flag = &flags->precision;
	else
		flag = &flags->width;
	len = 1;
	if (*temp == '*')
	{
		*flag = va_arg(arg_ptr, int);
		return (1);
	}
	else if (*temp >= '0' && *temp <= '9')
	{
		*flag = *temp - '0';
		while (temp[len] >= '0' && temp[len] <= '9')
			*flag = *flag * 10 + (temp[len++] - '0');
		return (len);
	}
	*flag = 0;
	return (0);
}

int	ft_args_gest(va_list arg_ptr, const char **format)
{
	t_flags		flags;
	const char	*temp;
	int			len_format;
	int			len;

	temp = *format;
	len = 0;
	ft_bzero(&flags, sizeof(t_flags));
	flags.precision = -1;
	while (ft_arg_flags(temp[len], &flags))
		len++;
	len += ft_arg_size(arg_ptr, (char *)(temp + len), &flags, 0);
	if (temp[len] == '.')
	{
		len++;
		len += ft_arg_size(arg_ptr, (char *)(temp + len), &flags, 1);
	}
	if (ft_arg_valide(temp[len]))
	{
		len_format = ft_type_valide(arg_ptr, &temp[len], &flags);
		*format += len + 1;
	}
	else
		len_format = ft_printf_c('%');
	return (len_format);
}
