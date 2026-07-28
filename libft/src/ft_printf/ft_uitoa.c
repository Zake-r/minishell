/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:11:24 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/22 22:11:24 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*number;
	size_t	len;
	long	nb;

	nb = n;
	len = length(n);
	number = malloc(len + 1);
	if (!number)
		return (NULL);
	number[len] = '\0';
	if (nb < 0)
	{
		number[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (number);
}
