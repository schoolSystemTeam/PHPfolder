/*
 *概要：
 *	insertUser.js
 *機能説明：
 *	insertUser.phtmlのフォームのエラーチェックを行う。
 *備考：
 *	作成日)	2015/9/03
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
		var user = $("input[name='userid']").val();					//ユーザーID
		var password = $("input[name='password']").val();			//パスワード
		var checkPass = $("input[name='checkPass']").val();			//パスワード（確認用）
		var name      = $("input[name='name']").val();				//名前
		var colorid   = $('input[name="colorid"]:checked').val();	//選択された表示色

		var array = new Array();

		if(jsTrim(user).length == 0){

			array[0] = ("ユーザー名が入力されていません！");
			$("input[name='userid']").css("background-color","#FFB6C1");

		}else if(user.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[0] = "ユーザー名に不正な文字が入力されています。";
			$("input[name='userid']").css("background-color","#FFB6C1");

		}else{
			$("input[name='userid']").css("background-color","#FFFFFF");

		}

		if(jsTrim(password).length == 0){

			array[1] = "パスワードが入力されていません！";
			$("input[name='password']").css("background-color","#FFB6C1");

		}else if(password.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[1] = "パスワードに不正な文字が入力されています。";
			$("input[name='password']").css("background-color","#FFB6C1");

		}else{
			$("input[name='password']").css("background-color","#FFFFFF");
		}

		if(jsTrim(checkPass).length == 0){
			array[2] = "確認用パスワードが入力されていません！";
			$("input[name='checkPass']").css("background-color","#FFB6C1");

		}else if(checkPass.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[2] = "確認用パスワードに不正な文字が入力されています。";
			$("input[name='checkPass']").css("background-color","#FFB6C1");

		}else if(password != checkPass){

			array[2] = "パスワードと確認パスワードが一致しません！";
			$("input[name='password']").css("background-color","#FFB6C1");
			$("input[name='checkPass']").css("background-color","#FFB6C1");

		}else{
			$("input[name='checkPass']").css("background-color","#FFFFFF");
		}

		if(jsTrim(name).length == 0){

			array[3] = "名前が入力されていません！";
			$("input[name='name']").css("background-color","#FFB6C1");

		}else{
			$("input[name='name']").css("background-color","#FFFFFF");
		}

		if(typeof colorid == "undefined")
		{
			array[4] = "表示色が選択されていません！";

		}else{

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