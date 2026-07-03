/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:56:35 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/02/07 13:22:38 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght_number(int t)
{
	int	len;

	len = 1;
	if (t == 0)
		return (1);
	if (t < 0)
		len++;
	while (t / 10)
	{
		len++;
		t = t / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ptr;
	long int	nbr;

	nbr = (long int)n;
	len = lenght_number(nbr);
	ptr = malloc((len + 1) * sizeof(char));
	ptr = NULL;
	if (ptr == NULL)
		return (NULL);
	if (nbr == 0)
		ptr[0] = '0';
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr *= -1;
	}
	ptr[len] = '\0';
	while (nbr > 0)
	{
		len--;
		ptr[len] = ((nbr % 10) + 48);
		nbr = nbr / 10;
	}
	return (ptr);
}
/* 
#include<stdio.h>
int main(void)
{
	for(int i = -25;i < 25;i++)
		printf("%s\n",ft_itoa(i));
	//printf("%s\n",ft_itoa(-2147483648));
} */ 