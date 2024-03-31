/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/31 17:56:36 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// 16進数の文字列を整数に変換する
int	hex_str_to_int(char *hex)
{
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			decimal += (hex[len] - '0') * base;
		if (hex[len] >= 'A' && hex[len] <= 'F')
			decimal += (hex[len] - 'A' + 10) * base;
		if (hex[len] >= 'a' && hex[len] <= 'f')
			decimal += (hex[len] - 'a' + 10) * base;
		base *= 16;
		len--;
	}
	return (decimal);
}

char	**split_str_by_spaces(char *str)
{
	char	**split_parts;

	split_parts = ft_split(str, ' ');
	if (split_parts == NULL)
		put_error_and_exit(ERR_MALLOC);
	return (split_parts);
}

void	fill_map(int *depth, int *color, char *line)
{
	char	**split_parts;
	char	*comma_pos;
	char	*depth_str;
	int		i;

	split_parts = split_str_by_spaces(line);
	i = 0;
	while (split_parts[i] != '\0')
	{
		comma_pos = ft_strchr(split_parts[i], ',');
		if (comma_pos != NULL)
		{
			depth_str = ft_substr(split_parts[i], 0, comma_pos
					- split_parts[i]);
			depth[i] = ft_atoi(depth_str);
			free(depth_str);
			color[i] = hex_str_to_int(comma_pos + 1);
		}
		else
		{
			depth[i] = ft_atoi(split_parts[i]);
			color[i] = ft_atoi("0");
		}
		i++;
	}
}

void	allocate_map_memory(t_data *data)
{
	data->map.height_map = (int **)malloc(sizeof(int *) * data->map.height + 1);
	data->map.color_map = (int **)malloc(sizeof(int *) * data->map.height + 1);
}

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
		fill_map(data->map.height_map[i], data->map.color_map[i], line);
		free(line);
		i++;
	}
	data->map.height_map[i] = NULL;
}

void	parse_file(char *filename, t_data *data)
{
	// int		fd;
	// int		i;
	// char	*line;
	data->map.width = get_width(filename);
	data->map.height = get_height(filename);
	
	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/
	printf("<parse_file>: width = %d\n", data->map.width);
	printf("<parse_file>: height = %d\n", data->map.height);
	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/
	allocate_map_memory(data);
	read_map_data(filename, data);
}

