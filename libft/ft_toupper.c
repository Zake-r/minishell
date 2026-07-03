/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:18 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/18 10:13:36 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && 'z' >= c)
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}
/* 
#include<stdio.h>
int main(void)
{
	printf("%c\n",fr_toupper('-'));
	printf("%c",toupper('f'));
} */