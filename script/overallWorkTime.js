$(function(){

	$('#display').click(function(){

		if($("input[name='work']:checked").val() == "month"){

			if($("input[name='month']").val().length == 0){

				alert("月次が入力されていません！");
				return false;

			}

		}

		if($("input[name='work']:checked").val() == "day"){

			if($("input[name='day']").val().length == 0){

				alert("日時が入力されていません！");
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

});

function formChange(){
	radio = document.getElementsByName('work')
	if(radio[0].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formWeek').style.display = "none";
		document.getElementById('formDay').style.display = "none";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[1].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "";
		document.getElementById('formWeek').style.display = "none";
		document.getElementById('formDay').style.display = "none";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[2].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formWeek').style.display = "";
		document.getElementById('formDay').style.display = "none";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[3].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formWeek').style.display = "none";
		document.getElementById('formDay').style.display = "";
		document.getElementById('formPeriod').style.display = "none";

	}else if(radio[4].checked) {

		//フォーム
		document.getElementById('formYear').style.display = "none";
		document.getElementById('formMonth').style.display = "none";
		document.getElementById('formWeek').style.display = "none";
		document.getElementById('formDay').style.display = "none";
		document.getElementById('formPeriod').style.display = "";

	}
}

//オンロードさせ、リロード時に選択を保持
window.onload = formChange;