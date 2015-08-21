$(function(){
	$('a[href="login.html"]').click(function() {
		if (!confirm('ログアウトします。\nよろしいですか？')) {
			return false;
		}
	});

	$('button.exportExcel').click(function() {
		if (!confirm('excelに出力します。\nよろしいですか？')) {
			return false;
		}
	});

	$('button.exportPDF').click(function() {
		if (!confirm('PDFに出力します。\nよろしいですか？')) {
			return false;
		}
	});

	$('button#record').click(function() {
		if (!confirm('上記の内容で登録します。\nよろしいですか？')) {
			return false;
		}
	});
});