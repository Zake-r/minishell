/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:16:59 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/15 23:16:59 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "ft_putchar_fd()" affiche le caractère "c" dans le descripteur
 * de fichier spécifié.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
