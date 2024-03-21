/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/21 19:29:29 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_map(int *nums, int *color, char *line)
{
	char **
}

int	handle_invalid_file(char *filename)
{
	int	fd;
	int	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	if (read(fd, buf, 1) < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	parse_file(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	// TODO : filenameが有効かどうかを判別する
	if (fd < 0 || handle_invalid_file(filename, 1))
		put_invalid_file(ERR_FILE);
	// 横幅を取得する
	data->map.width = get_width_from_file(filename);
	// 高さを取得する
	data->map.height = get_height(filename);
	// 取得した高さ情報によって、領域を確保する
	data->map.height_map = (int **)malloc(sizeof(int) * data->map.height + 1);
	// 各地点に対応する色情報格納するための領域
	data->map.color_map = (int **)malloc(sizeof(int *) * data->map.height + 1);
	while (i < data->map.height)
	{
		// 高さ[i]に横幅分の領域を確保する
		data->map.height_map[i] = (int *)malloc(sizeof(int) * data->map.width);
		data->map.color_map[i] = (int *)malloc(sizeof(int) * data->map.width);
		// ァイルから1行読み込み、その結果を line 変数に格納
		line = get_next_line(fd);
		// 読み込んだ行の幅が data->map.width と一致するかどうか
		if (data->map.width != get_width_from_line(line))
			put_invalid_file(ERR_FILE);
		// 読み込んだ行のデータを格納　高さと色
		fill_map(data->map.height_map[i], data->map.color_map[i], line);
		free(line);
		i++;
	}
	data->map.height_map[i] = NULL;
}
