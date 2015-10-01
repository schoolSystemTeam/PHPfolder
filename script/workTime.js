$(function(){

	$('#display').click(function(){

		if($("input[name='work']:checked").val() == "month"){

			if($("input[name='month']").val().length == 0){

				alert("月次が入力されていません！");
				return false;

			}

			var date = $("input[name='month']").val();
			var date2 = new Date();
			var year = date2.getFullYear()+1;
			var month = date2.getMonth()+1;
			var maxDate = year + "-" + month;
			if(date > maxDate){
				alert("検索する月が1年以上先です！");
				return false;

			}

			var minDate = new Date(2000,0,1)
			if(date < minDate){

				alert("検索する月が2000年以前です！");
				return false;

			}
		}

		if($("input[name='work']:checked").val() == "period"){

			var errArray = new Array();

			if($("input[name='startDay']").val().length == 0){

				errArray[0] = "開始日が入力されていません！";

			}

			if($("input[name='endDay']").val().length == 0){

				errArray[1] = "終了日が入力されていません！";

			}

			if(errArray.length != 0){

				alert(errArray.join("\n"));
				return false;

			}

		}

	});

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

	//オンロードさせ、リロード時に選択を保持
	window.onload = formChange;

});

function formChange(){
	radio = document.getElementsByName('work')
	if(radio[0].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[1].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[2].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formPeriod').style.display = "";

	}
}

