/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:29:24 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/15 20:29:24 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "itoa()" alloue de la mémoire à l'aide de "malloc()" et renvoie
 * une chaîne représentant l'entier reçu en tant qu'argument.
 * Les nombres négatifs doivent être traités.
 */

static size_t	length(int n);

char	*ft_itoa(int n)
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

static size_t	length(int n)
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
