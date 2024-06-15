/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/15 15:41:56 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <libc.h>

void	set_offset(t_data *data)
{
	double	map_width;
	double	map_height;

	find_min_max_iso(data);
	map_width = (data->map.max_x - data->map.min_x) * data->view.scale;
	map_height = (data->map.max_y - data->map.min_y) * data->view.scale;
	data->view.offset_x = (((WIN_WIDTH - map_width) / 2)
			- (data->map.min_x * data->view.scale));
	data->view.offset_y = (((WIN_HEIGHT - map_height) / 2)
			- (data->map.min_y * data->view.scale));
}

void	initialize(t_data *data)
{
	data->point.center_x = WIN_WIDTH / 2;
	data->point.center_y = WIN_HEIGHT / 2;
	data->point.p = 1;
	data->view.depth = 1;
	data->view.angle_x = ANGLE_30;
	data->view.angle_y = ANGLE_30;
	data->view.offset_x = 0;
	data->view.offset_y = 0;
	data->view.scale = 1;
}

void	check_argc(int argc)
{
	if (argc != 2)
		put_error_and_exit(ERR_ARGS);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_argc(argc);
	check_file(argv[1]);
	initialize(&data);
	init_image(&data);
	parse_file(argv[1], &data);
	set_scale(&data);
	set_offset(&data);
	draw(&data);
	mlx_key_hook(data.mlx.win, press, &data);
	mlx_hook(data.mlx.win, DESTROY_NOTIFY, 1L << 17, close_window, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
