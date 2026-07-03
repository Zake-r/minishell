/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:23:08 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/12 19:23:08 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strrchr()" revoie un pointeur vers le dernier caractère trouver
 * correspondant à "c".
 * Retourne "NULL" si aucune similitude trouvé.
 */

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	len--;
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
