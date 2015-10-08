/*
 *概要：
 *	overallWorkTime.js
 *機能説明：
 *	勤務時間表の検索フォームの空白チェックと不正な値の入力チェック、
 *	制限内に収まっているかをチェックする
 *	値が不正の場合、処理を行わずダイアログを表示する。
 *備考：
 *	作成日)	2015/9/03
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){

	$('#display').click(function(){

		//検索フォームのラジオボタンが年次を選択した時の処理
		if($("input[name='work']:checked").val() == "year"){

			$("input[name='extend']").val($("select[name='year']").val());

		}

		//検索フォームのラジオボタンが月次を選択した時の処理
		if($("input[name='work']:checked").val() == "month"){

			$("input[name='extend']").val($("input[name='month']").val());

			//空白チェック
			if($("input[name='month']").val().length == 0){

				alert("月次が入力されていません！");
				return false;

			}

			//正規表現のチェック
			if(!$("input[name='month']").val().match(/^\d{4}-[01]\d$/)){

				alert("数字と-以外の文字が入力されています！");
				return false;

			}

			//取得した日付の区切りを " - " から " / " に変更
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

		//検索フォームのラジオボタンが期間を選択した時の処理
		if($("input[name='work']:checked").val() == "period"){

			var period = $("input[name='startDay']").val() + ","
						+ $("input[name='endDay']").val();

			$("input[name='extend']").val(period);

			var errArray = new Array();

			//空白チェック
			if($("input[name='startDay']").val().length == 0){

				errArray[0] = "開始日が入力されていません！";

			//正規表現のチェック
			}else if(!$("input[name='startDay']").val().match(/^\d{4}-[01]\d$/)){

				errArray[0] = "開始日のフォームに数字と-以外の文字が入力されています！";

			}

			//空白チェック
			if($("input[name='endDay']").val().length == 0){

				errArray[1] = "終了日が入力されていません！";

			//正規表現のチェック
			}else if(!$("input[name='endDay']").val().match(/^\d{4}-[01]\d$/)){

				errArray[1] = "終了日のフォームに数字と-以外の文字が入力されています！";

			}

			if(errArray.length != 0){

				alert(errArray.join("\n"));
				return false;

			}

			//取得した日付の区切りを " - " から " / " に変更
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

//検索フォームを動的に切り替える
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
