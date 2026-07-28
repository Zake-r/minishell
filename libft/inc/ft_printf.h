/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:31:48 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/20 18:31:48 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Library needed:
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Definition of the linked list:
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}		t_flags;

// Function protoypes:
int		ft_printf(const char *format, ...);

// Utils:
int		ft_printf_c(char c);
char	*ft_uitoa(unsigned int n);
int		ft_args_gest(va_list arg_ptr, const char **format);
int		ft_arg_char(char c, t_flags *flags);
int		ft_arg_str(char *str, t_flags *flags);
int		ft_arg_ptr(unsigned long ptr, t_flags *flags);
int		ft_arg_int(int i, t_flags *flags);
int		ft_arg_unint(unsigned int i, t_flags *flags);
int		ft_arg_lowhexa(unsigned int i, t_flags *flags);
int		ft_arg_uphexa(unsigned int i, t_flags *flags);
int		ft_len_ptr(unsigned long ptr);
void	ft_ptr_hexa(unsigned long ptr, int len, char *str, int i);
int		ft_print_hexa(unsigned long ptr, int up, int adr, t_flags *flags);
int		ft_malloc_hexa(char **str, unsigned long ptr, int *len,
			t_flags *flags);
int		ft_ptr_gest(t_flags *flags);

#endif