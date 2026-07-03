/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:39:14 by jbossuyt          #+#    #+#             */
/*   Updated: 2025/11/29 10:01:33 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
/* #include<stdio.h>
int main(void)
{
	char sentence[9] = "ma phrase";

	ft_memset(sentence + 2,'.',2*sizeof(char));
	printf("%s",sentence);


} */