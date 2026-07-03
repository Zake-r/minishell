/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:52:17 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/09 19:52:17 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "isascii()" vérifie si "c" est une valeur "unsigned char" de 7
 * bits qui correspond au jeu de caractères ASCII.
 * Si le caractère provient de la table ascii on renvoit une valeur possitive
 * sinon "0".
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
