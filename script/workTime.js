$(function(){
	$('a[href="../login/login.php"]').click(function() {
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

	$('input[name=work]').change(function () {
		if ($('input[name=work]:checked').val() == 'year') {
			$('#formYear').show();
	        $('#formMonth').hide();
	    }

		if($('input[name=work]:checked').val() == 'month') {
			$('#formYear').hide();
	        $('#formMonth').show();
	    }
	});
});
