$(function(){

	$('#display').click(function(){

		if($("input[name='work']:checked").val() == "month"){

			if($("input[name='month']").val().length == 0){

				alert("月次が入力されていません！");
				return false;

			}

			var date = new Date($("input[name='month']").val());
			var year = date.getFullYear();
			var month = date.getMonth()+1;
			var formDate = year + "/" + month + "/1";

			var date2 = new Date();
			var year2 = date2.getFullYear()+1;
			var month2 = date2.getMonth()+1;
			var maxDate = year2 + "/" + month2 + "/1";


			if(formDate > maxDate){

				alert("検索する月が1年以上先です！");
				return false;

			}

			var minDate = "2000/1/1"
			if(formDate < minDate){

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

			if($("input[name='endDay']").val() > if($("input[name='startDay']").val()){

				errArray[1] = "終了期間が開始期間よりも前に設定しています！";
				return false;

			}

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
