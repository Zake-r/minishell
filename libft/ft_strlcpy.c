/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:55:01 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:03:51 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*  
#include <stdio.h>
int main(void)
{
	char s[] = "test";
	char t[] = "something";
	size_t res;
	char u[] = "ooooooooooooooooo";
	char v[] = "lorem ipsum dolor sit amet";
	size_t res1;

	res = strlcpy(s,t,3);
	printf("%s\n",s);
	printf("%zu\n", res);
	
	res1 = ft_strlcpy(u,v,15);
	printf("%s\n",u);
	printf("%zu", res1);
} */ 