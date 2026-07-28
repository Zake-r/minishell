/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:43:38 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/09 19:43:38 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "isalnum()" vérifie si "c" s'agit d'un caractère
 * alphanumérique.
 * Si le caractère est alphanuméric on renvoie une valeur positive sinon "0".
 * Cela équivaut à (isalpha(c) || isdigit(c)).
 */

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
