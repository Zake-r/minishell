/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:25:34 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/19 18:25:34 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_arg_ptr(unsigned long ptr, t_flags *flags)
{
	int	len;

	len = ft_print_hexa(ptr, 0, 1, flags);
	return (len);
}
