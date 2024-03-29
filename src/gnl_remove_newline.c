/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_remove_newline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:49:45 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/29 18:23:24 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*gnl_remove_newline(int fd)
{
	char	*line;
	int		len;

	// char	*next_line;
	// char	*new_line;
	line = get_next_line(fd);
	printf("****<gnl remove newline> : [%s]\n", line);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' '))
	{
		line[len - 1] = '\0';
		len--;
	}
	if (len == 0)
	{
		free(line);
		return (gnl_remove_newline(fd));
	}

// }

// printf("********<gnl rempve>line : \n|%s|\n", line);
// next_line = get_next_line(fd);
// if (next_line == NULL)
// {
// 	if (line[len - 1] != '\n')
// 	{
// 		new_line = ft_strjoin(line, "\n");
// 		free(line);
// 		line = new_line;
// 	}
// }
// else
// {
// 	free(next_line);
// }
return (line);
}
