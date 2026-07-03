/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:54:08 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/14 11:54:08 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "calloc()" alloue de la mémoire pour un tableau de "nmemb"
 * éléments de taille "size" bytes chacun et renvoie un pointeur vers la
 * mémoire allouée.
 * Si "nmemb" ou "size" est égale à "0" renvoie une valeur de pointeur unique
 * transmise avec succès à "free()".
 * La mémoire est mise à "0".
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*temp;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	temp = (char *)ptr;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}
