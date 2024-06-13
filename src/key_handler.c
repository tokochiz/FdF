/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/13 23:16:10 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	display_info(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx.mlx;
	win = data->mlx.win;
	mlx_string_put(mlx, win, 50, y += 10, TEXT_COLOR, "*** key ***");
	mlx_string_put(mlx, win, 50, y += 20, TEXT_COLOR, "esc: Quit");
}

int	press(int key, t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (key == ESC_KEY)
		exit(0);
	draw(data);
	return (0);
}
