/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:05:09 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/20 22:46:11 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void rot1(unsigned int i, char *c)
{
	(void)i;
	if (*c <= 'z' && *c >= 'a')
		*c = (((*c - 'a') + 1) % 26) + 'a';
	if (*c <= 'Z' && *c >= 'A')
		*c = (((*c - 'A') + 1) % 26) + 'A';
}

#include <stdio.h>
int main(void)
{
	char test[] = "abc  zABCZ";
	ft_striteri(test,&rot1);
	printf("%s",test);
} */