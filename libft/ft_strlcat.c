/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:55:01 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:03:19 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len_dst;

	i = 0;
	len_dst = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	if ((dstsize > len_dst))
	{
		while (i < (dstsize - len_dst - 1) && src[i])
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
		return (ft_strlen(src) + len_dst);
	}
	return (ft_strlen(src) + dstsize);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	
 	size_t res1 = ft_strlcat(NULL,"ser",1);
	//size_t res2 = strlcat("","ser",0);
	printf("%zu", res1);
} */