/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:13:57 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/28 23:40:37 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ファイルの存在と読み取り権限を確認する関数
int	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

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

int	check_map_consistent_width(int fd)
{
	int		width;
	int		current_width;
	int		first_line_width;
	char	*line;

	width = -1;
	current_width = 0;
	first_line_width = -1;
	while ((line = gnl_remove_newline(fd)) != NULL)
	{
		current_width = get_width(line);
		if (width == -1)
		{
			width = current_width;
			first_line_width = current_width;
		}
		else if (width != current_width)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	if (current_width != first_line_width)
		return (1);
	return (0);
}

void	check_file(char *filename)
{
	int fd;
	if (check_file_exists(filename))
		put_invalid_file("Error: File does not exist or cannot be read\n");
	if (check_file_extension(filename))
		put_invalid_file("Error: Invalid file extension\n");
	if (check_map_empty(filename))
		put_invalid_file("Error: Empty map file\n");

	//  TODO : 最後に改行が入っているか入っていないかで動作が異なる　改行がない場合に、エラー判定されてしまうのを治す

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_invalid_file(ERR_OPEN);
	if (check_map_consistent_width(fd))
		put_invalid_file("Error: Inconsistent map width\n");
	close(fd);
	// TODO : 隠しファイルを弾く
}