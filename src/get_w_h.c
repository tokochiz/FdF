/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_w_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/29 18:18:39 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
}
char	**split_str_by_spaces(char *str)
{
	char	**split_parts;

	split_parts = ft_split(str, ' ');
	if (split_parts == NULL)
		put_error_and_exit(ERR_MALLOC);
	return (split_parts);
}

int	get_width(char *line)
{
	int	width;
	int	i;
printf("<+++++++++++++test width [line] : |%s|\n", line);
	if (line == NULL)
		put_error_and_exit(ERR_FILE);
	width = 1;
	i = 0;
	// スペースの場合、widthをインクリメントし、連続するスペースをスキップ
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			width++;
			while (line[i] == ' ')
				i++;
		}
		else
			i++;
	}
	return (width);
}

int	get_height(int fd)
{
	//int		fd;
	int		height;
	char	*line;

	// fd = open(filename, O_RDONLY);
	// if (fd < 0)
	// 	put_error_and_exit(ERR_FILE);
	height = 1;
	 while ((line = gnl_remove_newline(fd)) != NULL)
	//while ((line = get_next_line(fd)) != NULL)
	{
		printf("test height [line] : |%s|\n", line);
		//if (ft_strlen(line) > 1 || line[0] != '\n')
			height++;
		printf("test height [h] ; %d\n", height);
		free(line);
	}
	//close(fd);
	return (height);
}
