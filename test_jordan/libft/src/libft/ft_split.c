/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:39:08 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/15 15:39:08 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "split()" alloue de la mémoire à l'aide de "malloc()" et
 * renvoie un tableau de chaînes obtenu en divisant "s" à l'aide du
 * caractère "c" comme délimiteur.
 * Le tableau doit se terminer par un pointeur NULL.
 */

static size_t	count_words(const char *s, char c);
static char		**gest(const char *s, char c, char **str);
static char		*gest_words(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	if (!gest(s, c, str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**gest(const char *s, char c, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		str[j] = gest_words(&s[i], c);
		if (!str[j])
		{
			while (j > 0)
				free(str[--j]);
			return (NULL);
		}
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	str[j] = NULL;
	return (str);
}

static char	*gest_words(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
