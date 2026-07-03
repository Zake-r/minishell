/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:52:43 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 15:52:43 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "substr()" alloue de la mémoire à l'aide de "malloc()" et
 * renvoie une sous-chaîne à partir de la chaîne "s".
 * La sous-chaîne commence à l'index "start" et a une longueur max de "len".
 * Retourne la sous chaîne créer.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	s_len = 0;
	while (s_len < len)
	{
		str[s_len] = s[start + s_len];
		s_len++;
	}
	str[s_len] = '\0';
	return (str);
}
