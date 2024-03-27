/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/27 17:34:03 by  ctokoyod        ###   ########.fr       */
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
			depth_str = ft_substr(split_parts[i], 0, comma_pos
				- split_parts[i]);
			// ft_substr(元の文字列、開始位置、 取り出す長さ);
			depth[i] = ft_atoi(depth_str);
			free(depth_str);
			color[i] = hex_str_to_int(comma_pos + 1);
			/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーー-----ーーーーーーーーーーーーーーー*/
			printf("<fill_map>: depth[%d] = %d, color[%d] = %d\n", i, depth[i],
				i, color[i]);
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
	//int		i;
	int		fd;
	char	*line;
	// data->map の初期化
	data->map.width = 0;
	data->map.height = 0;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
		put_error_and_exit(ERR_FILE);
		
	// 横幅を取得する
	line = gnl_remove_newline(fd);
	if (line == NULL){
		close(fd);
		put_error_and_exit(ERR_FILE);
		}
		
	printf("***line : %s\n", line);
	
	data->map.width = get_width(line);
	free(line);
	// 高さを取得する


	data->map.height = get_height(filename);

	close(fd);
	printf("<parse_file>: width = %d\n", data->map.width);
	printf("<parse_file>: height = %d\n", data->map.height);
	
	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーー-----ーーーーーーーーーーー*/

}
// 	/* ーーーーーーーーーーーーーーーーーーあとで消すーーーーーーーーーーーーーー-----ーーーーーーーー*/
// 	// 取得した高さ情報によって、領域を確保する
// 	data->map.height_map = (int **)malloc(sizeof(int *) * data->map.height + 1);
// 	// 各地点に対応する色情報格納するための領域
// 	data->map.color_map = (int **)malloc(sizeof(int *) * data->map.height + 1);
// 	// ファイル先頭に戻る
// 	close(fd);
// 	fd = open(filename, O_RDONLY);
// 	i = 0;
// 	while (i < data->map.height)
// 	{
// 		// 高さ[i]に横幅分の領域を確保する
// 		data->map.height_map[i] = (int *)malloc(sizeof(int) * data->map.width);
// 		data->map.color_map[i] = (int *)malloc(sizeof(int) * data->map.width);
// 		if (data->map.height_map[i] == NULL || data->map.color_map[i] == NULL)
// 		{
// 			free(data->map.height_map);
// 			free(data->map.color_map);
// 			put_error_and_exit(ERR_MALLOC);
// 		}
// 		//  ファイルから1行読み込み、その結果を line 変数に格納
// 		line = gnl_remove_newline(fd);
// 		if (line == NULL)
// 			put_error_and_exit(ERR_FILE);
// 		// 読み込んだ行の幅が data->map.width と一致するかどうか
// 		if (data->map.width != get_width(line))
// 		{
// 			free(data->map.height_map[i]);
// 			free(data->map.color_map[i]);
// 			put_invalid_file(ERR_FILE);
// 		}
// 		// 読み込んだ行のデータを格納　高さと色
// 		fill_map(data->map.height_map[i], data->map.color_map[i], line);
// 		free(line);
// 		i++;
// 	}
// 	data->map.height_map[i] = NULL;
// }
