/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/07 23:03:03 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	allocate_map_memory(t_data *data)
{
	data->map.height_map = (int **)malloc(sizeof(int *) * (data->map.height
			+ 1));
	data->map.color_map = (int **)malloc(sizeof(int *) * (data->map.height
			+ 1));
}
// allocate 割り当てる　メモリ割り当て　
void	allocate_row_memory(t_data *data, int row)
{
	data->map.height_map[row] = (int *)malloc(sizeof(int) * data->map.width);
	data->map.color_map[row] = (int *)malloc(sizeof(int) * data->map.width);
	if (data->map.height_map[row] == NULL || data->map.color_map[row] == NULL)
	{
		free(data->map.height_map);
		free(data->map.color_map);
		put_error_and_exit(ERR_MALLOC);
	}
}

void	read_map_data(char *filename, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	reset_gnl(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < data->map.height)
	{
		allocate_row_memory(data, i);
		line = gnl_remove_trailing_chars(fd);
		if (line == NULL)
			put_error_and_exit(ERR_FILE);
		if (data->map.width != get_width_from_line(line))
		{
			free(data->map.height_map[i]);
			free(data->map.color_map[i]);
			put_invalid_file(ERR_FILE);
		}
		fill_map(i, line, data);
		free(line);
		i++;
	}
	data->map.height_map[i] = NULL;
}

void	parse_file(char *filename, t_data *data)
{
	data->map.width = get_width(filename);
	data->map.height = get_height(filename);
	allocate_map_memory(data);
	read_map_data(filename, data);
}
