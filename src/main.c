/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/07 15:54:46 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int check_argv(int argc, char *argv[])
{
	if (argc != 2)
		return (0); // put error?
	
}

// TODO : 空白とタブの両方をトークンの区切りとして扱うカスタムの分割関数を作る
char **split_line(char const *s)
{
	char line;
	// 入力文字列sを解析して、トークンを抽出して、それらのトークンの配列を返す
	y = 0;
	while(p)
	
	
}

void parse_file_and_extract_data(char *file_path, t_point point)
{
	int fd;
	char *line;
	char **parts;
	
	fd = open(file_path, O_RDONLY);
	if(fd < 0 || check_file_path(file_path)) // TODO : file_pathが有効かどうかを判別する
		put_error(ERR_FILE);
	
	// 横幅を取得する
	get_width(file_path);
	// 高さを取得する 
	get_height(file_path);
	// 取得した高さ情報によって、マロックで領域を確保する
	
	// 各地点に対応する色情報格納するための領域
	//
	
　 //  高さ
	while()
	{
		// TODO: 1行ごとに、ファイルから行を読み込んで、それを格納する
		parts = split_line(line);
		free(parts);
	}
	close(fd);
}	


int	main(int argc, char *argv[])
{	
	t_point point;
	// TODO コマンドライん引数の検証をする
	check_argv(argc, argv);

	// TODO マップファイルの形式や内容を検証する　破損していないか、正しい形かチェック
	check_map(argv[1]); 
	// TODO マップの読み込みをして、構造体に格納する
	// TODO 二次元配列に対応する行列に突っ込む　GNL, split, atoi 使う
	parse_file_and_extract_data(argv[1], point);
	
	// TODO 読み込んだ点データを等角投影に変換する　→３D空間の点が、２D表示上で表現
	
	// TODO ライブラリの初期設定する
	// TODO 画像を描画する　→点を結んで線を描画する
	// TODO ユーザの入力を処理する→ズームイン、アウト
	// TODO minilibXのイベントループを開始して、ウィンドウが開いている間監視してる　
}