/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:08:10 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/17 00:08:10 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * La fonction "lstmap()" itère à travers la liste "lst", applique la
 * fonction "f" au contenu de chaque nœud et crée une nouvelle liste
 * résultant des applications successives de la fonction "f".
 * La fonction "del" est utilisée pour supprimer le contenu d'un nœud
 * si nécessaire.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	void	*content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
