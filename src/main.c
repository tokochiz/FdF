/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/20 22:33:18 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int check_argv(int argc, char *argv[])
{
	if (argc != 2)
		put_error_and_exit(ERR_INVALID);
}

int	main(int argc, char *argv[])
{	
	t_map map;
	t_point ptr;
	
	// TODO コマンドライん引数の検証をする
	check_argv(argc, argv);

	// TODO マップファイルの形式や内容を検証する　破損していないか、正しい形かチェック
	check_map(argv[1]); 
	
	// TODO マップの読み込みをして、構造体に格納する
	// TODO 二次元配列に対応する行列に突っ込む　GNL, split, atoi 使う
	parse_file(argv[1], map);
	
	// TODO 読み込んだ点データを等角投影に変換する　→３D空間の点が、２D表示上で表現
	
	// TODO ライブラリの初期設定する

	// TODO 画像を描画する　→点を結んで線を描画する

	// TODO ユーザの入力を処理する→ズームイン、アウト

	// TODO minilibXのイベントループを開始して、ウィンドウが開いている間監視してる　
	
}