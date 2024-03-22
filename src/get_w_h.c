/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/22 13:18:32 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
}

char	**split_str_by_spaces(char *str)
{
	char	**split_parts;

	split_parts = ft_split(str, ' ');
	if (split_parts == NULL)
		put_error_and_exit(ERR_MALLOC);
	return (split_parts);
}

int	get_width_from_file(char *filename)
{
	int		width;
	int		fd;
	char	*line;
	char	**split_parts;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		put_error_and_exit(ERR_FILE);
	}
	split_parts = split_str_by_spaces(line);
	free(line);
	close(fd);
	width = 0;
	while (split_parts[width])
		width++;
	free_line(split_parts);
	return (width);
}

int	get_width_from_line(char *filename)
{
	int		width;
	int		fd;
	char	*line;
	char	**split_parts;
	int		i;

	split_parts = split_str_by_spaces(filename);
	width = 0;
	while (split_parts[width])
		width++;
	free_line(split_parts);
	return (width);
}

int	get_height(char *filename)
{
	int		height;
	int		fd;
	char	**line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
