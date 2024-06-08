/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/08 21:11:00 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fdf");
// }

void set_zoom(t_data *data)
{
	if(data.map.height < 100)
	data.view.zoom = 10;
	if (data.map.height != 0)
	{
		data.view.zoom = 1500.0 / data.map.height;
		if (data.view.zoom < 1)
			data.view.zoom = 3;
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
	set_zoom();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	draw(&data);
	// mlx_key_hook();
	mlx_loop(data.mlx);
	return (0);
}
