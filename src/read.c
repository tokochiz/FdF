/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/21 19:29:15 by  ctokoyod        ###   ########.fr       */
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

int	get_width_from_file(char *filename)
{
	int		width;
	int		fd;
	char	*line;
	char	*split_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		put_error_and_exit(ERR_FILE);
	}
	split_line = ft_split(line, ' ');
	free(line);
	close(fd);
	if (split_line == NULL)
		put_error_and_exit(ERR_MALLOC);
	width = 0;
	while (split_line[width])
		width++;
	free_line(split_line);
	return (width);
}

int	get_width_from_line(char *filename)
{
	int width;
	int fd;
	char *line;
	char **split_line;
	int i;

	split_line = ft_split(filename, ' ');

	if (split_line == NULL)
		put_error_and_exit(ERR_MALLOC);

	width = 0;
	while (split_line[width])
		width++;
	free_line(split_line);
	return (width);
}