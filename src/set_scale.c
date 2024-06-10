/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:49:42 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/10 22:08:29 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	calc_scale(double max_dist)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = WIN_WIDTH / (max_dist);
	scale_y = WIN_HEIGHT / (max_dist);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < 1)
		scale = 1;
	return (scale);
}

double	euclidean_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

double	calc_max_distance(double iso_x, double iso_y, double current_max,
		t_data *data)
{
	int	d;

	d = euclidean_distance(iso_x, iso_y, data->point.center_x,
		data->point.center_y);
	if (d > current_max)
		return (d);
	return (current_max);
}

void	set_scale(t_data *data)
{
	int		max_dist;
	int		y;
	int		x;
	double	iso_x;
	double	iso_y;

	max_dist = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			iso_x = x;
			iso_y = y;
			calc_isometric(&iso_x, &iso_y, data->map.height_map[y][x]
				* data->view.depth, data);
			max_dist = calc_max_distance(iso_x, iso_y, max_dist, data);
			x++;
		}
		y++;
	}
	data->view.scale = calc_scale(max_dist);
}
