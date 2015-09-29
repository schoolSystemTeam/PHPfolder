/*
 *概要：
 *	insertEvent.js
 *機能説明：
 *	insertEvent.phtmlのフォームのエラーチェックを行う。
 *備考：
 *	作成日)	2015/9/29
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){

	$("form").submit(function(){

		if (!confirm('設定した情報で登録します。\nよろしいですか？')) {
			return false;
		}

		//各フォームの値を変数に格納
		var eventName = $("input[name='eventName']").val();	//イベント名
		var shortName = $("input[name='shortName']").val();	//イベント略名

		var array = new Array();

		if(jsTrim(eventName).length == 0){

			array[0] = ("セミナー名が入力されていません！");
			$("input[name='eventName']").css("background-color","#FFB6C1");

		}else{
			$("input[name='eventName']").css("background-color","#FFFFFF");

		}

		if(jsTrim(shortName).length == 0){

			array[1] = "セミナー略名が入力されていません！";
			$("input[name='shortName']").css("background-color","#FFB6C1");

		}else{
			$("input[name='shortName']").css("background-color","#FFFFFF");
		}

		//エラーが発生していた場合、エラーメッセージをアラートする。
		if(array.length != 0){
			alert(array.join("\n"));
			return false;
		}

		// 前後スペース削除(全角半角対応)

		function jsTrim( val ) {

			var ret = val;

			ret = ret.replace( /^[\s]*/, "" );

			ret = ret.replace( /[\s]*$/, "" );

			return ret;

		}

	});

});