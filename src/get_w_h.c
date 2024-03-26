/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_w_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/26 19:35:58 by  ctokoyod        ###   ########.fr       */
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
	int		width;
	char	**split_parts;

	if (line == NULL)
		put_error_and_exit(ERR_FILE);

	
	split_parts = split_str_by_spaces(line);
	width = 0;
	while (split_parts[width])
		width++;
	free_line(split_parts);
	return (width);
}

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 1;
	while ((line = gnl_remove_newline(fd)) != NULL)
	{
		height++;
		free(line);
	}
	return (height);
}
