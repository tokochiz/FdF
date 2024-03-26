/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:13:57 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/26 19:09:26 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ファイルの存在と読み取り権限を確認する関数
int	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_file_extension(char *filename)
{
	char	*extension;
	char *last_slash;
	char	len;

	// TODO: .fdf以外の拡張子の時、かつ.fdfのみの時を弾く
	last_slash = ft_strrchr(filename, '/');
	if(last_slash != NULL)
	{
		filename = last_slash + 1;
	}
	extension = ft_strrchr(filename, '.');
	last_slash = ft_strrchr(filename, '/');
	len = ft_strlen(filename);
	if (extension == NULL || ft_strncmp(extension, ".fdf", 4) != 0 || len == 4)
		return (0);
	return (1);
}

int	check_map_empty(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) > 0)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	check_map_consistent_width(char *filename)
{
	int		fd;
	int		width;
	int		current_width;
	char	*line;

	fd = open(filename, O_RDONLY);
	width = -1;
	current_width = 0;
	while ((line = get_next_line(fd)) != NULL)
	//while ((line = gnl_remove_newline(fd)) != NULL)
	{
		printf("1line : %s\n", line);
		printf("2width : %d\n", width);
		current_width = get_width(line);
		printf("3current_width %d\n", current_width);
		if (width == -1)
			width = current_width;
		else if (width != current_width)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		printf("4test %d\n", width);
	}
	close(fd);
	return (1);
}

void	check_file(char *filename)
{
	if (!check_file_exists(filename))
		put_invalid_file("Error: File does not exist or cannot be read\n");
	if (!check_file_extension(filename))
		put_invalid_file("Error: Invalid file extension\n");
	if (!check_map_empty(filename))
		put_invalid_file("Error: Empty map file\n");

	//  TODO : 最後に改行が入っているか入っていないかで動作が異なる　改行がない場合に、エラー判定されてしまうのを治す
	if (!check_map_consistent_width(filename))
		put_invalid_file("Error: Inconsistent map width\n");
	// TODO : 隠しファイルを弾く
	
}