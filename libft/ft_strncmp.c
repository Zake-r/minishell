/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:02:36 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:04:20 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/* #include<stdio.h>
#include<string.h>
int main(void)
{
	char u[] = "\200";
	char v[] = "\0";
	size_t size = 1;
	printf("%d\n",ft_strncmp(u,v,size));	
	printf("%d\n",strncmp(u,v,size));	

} */