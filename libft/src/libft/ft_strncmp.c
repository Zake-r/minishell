/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:31:15 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/13 14:31:15 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strncmp()" compare la chaîne "s1" avec la chaîne "s2" avec une
 * longueur maxiaml qui est de "n".
 * Les chaînes comparées doivent être non signer.
 * Elle retourne une valeur négative si "s1" est inférieure à "s2".
 * Elle retourne une valeur positive si "s1" est supérieur à "s2".
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (temp1[i] && temp2[i] && temp1[i] == temp2[i] && i < n - 1)
		i++;
	return (temp1[i] - temp2[i]);
}
