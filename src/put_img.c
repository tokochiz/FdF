/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:59:55 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/13 23:18:48 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_image(t_data *data)
{
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	// mlx_get_data_addr()作成されたイメージに関する情報を返すので、ユーザーは後でイメージを変更できます。
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
		&data->mlx.line_length, &data->mlx.endian);
	printf("Bits per pixel: %d\n", data->mlx.bits_per_pixel);
	printf("Line length: %d\n", data->mlx.line_length);
	printf("Endian: %d\n", data->mlx.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x
		* (data->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
