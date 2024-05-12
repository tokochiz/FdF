/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:00 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/05/12 19:30:53 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO アイソメトリック投影の計算
void	isometric(int *x, int *y, int z, t_data *data)
{
	int	original_x;
	int	original_y;

	original_x = *x;
	original_y = *y;
	*x = round(cos(data->view.angle_x) * (original_x - original_y));
	*y = round(sin(data->view.angle_y) * (original_x + original_y) - z);
}

// set_points(t_data *data, float *x, float *y, int check)
// {
	
// }

// coordinates  座標
void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	display_info(data);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->color = data->map.color_map[x][y];
			if (x < data->map.width - 1)
			// 	set_points(data, x, y, 0);
			// if (y < data->map.height - 1)
			// 	set_points(data, x, y, 1);
			x++;
		}
		y++;
	}
}

// TODO グラフィック描画の管理
/*
 * 実行フロー
グラフィック描画アプリケーションの一般的な実行フローは次のようになります：

初期設定:
アプリケーションの必要なライブラリと環境を初期化し、必要なデータ構造を準備します。
データ読み込み:
マップデータやテクスチャなど、必要なリソースをファイルシステムやデータベースから読み込みます。
メモリ割り当て:
データの格納と処理のために、適切なメモリ領域を確保します。
投影計算:
3Dデータを2Dスクリーン上での表示に適した形に変換するための計算を行います。
描画処理:
計算された2Dデータを基に、画面に図形やテクスチャを描画します。
イベント処理:
ユーザーからの入力を受け付け、それに応じて画面表示や内部データを更新します。
クリーンアップ:
アプリケーションの終了処理として、開放すべきリソースを適切に解放し、システム状態をクリーンな状態に戻します。
 
*/