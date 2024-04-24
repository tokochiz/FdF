/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/04/24 21:24:13 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO アイソメトリック投影の計算
void isometric(float *x, float *y, int z, t_data *data)
{
	float original_x;
	float original_y;

	*x = (original_x - original_y) * cos(data->camera.angle_x);
	*y = (original_x + original_y) * sin(data->camera.angle_y) - z;
}

// TODO グラフィック描画の管理

