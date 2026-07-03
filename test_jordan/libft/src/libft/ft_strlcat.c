/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:39:56 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/12 16:39:56 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strlcat()" concatène "src" à la suite de "dst" en limitant
 * la taille de la concaténation avec "size".
 * Retourne la longueur de "src" + "size" si "dst" est plus grand ou égale
 * à "size".
 * La chaîne copier doit se terminer par "\0".
 * Retourne la longueur de "dst" + "src".
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && size - 1 > i + dst_len)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}
