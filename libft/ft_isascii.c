/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:53:33 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/09 13:53:34 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	else
		return (0);
}
/* 
#include<stdio.h>

int main(void)
{
	int c = 'a';
	printf("%d\n",ft_isascii(c));
} */