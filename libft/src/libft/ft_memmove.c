/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:58:16 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/10 23:58:16 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "memmove()" copie "n" octets de la zone mémoire "src" vers la
 * zone mémoire "dest".
 * Les zones mémoire peuvent se chevaucher.
 * La copie s'effectue comme si les octets de "src" étaient d'abord copiés
 * dans un tableau temporaire qui ne chevauche ni "src" ni "dest",
 * puis copiés depuis le tableau temporaire vers "dest".
 * On retourne la destination "dest".
 */

static void	copy(unsigned char *temp1, unsigned char *temp2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		temp2[i] = temp1[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dest && !src)
		return (NULL);
	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dest;
	if (temp2 > temp1 && temp2 < temp1 + n)
	{
		while (n > 0)
		{
			temp2[n - 1] = temp1[n - 1];
			n--;
		}
	}
	else
		copy(temp1, temp2, n);
	return (dest);
}
