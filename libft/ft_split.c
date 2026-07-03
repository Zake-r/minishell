/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:35:30 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/02/02 11:31:05 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const	*str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static char	*ft_mystrdup(const char *s1, char c)
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	len = 0;
	while (s1[len] != c && s1[len] != '\0')
		len++;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**free_split(char **ptr, int nb)
{
	while (nb--)
		free(ptr[nb]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			ptr[i] = ft_mystrdup(s, c);
			if (!ptr[i])
				return (free_split(ptr, i));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	ptr[i] = 0;
	return (ptr);
}
/* #include<stdio.h>
int main(void)
{
	char **res;
	char test[] = "hello!";
	//char *s = "      split       this for   me*  !       ";

	char sep = ' ';
	//int i = 0;
	//printf("%d",count_words(test, sep));
	res = ft_split(test,sep);
	for (int i = 0; i < 1; i++)
	{
		printf("%s",res[i]);
	}
} */