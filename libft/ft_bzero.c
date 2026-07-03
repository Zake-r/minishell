/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:42:55 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:00:01 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (n == 0)
		return ;
	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/* #include<stdio.h>
int main(void)
{
	char sentence[10] = "ma phrase";
	printf("before :%s\n",sentence);
	ft_bzero(sentence,2);
	printf("after :%s",sentence);
} */