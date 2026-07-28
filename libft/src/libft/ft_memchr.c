/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:21:06 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/13 16:21:06 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "memchr()" analyse les "n" premiers octets de la zone mémoire
 * pointée par "s" à la recherche de la première occurrence de "c".
 * La fonction ne s'arrête que lorsque "n" est terminer pas à la fin de "s"
 * Elle retourne un pointeur vers le caractère "c" si trouvé sinon "NULL".
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	unsigned char	*s2;
	size_t			i;

	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
