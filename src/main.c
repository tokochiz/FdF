/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/13 19:24:58 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <libc.h>

void	set_offset(t_data *data)
{
	data->view.offset_x = (WIN_WIDTH - (data->map.width * data->view.scale)) / 2;
	data->view.offset_y = (WIN_HEIGHT - (data->map.height * data->view.scale))
		/ 2;
}

// void	set_scale(t_data *data)
// {
// 	int		max_l;
// 	float	scale_x;
// 	float	scale_y;

// 	if (data->map.height < data->map.width)
// 		max_l = data->map.width;
// 	else
// 		max_l = data->map.height;
// 	if (max_l < 100)
// 	{
// 		data->view.scale = 25;
// 	}
// 	else
// 	{
// 		scale_x = (float)WIN_WIDTH / (float)data->map.width;
// 		scale_y = (float)WIN_HEIGHT / (float)data->map.height;
// 		if (scale_x < scale_y)
// 			data->view.scale = scale_x;
// 		else
// 			data->view.scale = scale_y;
// 		if (data->view.scale < 1)
// 			data->view.scale = 1;
// 	}
// }

void	initialize(t_data *data)
{
	data->point.center_x = WIN_WIDTH / 2;
	data->point.center_y = WIN_HEIGHT / 2;
	data->point.p = 1;
	data->view.depth = 1;
	data->view.angle_x = 0.523599;
	data->view.angle_y = 0.523599;
	data->view.offset_x = 0;
	data->view.offset_y = 0;
	data->view.scale =  30;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
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
	parse_file(argv[1], &data);
	initialize(&data);
	//set_scale(&data);
	set_offset(&data);
	draw(&data);
	mlx_key_hook(data.win, press, &data);
	mlx_loop(data.mlx);
	return (0);
}
