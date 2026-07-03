/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:10:39 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/10 19:10:39 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "memcpy()" copie "n" octets de la zone mémoire "src" vers la
 * zone mémoire "dest".
 * Les zones mémoire ne doivent pas se chevaucher.
 * On retourne la destination "dest".
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		temp2[i] = temp1[i];
		i++;
	}
	return (dest);
}
