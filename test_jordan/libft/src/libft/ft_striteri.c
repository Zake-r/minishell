/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:59:04 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/15 22:59:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "striteri()" applique la fonction "f" à chaque caractère de la
 * chaîne passée en argument, en passant son index comme premier argument.
 * Chaque caractère est passé par adresse à "f" afin qu'il puisse être
 * modifié si nécessaire.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
