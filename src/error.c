/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:17 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/09 16:49:03 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_error_and_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	put_invalid_file(const char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	handle_invalid_file(char *filename)
{
	int	fd;
	int	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	if (read(fd, buf, 1) < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
