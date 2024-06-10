/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/10 20:28:01 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_isometric(double *x, double *y, int z, t_data *data)
{
	double	original_x;
	double	original_y;

	original_x = *x;
	original_y = *y;
	*x = round((original_x - original_y) * cos(data->view.angle_x));
	*y = round((original_x + original_y) * sin(data->view.angle_y) - z);
}

void	ajust_point(t_data *data)
{
	int	z0;
	int	z1;

	z0 = data->map.height_map[(int)data->point.y0][(int)data->point.x0]
		* data->view.depth;
	z1 = data->map.height_map[(int)data->point.y1][(int)data->point.x1]
		* data->view.depth;
	calc_isometric(&data->point.x0, &data->point.y0, z0, data);
	calc_isometric(&data->point.x1, &data->point.y1, z1, data);
	data->point.x0 *= data->view.scale;
	data->point.y0 *= data->view.scale;
	data->point.x1 *= data->view.scale;
	data->point.y1 *= data->view.scale;
	data->point.x0 += data->point.center_x;
	data->point.x1 += data->point.center_x;
	data->point.y0 += data->view.offset_y;
	data->point.y1 += data->view.offset_y;
}

void	calc_line_steps(t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	step_x;
	float	step_y;
	float	max_v;

	ajust_point(data);
	delta_x = fabs(data->point.x1 - data->point.x0);
	delta_y = fabs(data->point.y1 - data->point.y0);
	if (delta_x < delta_y)
		max_v = delta_y;
	else
		max_v = delta_x;
	step_x = (data->point.x1 - data->point.x0) / max_v;
	step_y = (data->point.y1 - data->point.y0) / max_v;
	while ((int)(data->point.x0 - data->point.x1) || ((int)(data->point.y0
				- data->point.y1)))
	{
		mlx_pixel_put(data->mlx, data->win, data->point.x0, data->point.y0,
			data->color);
		data->point.x0 += step_x;
		data->point.y0 += step_y;
	}
}

void	set_points(t_data *data, int x, int y, int direction)
{
	if (direction == HORIZONTAL)
	{
		data->point.x0 = x;
		data->point.x1 = x + 1;
		data->point.y0 = y;
		data->point.y1 = y;
	}
	if (direction == VERTICAL)
	{
		data->point.x0 = x;
		data->point.x1 = x;
		data->point.y0 = y;
		data->point.y1 = y + 1;
	}
	calc_line_steps(data);
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	display_info(data);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->color = data->map.color_map[y][x];
			if (x < data->map.width - 1)
				set_points(data, x, y, HORIZONTAL);
			if (y < data->map.height - 1)
				set_points(data, x, y, VERTICAL);
			x++;
		}
		y++;
	}
}
