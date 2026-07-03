/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:27 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 09:55:58 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned const char	*u;
	unsigned const char	*v;

	if (!s1 && !s2)
		return (0);
	i = 0;
	u = s1;
	v = s2;
	while (i < n)
	{
		if (u[i] != v[i])
			return ((unsigned char)u[i] - (unsigned char)v[i]);
		i++;
	}
	return (0);
}
/* #include<stdio.h>
int main(void)
{
	char *s1 = "atoms\0\0\0\0";
	char *s2 = "atoms\0abc";
	//char u[] = "t12";
	//char v[] = "t123";

	size_t size = 8;
	printf("%d\n",ft_memcmp(s1,s2,size));	

} */