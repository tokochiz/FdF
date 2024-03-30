/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:34:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/30 23:09:41 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_file_extension(char *filename)
{
	char	*extension;
	char	*last_slash;
	char	len;

	// TODO: .fdf以外の拡張子の時、かつ.fdfのみの時を弾く
	last_slash = ft_strrchr(filename, '/');
	if (last_slash != NULL)
	{
		filename = last_slash + 1;
	}
	extension = ft_strrchr(filename, '.');
	last_slash = ft_strrchr(filename, '/');
	len = ft_strlen(filename);
	if (extension == NULL || ft_strncmp(extension, ".fdf", 4) != 0 || len == 4)
		return (1);
	return (0);
}

int	check_map_empty(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (1);
	}
	free(line);
	close(fd);
	return (0);
}

int	check_line_width(char *line, int *width, int *first_line_width)
{
	int	current_width;

	current_width = get_width_from_line(line);
	if (*width == -1)
	{
		*width = current_width;
		*first_line_width = current_width;
	}
	else if (*width != current_width)
		return (1);
	return (0);
}

int	check_map_consistent_width(char *filename)
{
	int		fd;
	int		width;
	int		first_line_width;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
		
	width = -1;
	first_line_width = -1;

	while ((line = gnl_remove_newline(fd)) != NULL)
	{
		if (check_line_width(line, &width, &first_line_width))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	if (width != first_line_width)
		return (1);

	return (0);
}

void	check_file(char *filename)
{
	printf("check 2\n");
	if (check_file_extension(filename))
		put_invalid_file("Error: Invalid file extension\n");

	printf("check 4\n");
		if (check_map_consistent_width(filename))
		put_invalid_file("Error: Inconsistent map width\n");
		
		printf("check 3\n");
	if (check_map_empty(filename))
		put_invalid_file("Error: Empty map file\n");

	printf("check fin\n");
}