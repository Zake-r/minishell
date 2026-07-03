/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:44:14 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/02/28 13:31:52 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ('0' <= str[i] && '9' >= str[i])
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * signe);
}
/* #include <stdio.h>
int main(void)
{
	char *n = "      3234123";
	//	char str[] = "  +234" ;
	//printf("%d\n",atoi(str));
	printf("%d",ft_atoi(n));
} */