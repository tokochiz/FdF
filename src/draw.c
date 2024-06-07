/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/07 23:09:10 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO アイソメトリック投影の計算
void	calc_isometric(double *x, double *y, int z, t_data *data)
{
	double	original_x;
	double	original_y;

	original_x = *x;
	original_y = *y;
	*x = (original_x - original_y) * cos(data->view.angle_x);
	*y = (original_x + original_y) * sin(data->view.angle_y) - z;
}

void	ajust_point(t_data *data)
{
	int	z0;
	int	z1;

	z0 = data->map.height_map[(int)data->point.y0][(int)data->point.x0]
		* data->view.depth;
	z1 = data->map.height_map[(int)data->point.y1][(int)data->point.x1]
		* data->view.depth;
	if (data->point.p == 1)
	{
		data->point.x0 *= data->view.zoom;
		data->point.y0 *= data->view.zoom;
		data->point.x1 *= data->view.zoom;
		data->point.y1 *= data->view.zoom;
		calc_isometric(&data->point.x0, &data->point.y0, z0, data);
		calc_isometric(&data->point.x1, &data->point.y1, z1, data);
	}
	data->point.x0 += data->point.shift_x;
	data->point.x1 += data->point.shift_x;
	data->point.y0 += data->point.shift_y;
	data->point.y1 += data->point.shift_y;
 printf("Shifted: x0=%f, y0=%f, x1=%f, y1=%f\n", data->point.x0,
		data->point.y0, data->point.x1, data->point.y1);
}

void	calc_line_steps(t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	step_x;
	float	step_y;
	float	max_v;

	ajust_point(data);
	delta_x = data->point.x1 - data->point.x0;
	delta_y = data->point.y1 - data->point.y0;
	if (delta_x < 0)
		delta_x = -delta_x;
	if (delta_y < 0)
		delta_y = -delta_y;
	if (delta_x < delta_y)
		max_v = delta_y;
	else
		max_v = delta_x;
	step_x = (data->point.x1 - data->point.x0) / max_v;
	step_y = (data->point.y1 - data->point.y0) / max_v;
	printf("delta_x = %f, delta_y = %f, step_x = %f, step_y = %f\n", delta_x,
		delta_y, step_x, step_y);
	while ((int)(data->point.x0 - data->point.x1) || ((int)(data->point.y0
				- data->point.y1)))
	{
		mlx_pixel_put(data->mlx, data->win, data->point.x0, data->point.y0,
			data->color);
		printf("x0 = %f, y0 = %f\n", data->point.x0, data->point.y0); // デバッグ用出力
		data->point.x0 += step_x;
		data->point.y0 += step_y;
	}
}

void	set_points(t_data *data, int x, int y, int direction)
{
	if (direction == 0)
	{
		data->point.x0 = x;
		data->point.x1 = x + 1;
		data->point.y0 = y;
		data->point.y1 = y;
	}
	if (direction == 1)
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
			printf("Processing point (%d, %d)\n", x, y);
			if (y >= 0 && y < data->map.height && x >= 0 && x < data->map.width)
			{
				data->color = data->map.color_map[x][y];
			if (x < data->map.width - 1)
				set_points(data, x, y, 0);
			if (y < data->map.height - 1)
				set_points(data, x, y, 1);
			}
			x++;
		}
		y++;
	}
}
