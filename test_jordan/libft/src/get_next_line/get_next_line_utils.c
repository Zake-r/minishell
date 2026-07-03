/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:58:36 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/26 11:58:36 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Permet de gèrer les erreurs de `read`
char	*ft_gest_error(char *stash, int len_read)
{
	if (len_read < 0)
	{
		free(stash);
		return (NULL);
	}
	else if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

// Permet de voir si un caractère de saut de ligne se trouve dans une chaîne
int	found_newline(char *stash)
{
	if (!stash)
		return (0);
	while (*stash)
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

// Permet de calculer la taille d'une chaîne caratère
size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// Permet de concatener 2 chaînes de caractère entre elles
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	str = malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len_s1];
		i++;
	}
	str[len_s1 + len_s2] = '\0';
	free(s1);
	return (str);
}
