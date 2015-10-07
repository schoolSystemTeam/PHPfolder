$(function(){

	$('#display').click(function(){
		if($("input[name='work']:checked").val() == "month"){

			$("input[name='extend']").val($("input[name='month']").val());

			if($("input[name='month']").val().length == 0){

				alert("月次が入力されていません！");
				return false;

			}

			if(!$("input[name='month']").val().match(/^\d{4}-[01]\d$/)){

				alert("数字と-以外の文字が入力されています！");
				return false;

			}

			var d = $("input[name='month']").val().replace( /-/g , "/" ) + "/01";
			var formDate = new Date(d);

			var date = new Date();
			var year = date.getFullYear()+1;
			var month = date.getMonth()+1;
			var maxDate = new Date(year,month);

			if(formDate > maxDate){

				alert("検索する月が1年以上先です！");
				return false;

			}

			var minDate = new Date("2000/01/01");

			if(formDate < minDate){

				alert("検索する月が2000年以前です！");
				return false;

			}
		}

		if($("input[name='work']:checked").val() == "period"){

			var period = $("input[name='startDay']").val() + ","
						+ $("input[name='endDay']").val();

			$("input[name='extend']").val(period);

			var errArray = new Array();


			if($("input[name='startDay']").val().length == 0){

				errArray[0] = "開始日が入力されていません！";

			}else if(!$("input[name='startDay']").val().match(/^\d{4}-[01]\d$/)){

				errArray[0] = "開始日のフォームに数字と-以外の文字が入力されています！";

			}

			if($("input[name='endDay']").val().length == 0){

				errArray[1] = "終了日が入力されていません！";

			}else if(!$("input[name='endDay']").val().match(/^\d{4}-[01]\d$/)){

				errArray[1] = "終了日のフォームに数字と-以外の文字が入力されています！";

			}

			if(errArray.length != 0){

				alert(errArray.join("\n"));
				return false;

			}


			var startDay = $("input[name='startDay']").val().replace( /-/g , "/" );
			var endDay = $("input[name='endDay']").val().replace( /-/g , "/" );


			if(startDay > endDay){

				alert("終了期間が開始期間よりも前に設定しています！");
				return false;

			}

			var maxPeriod = new Date(startDay + "/01");
			maxPeriod.setFullYear(maxPeriod.getFullYear()+1);

			var endPeriod = new Date(endDay + "/01");
			if(endPeriod >= maxPeriod){

				alert("検索する期間が1年以上です！");
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
