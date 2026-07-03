/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_lowhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:55:10 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/20 17:55:10 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_arg_lowhexa(unsigned int ptr, t_flags *flags)
{
	int	len;

	len = ft_print_hexa(ptr, 0, 0, flags);
	return (len);
}
