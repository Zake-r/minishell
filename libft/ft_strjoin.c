/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:08:40 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/20 22:45:25 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tlen;
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tlen = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((tlen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
/* 
#include <stdio.h>
int main(void)
{
	char u[] = "test";
	char v[] = "encore";

	printf("%s",ft_strjoin(u,v));
} */