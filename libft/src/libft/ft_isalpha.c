/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:35:08 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/07 23:35:08 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "isalpha()" vérifie si "c" s'agit d'un caractère alphabétique.
 * Si le caractère est alphabétique on renvoie une valeur positive sinon "0".
 * Dans la locale standard "C", cela équivaut à (isupper(c) || islower(c)).
 */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
