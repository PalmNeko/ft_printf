
# 必要な関数

* 左寄せ。(空白パディング && 文字数分出力)
* 右寄せ。(空白パディング && 文字数分出力)
* 大文字変換
* 数値文字列にゼロパディング(最小桁数設定可能)
* プラスもしくは空白付与
* 変換指定子解析

# 設計

以下のようにコーディングできるようにする。

print_align(cs, &size,
	add_sign(cs, &size,
		pad_for_num(cs, &size,
			int2str(precision, &size, num))))

print_align(field_width, &size,
	to_upper(type == CS_UPPER, &size,
		add_prefix(sharp, &size,
			pad_for_num(zero, field_width, &size,
				unit2str(precision, &size, num, base)))))

print_align(field_width, &size,
	chr2str(&size, chr))

print_align(cs, &size,
	cut_string(precision, &size, str))

caution: 共通仕様として、生成に失敗した場合、引数の文字列をfreeする。

* add_sign: 符号周りを処理する。+フラグ&&正の値なら+をつける。spaceフラグ&&正の値なら空白をつける。
* pad_for_num: パディング周りを処理する。0フラグが立っていれば、0でパディング。無いなら処理しない。
* print_align: 0フラグが立っていないときに、空白を出力して、左右どちらかに寄せる。-フラグ
* cut_string: 文字列をカットする。(s)
