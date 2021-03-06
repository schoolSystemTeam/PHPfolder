/*
 *概要：
 *	loginForm.js
 *機能説明：
 *	login.phpのログインフォームの空白チェックと不正な値の入力チェックを
 *	行う。
 *	値が不正の場合、違った値のフォームの色を変更する。
 *備考：
 *	作成日)	2015/9/03
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){
	$("form").submit(function(){	//ログインボタン押下時

		//各変数にユーザー入力値を挿入
		var user = $("input[name='userid']").val();			//ユーザーID
		var password = $("input[name='password']").val();	//パスワード

		//エラー処理格納用変数
		var array = new Array();

		//ユーザーIDエラーチェック
		if(jsTrim(user).length == 0){

			array[0] = "ログイン名が入力されていません！";
			document.loginForm.userid.style.backgroundColor = "#FFB6C1";

		}else if(user.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[0] = "ログイン名に不正な文字が入力されています。";
			document.loginForm.userid.style.backgroundColor = "#FFB6C1";

		}else{
			document.loginForm.userid.style.backgroundColor = "#FFFFFF";
		}

		//パスワードエラーチェック
		if(jsTrim(password).length == 0){
			array[1] = "パスワードが入力されていません！";
			document.loginForm.password.style.backgroundColor = "#FFB6C1";

		}else if(password.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[1] = "パスワードに不正な文字が入力されています。";
			document.loginForm.password.style.backgroundColor = "#FFB6C1";

		}else{
			document.loginForm.password.style.backgroundColor = "#FFFFFF";
		}

		//エラーがあるかどうかを確認
		if(array.length != 0){

			//エラー発生時メッセージをダイアログで表示し、処理を中断する
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