/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:24:57 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:00:36 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned const char	*v;
	unsigned char		h;

	i = 0;
	h = (unsigned char)c;
	v = (unsigned const char *)s;
	while (i < n)
	{
		if (v[i] == h)
			return ((void *)&v[i]);
		i++;
	}
	return (0);
}
/*  
#include<stdio.h>
#include<string.h>
int main(void)
{
	char s1[] = "er2344weru";
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("%p\n",s);
	printf("%p\n",ft_memchr(s1,'2',3));
	printf("%p",memchr(s1,'2',3));

} */