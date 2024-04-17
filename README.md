# Level2 : FdF

## 課題要件
- プログラム名 : FdF
- 提出ファイル : Makefile, *.h, *.c
- Makefile NAME, all, clean, fclean, re
- 引数 *.fdf形式のファイル
- 外部関数
	- open, close, read, write, malloc, free, perror, strerror, exit
	- 数学ライブラリの全関数（-lm コンパイラオプション, man man 3 math）
	- MiniLibXの全関数
	- ft_printfおよびあなたがコーディングした同等のもの
	- Libft 許可

## 概要
- MiniLibXを使用して、高さデータを与えられたマップを3Dのシンプルなワイヤーフレームモデルに変換する。

### MiniLibX 導入
- MiniLibX は、X-Window や Cocoa の知識がなくても、画面内で何かをレンダリングするための最も基本的な操作を実行できる小さなグラフィックライブラリです。いわゆる単純なウィンドウ作成、疑わしい描画ツール、中途半端な画像機能、そして奇妙なイベント管理システムを提供します。

### .fdfファイル仕様
- .fdfファイルは以下の形式で構成されています：
	- 各行は、スペースまたはタブで区切られた複数の要素で構成されます。（末尾のスペースまたはタブも許容されます）
 	- 最初の要素は高さを表します。必須要素です。整数である必要があります。
	- 2番目の要素は色を表します。オプションです。0xで始まる正の16進数である必要があります。
	- 各行の要素数は一定で、明確な長方形の形状を形成します。
	- ファイルの最後には改行文字（またはスペースやタブ）が必須です。
