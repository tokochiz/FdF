/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:49:42 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/13 21:48:25 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	calc_scale(double min_x, double max_x, double min_y, double max_y)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = WIN_WIDTH / (max_x - min_x);
	scale_y = WIN_HEIGHT / (max_y - min_y);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

void	find_min_max_iso(t_data *data, double *min_x, double *max_x,
		double *min_y, double *max_y)
{
	int		y;
	int		x;
	double	iso_x;
	double	iso_y;

	*min_x = 0;
	*max_x = 0;
	*min_y = 0;
	*max_y = 0;
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
			if (iso_x < *min_x)
				*min_x = iso_x;
			if (iso_x > *max_x)
				*max_x = iso_x;
			if (iso_y < *min_y)
				*min_y = iso_y;
			if (iso_y < *max_y)
				*max_y = iso_y;
			x++;
		}
		y++;
	}
}

void	set_scale(t_data *data)
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	scale;

	find_min_max_iso(data, &min_x, &max_x, &min_y, &max_y);
	scale = calc_scale(min_x, max_x, min_y, max_y);
	if (scale < 1)
		scale = 1;
	data->view.scale = scale;
	printf("Calculated scale: %f\n", data->view.scale);
}
