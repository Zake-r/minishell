/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:15:40 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:02:54 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* 
#include <stdio.h>
int main(void)
{
	
	char *ptr;
	char test[] = "ma phrase";

	ptr = ft_strdup(test);

	printf("%s",ptr);
	free(ptr);
} */ 