/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:13:57 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/22 13:34:20 by  ctokoyod        ###   ########.fr       */
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
// ファイルの内容が有効なマップデータであるかを確認する関数
int	check_map_content(char *filename)
{
	int		fd;
	int		width;
	int		current_width;
	char	*line;

	width = -1;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		current_width = get_width_from_line(line);
		if (width == -1)
			width = current_width;
		else if (width != current_width)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}

int	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension != NULL && ft_strcmp(extension, ".fdf") == 0)
		return (1);
	return (0);
}

int	check_map(char *filename)
{
	if (!check_file_exists(filename))
		return (0);
	if (!check_map_content(filename))
		return (0);
	if (!check_file_extension(filename))
		return (0);
	return (1);
}