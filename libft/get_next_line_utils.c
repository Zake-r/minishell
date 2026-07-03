/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:17:41 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/04/22 17:43:54 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*my_dealloc(t_list *list, int j, char *buff, int is_dashn)
{
	t_list	*new_list;
	t_list	*node_with_dn;

	node_with_dn = find_node_with_dashn(list);
	if (!node_with_dn)
		return (free_and_return_null(list, buff));
	new_list = ft_lstnew(buff);
	if (!new_list)
		return (free_and_return_null(list, buff));
	new_list->next = node_with_dn->next;
	free_until_node(list, new_list->next);
	if ((!is_dashn || !j) && (new_list->next == NULL))
	{
		free(new_list->content);
		free(new_list);
		return (NULL);
	}
	return (new_list);
}

int	is_newline(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstnew(char *c)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = c;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = new;
}

t_list	*find_node_with_dashn(t_list *list)
{
	int		j;
	t_list	*temp;

	temp = list;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
				return (list);
			j++;
		}
		temp = list;
		list = list->next;
	}
	return (temp);
}
