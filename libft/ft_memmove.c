/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:31:50 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/18 10:27:48 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*ptr_src;
	char			*ptr_dst;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if (ptr_dst > ptr_src && ((ptr_dst + len) > ptr_src))
	{
		while (i < len)
		{
			ptr_dst[len - 1 - i] = ptr_src[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	return (dst);
}
/* #include <stdio.h>
int main(void)
{
	char s2[] = "test23";
	char *src = "this is a good nyancat !\r\n";
	char dst1[0xF0];

	//ft_memmove(&s2[0],&s2[2],sizeof(char)*4);//evite le resultat tetete
	ft_memmove(dst1,src,sizeof(char)*27);//evite le resultat tetete
	printf("%s\n",dst1);
	char s1[] = "test23";
	memmove(&s1[0],&s1[2],sizeof(char)*4);//evite le resultat tetete
	printf("%s",s1);
}	 */