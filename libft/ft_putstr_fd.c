/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:32:08 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/20 22:36:04 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}
/* 
#include <fcntl.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1],O_WRONLY);
		if (fd == -1)
		{
			write(2,"can't open file",15);
			return (1);
		}

		ft_putstr_fd("une phrase",fd);
		
		close(fd);
	}
	else 
		write(2,"wrong argument number",21);
}  */