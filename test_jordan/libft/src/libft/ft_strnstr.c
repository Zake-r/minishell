/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:07:46 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/13 17:07:46 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strnstr()" localise la première occurrence de la chaîne
 * "little" dans la chaîne "big", où pas plus de len caractères sont
 * recherchés.
 * La fonction retourne un pointeur vers la première valeur trouver.
 * Elle renvoie "big" si "little" est vide.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(little[i]))
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && little[j] == big[i + j]
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
