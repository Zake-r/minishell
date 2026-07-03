/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:14:22 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/16 22:52:04 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
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

		ft_putchar_fd('j',fd);

		close(fd);

	}
	else 
		write(2,"wrong argument number",21);
} */