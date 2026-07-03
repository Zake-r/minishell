/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:13:00 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 17:13:00 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strtrim()" alloue de la mémoire à l'aide de "malloc()" et
 * renvoie une copie de "s1" dont les caractères de "set" ont été supprimés
 * au début et à la fin.
 */

static int		is_sep(char const *set, char c);
static char		*gest_malloc(size_t start, size_t end);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (is_sep(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_sep(set, s1[end - 1]))
		end--;
	s_trim = gest_malloc(start, end);
	if (!s_trim)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s_trim[i] = s1[start];
		start++;
		i++;
	}
	s_trim[i] = '\0';
	return (s_trim);
}

static int	is_sep(char const *sep, char c)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*gest_malloc(size_t start, size_t end)
{
	char	*s_trim;

	if (start >= end)
	{
		s_trim = malloc(1);
		if (!s_trim)
			return (NULL);
		s_trim[0] = '\0';
		return (s_trim);
	}
	s_trim = malloc((end - start) + 1);
	if (!s_trim)
		return (NULL);
	return (s_trim);
}
