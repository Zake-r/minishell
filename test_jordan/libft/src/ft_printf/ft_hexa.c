/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:53:06 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/20 17:53:06 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_len_ptr(unsigned long ptr)
{
	unsigned long	temp;
	int				len;

	temp = ptr;
	len = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}

void	ft_ptr_hexa(unsigned long ptr, int len, char *str, int i)
{
	unsigned long	temp;
	char			*hexa;

	temp = ptr;
	if (i == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (ptr == 0)
	{
		str[0] = '0';
		return ;
	}
	while (temp != 0)
	{
		str[len] = hexa[temp % 16];
		temp /= 16;
		len--;
	}
}

int	ft_flags_len(int adr, t_flags *flags, int len)
{
	if (flags->precision != -1 && flags->precision > len)
		len = flags->precision;
	if (flags->plus && adr)
		len += 1;
	if (adr == 1 || flags->hash)
		len += 2;
	return (len);
}

int	ft_write_hexa1(t_flags *flags, int up, int adr, int count)
{
	if (!flags->minus && !flags->zero && flags->width > count)
		while (flags->width > count)
			count += write(1, " ", 1);
	else if (!flags->minus && flags->zero && flags->precision != -1
		&& flags->width > count)
		while (flags->width > count)
			count += write(1, " ", 1);
	else if (!flags->minus && !flags->zero && !flags->plus && flags->space
		&& adr)
		count += write(1, " ", 1);
	if (flags->plus && adr)
		write(1, "+", 1);
	if ((flags->hash || adr) && up == 0)
		write(1, "0x", 2);
	else if (flags->hash && up)
		write(1, "0X", 2);
	if (!flags->minus && flags->precision == -1 && flags->zero
		&& flags->width > count)
		while (flags->width > count)
			count += write(1, "0", 1);
	return (count);
}

int	ft_print_hexa(unsigned long ptr, int up, int adr, t_flags *flags)
{
	int		len;
	int		count;
	char	*str;

	if (!ptr && adr)
		return (ft_ptr_gest(flags));
	if (flags->hash && !adr && ptr == 0)
		return (write(1, "0", 1));
	len = ft_len_ptr(ptr);
	if (!ft_malloc_hexa(&str, ptr, &len, flags))
		return (0);
	str[len] = '\0';
	ft_ptr_hexa(ptr, len - 1, str, up);
	count = ft_flags_len(adr, flags, len);
	count = ft_write_hexa1(flags, up, adr, count);
	if (flags->precision != -1 && flags->precision > len)
		while (flags->precision-- > len)
			write(1, "0", 1);
	write(1, str, len);
	if (flags->minus && flags->width > count)
		while (flags->width > count)
			count += write(1, " ", 1);
	free(str);
	return (count);
}
