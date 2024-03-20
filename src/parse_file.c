/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:53:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/20 23:17:36 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO : 空白とタブの両方をトークンの区切りとして扱うカスタムの分割関数を作る
char **split_line(char const *s)
{
	char line;
	// 入力文字列sを解析して、トークンを抽出して、それらのトークンの配列を返す
	y = 0;
	while(p)
	{

	}
}
int get_width(int fd)
{
	char *line;
	int width;

	line = get_next_line(fd);
	width = 
}

int check_file_path(char *filepath)
{
	
}

void parse_file(char *file_path, t_map map)
{
	int fd;
	char *line;
	char **parts;
	
	fd = open(file_path, O_RDONLY);
	if(fd < 0 || check_file_path(file_path)) // TODO : file_pathが有効かどうかを判別する
		put_error(ERR_FILE);
	
	// 横幅を取得する
	map->width = get_width(fd);
	// 高さを取得する 
	map->height = get_height(file_path);
	// 取得した高さ情報によって、マロックで領域を確保する
	map->map_area = (int **)malloc(sizeof(int) map->height + 1))
	// 各地点に対応する色情報格納するための領域
	
　 //  高さ
	while()
	{
		// TODO: 1行ごとに、ファイルから行を読み込んで、それを格納する
		parts = split_line(line);
		free(parts);
	}
	close(fd);
}	