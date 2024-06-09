Level2 : FdF
課題要件
プログラム名: FdF
提出ファイル: Makefile, *.h, *.c
Makefile: NAME, all, clean, fclean, re
引数: *.fdf形式のファイル
外部関数:
open, close, read, write, malloc, free, perror, strerror, exit
数学ライブラリの全関数（-lm コンパイラオプション, man 3 math）
MiniLibXの全関数
ft_printfおよびコーディングした同等のもの
Libft 許可
概要
MiniLibXを使用して、高さデータを与えられたマップを3Dのシンプルなワイヤーフレームモデルに変換します。

MiniLibX 導入
MiniLibX は、X-Window や Cocoa の知識がなくても、画面内で何かをレンダリングするための最も基本的な操作を実行できる小さなグラフィックライブラリです。いわゆる単純なウィンドウ作成、簡易な描画ツール、画像機能、イベント管理システムを提供します。

プロジェクトの目的
プログラムは等角投影（isometric projection）でモデルを表示する必要があります。地形の座標は、プログラムのパラメータとして渡される.fdfファイルに格納されています。以下に例を示します：

shell
コードをコピーする
$>cat 42.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
$>
各数字は空間内の点を表しています：

横方向の位置はその軸に対応しています。
縦方向の位置はその縦座標に対応しています。
値はその高度を表しています。
使用方法
コンパイル:
Makefileを使用してプロジェクトをコンパイルします。

sh
コードをコピーする
make
実行:
.fdfファイルを指定してプログラムを実行します。

sh
コードをコピーする
./fdf <path_to_fdf_file>
キー操作:

ESCキーを押すとウィンドウが閉じてプログラムが終了します。
機能一覧
ファイルの読み込みと解析:

.fdfファイルからマップデータを読み込みます。
get_next_lineとft_splitを使用してデータを解析し、高度情報を取得します。
データ構造の定義:

マップの幅と高さを格納します。
各ポイントの高度情報を2次元配列に格納します。
アイソメトリック投影の計算:

各ポイントのx, y, z座標をアイソメトリック投影に変換します。
グラフィックの管理:

MiniLibXを使用してウィンドウを作成し、モデルを描画します。
描画にはmlx_pixel_putやmlx_line_putを使用します。
イベントハンドリング:

キーイベントとウィンドウクローズイベントを処理します。
ESCキーでウィンドウを閉じ、プログラムを終了します。
必要なライブラリ
MiniLibX:
小さなグラフィックライブラリで、X-WindowやCocoaを使用して簡単にウィンドウを作成できます。
Libft:
42プロジェクトで作成した標準Cライブラリ関数の再実装。
追加の観点
エラーハンドリング:
ファイルの読み込みやメモリアロケーションに失敗した場合のエラーハンドリングを行います。
拡張機能:
キーボード操作でズームイン・ズームアウト、モデルの回転などの機能を追加することができます。
ドキュメント:
コード内にコメントを追加して、各関数やアルゴリズムの動作を説明します。
テスト:
様々な.fdfファイルを使用してテストを行い、プログラムが正しく動作することを確認します。
