/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/22 12:51:25 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			// depth_len = comma_pos - split_parts[i];// commaの位置ー文字列の先頭の位置の差
			depth_str = ft_substr(split_parts[i], 0, comma_pos - split_parts[i]); 
			// ft_substr(元の文字列、開始位置、 取り出す長さ);
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

void	parse_file(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	// TODO : filenameが有効かどうかを判別する
	if (fd < 0 || handle_invalid_file(filename))
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
		//  ファイルから1行読み込み、その結果を line 変数に格納
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
