/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:33:59 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:05:04 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/* #include<stdio.h>
#include<string.h>
int main(void)
{
	char s[] = "123456789";
	printf("%p\n",s);
	printf("%p\n",ft_strrchr(s,'a'));
	printf("%p",strrchr(s,'a'));

} */