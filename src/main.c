/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/05/28 22:02:13 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fdf");
// }

void	check_argc(int argc)
{
	if (argc != 2)
		put_error_and_exit(ERR_ARGS);
}

int	main(int argc, char *argv[])
{
	t_data data;

	check_argc(argc);	
	check_file(argv[1]);
	parse_file(argv[1], &data);
	
	 data.point.shift_x = WIN_WIDTH / 2;
	 data.point.shift_x = WIN_HEIGHT /2 - 500;
	 //data.point.p = 1;
	 //data.view.depth = 1;
	 data.view.angle_x = 0.523599; // 30度
	 data.view.angle_y = 0.523599; // 30度
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
		
	draw(&data);
	
	//mlx_key_hook();
	mlx_loop(data.mlx);

	return (0);
}
