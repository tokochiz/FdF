/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/15 14:26:18 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	handle_read_error(t_data *data, int row, const char *error_message)
{
	free_2d_memory(data->map.height_map, row + 1);
	free_2d_memory(data->map.color_map, row + 1);
	put_error_and_exit(error_message);
}

void	allocate_row_memory(t_data *data, int row)
{
	data->map.height_map[row] = (int *)malloc(sizeof(int) * data->map.width);
	data->map.color_map[row] = (int *)malloc(sizeof(int) * data->map.width);
	if (data->map.height_map[row] == NULL || data->map.color_map[row] == NULL)
	{
		handle_read_error(data, row, ERR_MALLOC);
	}
}

void	read_map_from_file(char *filename, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	reset_gnl(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error_and_exit(ERR_FILE);
	i = 0;
	while (i < data->map.height)
	{
		allocate_row_memory(data, i);
		line = gnl_remove_trailing_chars(fd);
		if (line == NULL)
			handle_read_error(data, i, ERR_FILE);
		if (data->map.width != get_width_from_line(line))
		{
			free(line);
			handle_read_error(data, i, ERR_FILE);
		}
		fill_map(i, line, data);
		free(line);
		i++;
	}
	data->map.height_map[i] = NULL;
}

void	allocate_map_memory(t_data *data)
{
	data->map.height_map = (int **)malloc(sizeof(int *) * (data->map.height
			+ 1));
	data->map.color_map = (int **)malloc(sizeof(int *) * (data->map.height
			+ 1));
	if (data->map.height_map == NULL || data->map.color_map == NULL)
	{
		if (data->map.height_map != NULL)
			free(data->map.height_map);
		if (data->map.color_map != NULL)
			free(data->map.color_map);
		put_error_and_exit(ERR_MALLOC);
	}
}

void	parse_file(char *filename, t_data *data)
{
	data->map.width = get_width(filename);
	data->map.height = get_height(filename);
	allocate_map_memory(data);
	read_map_from_file(filename, data);
}
