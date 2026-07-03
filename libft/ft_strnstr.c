/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:24:10 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:04:44 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while ((i < len) && haystack[i])
	{
		while (i + j < len && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char h[] = "je veux trouver";
	char n[] = "veux";
	
	//printf("%s\n",ft_strnstr("","",0));
	printf("%s",strnstr("","",0));
} */