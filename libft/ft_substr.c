/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:54:25 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/18 17:26:35 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= (unsigned int)ft_strlen(s))
		len = ft_strlen(&s[start]);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* #include <stdio.h>
int main(void)
{
	char test[] = "grande phrase pour mot";
	//char *str = "01234";
	char *str = "i just want this part #############";
	size_t size = 15; 

	//printf("%s",ft_substr(test,30,30*sizeof(char)));
	printf("%s",ft_substr(test,40,size));
	//printf("%s",ft_substr(test,7,0));
} */