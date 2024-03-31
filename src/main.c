/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/31 16:36:42 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}

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

	// TODO 読み込んだ点データを等角投影に変換する　→３D空間の点が、２D表示上で表現

	// TODO ライブラリの初期設定する

	// TODO 画像を描画する　→点を結んで線を描画する

	// TODO ユーザの入力を処理する→ズームイン、アウト

	// TODO minilibXのイベントループを開始して、ウィンドウが開いている間監視してる　

	return (0);
}
