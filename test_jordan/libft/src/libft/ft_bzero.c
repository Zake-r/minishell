/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:17:59 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/10 18:17:59 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "bzero()" remplace les données contenues dans les "n"
 * octets de mémoire à partir de l'emplacement pointé par "s", en écrivant
 * des zéros (octets contenant "\0") dans cette zone.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
