/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:28:02 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/15 22:28:02 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "strmapi()" applique la fonction "f" à chaque caractère de la
 * chaîne "s", en passant son index comme premier argument et le caractère
 * lui-même comme deuxième argument.
 * Une nouvelle chaîne est créée à l'aide de "malloc()" pour stocker les
 * résultats des applications successives de "f".
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
