/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:28:34 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/25 16:28:34 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_malloc_hexa(char **str, unsigned long ptr, int *len, t_flags *flags)
{
	if (ptr == 0 && flags->precision == 0)
	{
		*str = ft_strdup("");
		if (!*str)
			return (0);
		*len = 0;
	}
	else
	{
		*str = malloc(*len + 1);
		if (!*str)
			return (0);
	}
	return (1);
}

int	ft_ptr_gest(t_flags *flags)
{
	char	*nil;
	int		nil_len;
	int		count;

	nil = "(nil)";
	nil_len = 5;
	count = nil_len;
	if (!flags->minus && flags->width > count)
		while (flags->width > count)
			count += write(1, " ", 1);
	write(1, nil, nil_len);
	if (flags->minus && flags->width > nil_len)
		while (flags->width > nil_len)
			nil_len += write(1, " ", 1);
	return (count);
}
