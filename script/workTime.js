/*
 *概要：
 *	workTime.js
 *機能説明：
 *	勤務時間表の各種ボタンとログアウトリンクを
 *	押下したとき、確認を促すダイアログボックスを表示させる。
 *備考：
 *	作成日)	2015/9/03
 *	作成者)	鈴木一紘
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){

	//ログアウトリンクを押下
	$('a[href="../login/login.php"]').click(function() {
		if (!confirm('ログアウトします。\nよろしいですか？')) {
			return false;
		}
	});


	//「excelに出力」ボタンを押下
	$('button.exportExcel').click(function() {
		if (!confirm('excelに出力します。\nよろしいですか？')) {
			return false;
		}
	});

	//「PDFに出力」ボタンを押下
	$('button.exportPDF').click(function() {
		if (!confirm('PDFに出力します。\nよろしいですか？')) {
			return false;
		}
	});

	//勤務時間表(個人)画面の「保存」ボタンを押下
	$('button#record').click(function() {
		if (!confirm('上記の内容で登録します。\nよろしいですか？')) {
			return false;
		}
	});

});


