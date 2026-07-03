/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:45:38 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/21 18:15:25 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
/* 
#include <stdio.h>
int main(void)
{
	int *test;
	int i = 0;
	
	test = ft_calloc(0,0);
	//test = ft_calloc(3,0);
	//printf("%p",test);

	while (i < 3)
	{
		printf("%d",test[i]);
		i++;
	}
	free(test);
} */ 