/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/05/07 20:42:09 by  ctokoyod        ###   ########.fr       */
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
	// data->view.shift_x = WIN_WIDTH / 2;
	// data->view.shift_x = WIN_HEIGHT /2;
	// data->view.angle_x = 0.523599; // 30度
	// data->view.angle_y = 0.523599; // 30度
	
	check_argc(argc);	
	check_file(argv[1]);
	parse_file(argv[1], &data);

 //	minilibx の初期化
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
		
	// TODO 画像を描画する　→点を結んで線を描画する
	draw(&data);
	
	// mlx_key_hook();
	
	// TODO minilibXのイベントループを開始して、ウィンドウが開いている間監視してる　
	mlx_loop(data.mlx);

	return (0);
}
