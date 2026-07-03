/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_uphexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:55:06 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/20 17:55:06 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_arg_uphexa(unsigned int ptr, t_flags *flags)
{
	int	len;

	len = ft_print_hexa(ptr, 1, 0, flags);
	return (len);
}
