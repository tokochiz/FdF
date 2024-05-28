/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/05/28 22:04:37 by  ctokoyod        ###   ########.fr       */
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
	// デバッグ用のログ出力
    printf("Isometric: original_x=%f, original_y=%f, x=%f, y=%f, z=%d\n", original_x, original_y, *x, *y, z);
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
		calc_isometric(&data->point.x0, &data->point.y0, z0, data);
		calc_isometric(&data->point.x1, &data->point.y1, z1, data);
	}
	data->point.x0 += data->point.shift_x;
	data->point.x1 += data->point.shift_x;
	data->point.y0 += data->point.shift_y;
	data->point.y1 += data->point.shift_y;
}

void	calc_line_steps(t_data *data)
{
	float	step_x;
	float	step_y;
	float	max_v;

	ajust_point(data);
	step_x = data->point.x1 - data->point.x0;
	step_y = data->point.y1 - data->point.y0;
	if (step_x < 0)
		step_x = step_x * -1;
	if (step_y < 0)
		step_y = step_y * -1;
	if (step_x < step_y)
	{
		max_v = step_y;
	}
	else
	{
		max_v = step_x;
	}
	step_x /= max_v;
	step_y /= max_v;
	while (((int)data->point.x0 - data->point.x1) || ((int)data->point.y0
			- data->point.y1))
	{
		mlx_pixel_put(data->mlx, data->win, data->point.x0, data->point.y0,
			data->color);
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
		if (direction == 1)
		{
			data->point.x0 = x;
			data->point.x1 = x;
			data->point.y0 = y;
			data->point.y1 = y + 1;
		}
		calc_line_steps(data);
	}
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
			data->color = data->map.color_map[x][y];
			if (x < data->map.width - 1)
				set_points(data, x, y, 0);
			if (y < data->map.height - 1)
				set_points(data, x, y, 1);
			x++;
		}
		y++;
	}
}
