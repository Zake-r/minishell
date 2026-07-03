/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:18 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/18 10:13:49 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && 'Z' >= c)
	{
		c += 32;
		return (c);
	}
	else
		return (c);
}
/* 
#include<stdio.h>
int main(void)
{
	printf("%c\n",ft_tolower('-'));
	printf("%c",tolower('F'));
} */ 