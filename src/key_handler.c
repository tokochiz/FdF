/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/09 16:48:52 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_info(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx;
	win = data->win;
	mlx_string_put(mlx, win, 50, y += 10, TEXT_COLOR, "*** key ***");
	mlx_string_put(mlx, win, 50, y += 20, TEXT_COLOR, "esc: Quit");
}

int	press(int key, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == 53)
		exit(0);
	draw(data);
	return (0);
}
