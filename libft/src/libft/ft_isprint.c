/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:47:56 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/09 20:47:56 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "isprint()" vérifie si "c" est un caractère imprimable.
 * Si le caractère est imprimable on revoie une valeur possitive sinon "0".
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
