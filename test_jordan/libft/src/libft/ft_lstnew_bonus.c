/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:40:52 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/16 17:40:52 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "lstnew()" alloue de la mémoire à l'aide de "malloc()" et
 * renvoie un nouveau nœud. La variable membre "content" est initialisée
 * avec le paramètre "content" fourni.
 * La variable "next" est initialisée à NULL.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
