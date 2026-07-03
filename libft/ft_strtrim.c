/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:23:06 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/02/02 11:31:35 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_characters(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len_s1;
	char	*ptr;
	int		start;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	start = len_s1;
	i = 0;
	j = 0;
	while (check_characters(s1[i], set) && s1[i])
	{
		len_s1--;
		i++;
	}
	while ((0 != len_s1) && check_characters(s1[(start - 1) - j], set))
		j++;
	ptr = malloc(((len_s1 - j) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memcpy(ptr, &s1[i], len_s1 - j);
	ptr[len_s1 - j] = '\0';
	return (ptr);
}
/* #include<stdio.h>
int main(void)
{
	char test[] = "";
	//char s1[] = "  ";
	char r[] = " \n\t";
	
	printf("%s",ft_strtrim("",""));
}   */