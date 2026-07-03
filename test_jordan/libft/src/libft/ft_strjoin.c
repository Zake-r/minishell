/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+	   +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:52:04 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 16:52:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strjoin()" alloue de la mémoire à l'aide de "malloc()" et
 * renvoie une nouvelle chaîne, qui est le résultat de la concaténation de
 * "s1" et "s2".
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
	return (str);
}
