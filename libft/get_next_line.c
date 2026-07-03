/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbossuyt <jbossuyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:41:02 by jbossuyt          #+#    #+#             */
/*   Updated: 2026/04/23 17:12:01 by jbossuyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*create_list(t_list *list, int fd)
{
	char	*buffer;
	int		n;

	buffer = NULL;
	while (!is_newline(buffer))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		n = read(fd, buffer, BUFFER_SIZE);
		if (!n)
		{
			free(buffer);
			return (list);
		}
		buffer[n] = '\0';
		if (!list)
			list = ft_lstnew(buffer);
		else
			ft_lstadd_back(&list, ft_lstnew(buffer));
		if (!list)
			free(buffer);
	}
	return (list);
}

int	get_size(int param, t_list *list)
{
	int	size;
	int	i;

	size = 0;
	while (list)
	{
		if (param == 1)
		{
			i = 0;
			while (list->content[i] != '\n' && list->content[i])
			{
				i++;
				size++;
			}
			if (list->content[i] == '\n')
			{
				size++;
				break ;
			}
		}
		else
			size++;
		list = list->next;
	}
	return (size);
}

char	*get_line(t_list *list, char *line)
{
	int	i;
	int	j;

	if (!list)
		return (NULL);
	line = malloc(sizeof(char) * (get_size(1, list) + 1));
	if (!line)
		return (NULL);
	line[get_size(1, list)] = '\0';
	j = 0;
	while (list)
	{
		i = 0;
		while ((i < BUFFER_SIZE) && list->content[i])
		{
			line[j++] = list->content[i++];
			if (list->content[i - 1] == '\n')
				return (line);
		}
		list = list->next;
	}
	return (line);
}

t_list	*prepare(t_list *list)
{
	t_list	*last_node;
	char	*buff;
	int		i;
	int		j;

	last_node = find_node_with_dashn(list);
	buff = malloc(BUFFER_SIZE + 1);
	if (!last_node || !buff)
	{
		free_list(list);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (last_node->content[i] != '\n' && last_node->content[i])
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i])
		buff[j++] = last_node->content[i++];
	buff[j] = '\0';
	return (my_dealloc(list, j, buff, (j > 0
				|| (i > 0 && last_node->content[i - 1] == '\n'))));
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	line = NULL;
	list = create_list(list, fd);
	if (!list)
		return (NULL);
	line = get_line(list, line);
	if (!line)
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	list = prepare(list);
	return (line);
}

/* int main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1],O_RDONLY);
  	char *str;
	
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
 	close(fd);
}  */
