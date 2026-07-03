/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:01 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/20 22:40:59 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* 
char rot1(unsigned int i, char c)
{
	(void)i;
	if (c <= 'z' && c >= 'a')
		c = (((c - 'a') + 1) % 26) + 'a';
	if (c <= 'Z' && c >= 'A')
		c = (((c - 'A') + 1) % 26) + 'A';
	return (c);
}

#include <stdio.h>
int main(void)
{
	char test[] = "ma phrasezABCZ";
	printf("%s",ft_strmapi(test,&rot1));
}
 */