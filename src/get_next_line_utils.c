/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:49:45 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/15 14:26:26 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_2d_memory(int **array, int height)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
	free(array);
}
char	*gnl_remove_trailing_chars(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' '))
	{
		line[len - 1] = '\0';
		len--;
	}
	return (line);
}

void	reset_gnl(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
