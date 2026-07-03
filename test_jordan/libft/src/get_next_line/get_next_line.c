/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:57:44 by jbusquet          #+#    #+#             */
/*   Updated: 2025/11/26 11:57:44 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Permet de remplir stash jusqu'à trouver un retour à la ligne
char	*fill_stash(int fd, char *stash)
{
	char	*buf;
	int		len_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!found_newline(stash))
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		if (len_read <= 0)
		{
			free(buf);
			if (!ft_gest_error(stash, len_read))
				return (NULL);
			return (stash);
		}
		buf[len_read] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (NULL);
	}
	free(buf);
	return (stash);
}

// Permet de remplir la ligne avec stash jusqu'à `\n`
char	*fill_newline(char *stash)
{
	char	*line;
	int		len;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		line = malloc(len + 2);
	else
		line = malloc(len + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

// Permet de nettoyer stash des caractère en trop
char	*clean_stash(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = malloc(ft_strlen_gnl(stash) - i + 1);
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = fill_newline(stash);
	if (!line)
		return (NULL);
	stash = clean_stash(stash);
	return (line);
}
