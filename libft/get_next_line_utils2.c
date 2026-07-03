/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:43:12 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/04/23 16:59:14 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
	}
}

t_list	*free_and_return_null(t_list *list, char *buff)
{
	free(buff);
	free_list(list);
	return (NULL);
}

void	free_until_node(t_list *list, t_list *stop_node)
{
	t_list	*temp;

	while (list != stop_node)
	{
		temp = list;
		list = temp->next;
		free(temp->content);
		free(temp);
	}
}
