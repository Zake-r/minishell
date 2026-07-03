/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:16:41 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/16 00:16:41 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "putstr_fd()" affiche la chaîne "s" dans le descripteur de
 * fichier spécifié.
 */

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (!s)
		return ;
	while (s[len])
		len++;
	write(fd, s, len);
}
