/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 03:43:58 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/08 03:43:58 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "isdigit()" vérifie si "c" est un chiffre (de 0 à 9).
 * Si le caractère est numérique on revoie une valeur possitive sinon "0".
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
