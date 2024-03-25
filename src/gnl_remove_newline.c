/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_remove_newline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:49:45 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/25 18:22:35 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char *gnl_remove_newline(int fd)
{
	char *line;
	int len;

	line = get_next_line(fd);
	if(line == NULL)
		return NULL;
	len = ft_strlen(line);
	if(len > 0 && line[len -1] == '\n')
	line[len - 1] = '\0';
	return (line);
}


