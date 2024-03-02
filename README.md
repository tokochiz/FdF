# Level2 : Pipex

## 課題要件
- プログラム名 : FdF
- 提出ファイル : Makefile, *.h, *.c
- Makefile NAME, all, clean, fclean, re
- 引数 *.fdf形式のファイル
- 外部関数
	-・open, close, read, write, malloc, free, perror, strerror, exit
	-・数学ライブラリの全関数（-lm コンパイラオプション, man man 3 math）
	-・MiniLibXの全関数
	-・ft_printfおよびあなたがコーディングした同等のもの
	-Libft 許可

## 概要
- 高さデータを与えられたマップを読み込み、MiniLibXを使用して3Dのシンプルなワイヤーフレームモデル表現を作成する。

### MiniLibX 導入
- MiniLibX は、X-Window や Cocoa の知識がなくても、画面内で何かをレンダリングするための最も基本的な操作を実行できる小さなグラフィックライブラリです。いわゆる単純なウィンドウ作成、疑わしい描画ツール、中途半端な画像機能、そして奇妙なイベント管理システムを提供します。