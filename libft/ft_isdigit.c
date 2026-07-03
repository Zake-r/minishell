/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:23:09 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/16 23:38:29 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}
/*  
#include<stdio.h>

int main(void)
{
	//int c = 3;
	int c = 'c';
	printf("%d\n",ft_isdigit(c));
} */