/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+	   +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:52:04 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 16:52:04 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "putendl_fd()" affiche la chaîne "s" dans le descripteur de
 * fichier spécifié, suivie d'un saut de ligne.
 */

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (!s)
		return ;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
