/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:45:06 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/09 16:47:38 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*release_memory_buffer(char *buffer)
{
	free(buffer);
	return (NULL);
}

static char	*release_memory(char **save)
{
	if (save == NULL || *save == NULL)
		return (NULL);
	free(*save);
	*save = NULL;
	return (NULL);
}

static char	*get_line_from_save(char **save)
{
	char	*line;
	char	*next_line;
	int		i;

	if (ft_strchr(*save, '\n') == NULL)
	{
		line = *save;
		*save = NULL;
		return (line);
	}
	i = 0;
	while ((*save)[i] != '\n')
		i++;
	line = ft_substr(*save, 0, i + 1);
	next_line = ft_strdup(*save + i + 1);
	if (next_line == NULL)
	{
		free(line);
		return (release_memory(save));
	}
	free(*save);
	*save = next_line;
	return (line);
}

static char	*read_file(int fd, char *buffer, char **save)
{
	ssize_t	read_bytes;
	char	*tmp;

	read_bytes = 1;
	while (read_bytes > 0 && ft_strchr(*save, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (release_memory(save));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(*save, buffer);
		if (tmp == NULL)
			return (release_memory(save));
		free(*save);
		*save = tmp;
	}
	if (read_bytes == 0 && *save[0] == 0)
		return (release_memory(save));
	return (*save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (save == NULL)
	{
		save = ft_strdup("");
		if (save == NULL)
			return (release_memory_buffer(buffer));
	}
	line = read_file(fd, buffer, &save);
	if (line == NULL)
		return (release_memory_buffer(buffer));
	line = get_line_from_save(&save);
	free(buffer);
	return (line);
}
