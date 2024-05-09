/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/04/27 17:55:12 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_width_from_line(char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			width++;
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
		else
		{
			while (line[i] == ' ' && line[i] != '\0')
				i++;
		}
	}
	return (width);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	reset_gnl(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	line = gnl_remove_trailing_chars(fd);
	width = get_width_from_line(line);
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	reset_gnl(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	height = 0;
	line = gnl_remove_trailing_chars(fd);
	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/
	printf("<get height> line1 : |%s|\n", line);
	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/

	while (line != NULL)
	{
		if (line[0] != '\n' || line[0] != ' ' || line[0] != '\t')
			height++;
		free(line);
		line = gnl_remove_trailing_chars(fd);
		/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/
		printf("<get height> line2 : |%s|\n", line);
	}
	free(line);
	close(fd);
	return (height);
}
