/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/08 23:38:24 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fdf");
// }

void	set_zoom(t_data *data)
{
	int		max_l;
	float	zoom_x;
	float	zoom_y;

	if (data->map.height < data->map.width)
		max_l = data->map.width;
	else
		max_l = data->map.height;
	if (max_l < 100)
	{
		data->view.zoom = 25;
	}
	else
	{
		zoom_x = (float)WIN_WIDTH / (float)data->map.width;
		zoom_y = (float)WIN_HEIGHT / (float)data->map.height;
		if (zoom_y < zoom_x)
			data->view.zoom = zoom_x;
		else
			data->view.zoom = zoom_y;
		if (data->view.zoom < 1)
			data->view.zoom = 1;
	}
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
	data.point.shift_x = WIN_WIDTH / 2;
	data.point.shift_y = WIN_HEIGHT / 2;
	data.point.p = 1;
	data.view.depth = 1;
	data.view.angle_x = 0.523599; // 30度
	data.view.angle_y = 0.523599; // 30度
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	set_zoom(&data);
	draw(&data);
	// mlx_key_hook();
	mlx_loop(data.mlx);
	return (0);
}
