/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:31:50 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/17 22:07:40 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*ptr_src;
	char			*ptr_dst;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
/* 
#include<stdio.h>
int main(void)
{
	//char s1[] = "test1";
	//char s2[] = "test23";
	//int n1 = 12;
	//int n2 = 34;
	//ft_memcpy(&n1,&n2,sizeof(int));
	//printf("%d",n1);
	ft_memcpy(((void *)0),((void *)0),3);
	//printf("%s",s2);
} */ 