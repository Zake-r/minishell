/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:58:41 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/26 11:58:41 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Library needed:
# include <unistd.h>
# include <stdlib.h>

// Definition of `BUFFER_SIZE`:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// Function protoypes:
char	*get_next_line(int fd);

// Utils:
char	*ft_gest_error(char *stash, int len_read);
int		found_newline(char *stash);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif