/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:14:13 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/16 20:14:13 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "lstadd_front()" ajoute le nœud "new" au début de la liste.
 * Visuel : lst -> [A] -> [B] -> [C] -> NULL
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*next;

	if (!new)
		return ;
	next = *lst;
	*lst = new;
	new->next = next;
}
