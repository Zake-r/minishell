/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:06:05 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/13 18:06:05 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "atoi()" convertit la partie initiale de la chaîne pointée par
 * "nptr" en (int).
 * Ignore tout les espaces au début de la chaîne de caractère.
 * Gère le sign si il y en a 1 seul.
 * Ne gère plus ce qui vient après les caractères n'étant plus des chiffres.
 * Retourne la valeur en (int).
 */

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}
