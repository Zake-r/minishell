/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+	   +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:52:04 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 16:52:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strdup()" renvoie un pointeur vers une nouvelle chaîne qui
 * est une copie de la chaîne "s".
 * La mémoire pour la nouvelle chaîne est obtenue avec "malloc()" et peut
 * être libérée avec "free()".
 * La nouvelle chaîne doit contenir "\0" à la fin.
 */

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
