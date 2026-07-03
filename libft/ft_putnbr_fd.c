/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:13:56 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/18 11:32:00 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd((n) + '0', fd);
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

		//ft_putnbr_fd(-2147483648,fd);
		ft_putnbr_fd(-234,fd);

		close(fd);

	}
	else 
		write(2,"wrong argument number",21);
} */