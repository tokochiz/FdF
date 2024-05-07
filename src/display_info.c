/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/05/07 21:46:45 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void display_info(t_data *data)
{
	int y;
	void *mlx;
	void *win;

	y=0;
	mlx = data->mlx;
	win = data->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");	
}