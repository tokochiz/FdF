/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/14 19:17:36 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	press(int key, t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (key == ESC_KEY)
		exit(0);
	draw(data);
	return (0);
}
