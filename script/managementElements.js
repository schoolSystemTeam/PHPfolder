/*
 *概要：
 *	managementElements.js
 *機能説明：
 *	クリックで内部を表示するアコーディオン機能を提供する。
 *	#acMenu内のdtをクリックするとアコーディオンメニューの表示,非表示
 *	を切り替えることができる。
 *備考：
 *	作成日)	2015/9/01
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){

	//カラー一覧変更機能
	$(".c_update").click(function(){

		//hiddenに判別用のパラメータを格納
		$('.execute').val($(this).data('execute'));

		//変数にindex番号を格納
		var index = $(this).data('index');

		//テキストボックスの内容を取得し,変数に格納する
		var id = '#c_name'+index;

		//変数を使用してエラーがあったかどうかを判別
		if(emptyCheck(id))
		{
			alert("テキストが未入力です！色名を入力して下さい！");
			return false;
		}

		if (!confirm('この色を変更します。\nよろしいですか？')) {
			return false;
		}

	});

	//カラー一覧削除機能
	$(".c_delete").click(function(){

		$('.execute').val($(this).data('execute'));

		if (!confirm('この情報を削除します。\nよろしいですか？')) {
			return false;
		}

	});

	//カラー登録機能
	$("#c_insert").click(function(){

		//変数にindex番号を格納
		var index = $(this).data('index');

		//変数を使用してエラーがあったかどうかを判別
		if(emptyCheck("#insertColor"))
		{
			alert("テキストが未入力です！色名を入力して下さい！");
			return false;
		}

		if (!confirm('この情報を登録します。\nよろしいですか？')) {
			return false;
		}

	});


	//役割一覧変更機能
	$(".p_update").click(function(){

		$('.execute').val($(this).data('execute'));

		//変数にindex番号を格納
		var index = $(this).data('index');

		//テキストボックスの内容を取得し,変数に格納する
		var id = '#p_name'+index;

		//変数を使用してエラーがあったかどうかを判別
		if(emptyCheck(id))
		{
			alert("テキストが未入力です！役割名を入力して下さい！");
			return false;
		}

		if (!confirm('この内容で情報を変更します。\nよろしいですか？')) {
			return false;
		}

	});

	//役割一覧削除機能
	$(".p_delete").click(function(){

		$('.execute').val($(this).data('execute'));

		if (!confirm('この情報を削除します。\nよろしいですか？')) {
			return false;
		}
	});


	//役割登録機能
	$("#p_insert").click(function(){

		//変数を使用してエラーがあったかどうかを判別
		if(emptyCheck("#insertPosition"))
		{
			alert("テキストが未入力です！役割名を入力して下さい！");
			return false;
		}

		if (!confirm('この情報を登録します。\nよろしいですか？')) {
			return false;
		}

	});


	// 前後スペース削除(全角半角対応)
	function jsTrim( val ) {

		var ret = val;

		ret = ret.replace( /^[\s]*/, "" );

		ret = ret.replace( /[\s]*$/, "" );

		return ret;

	}


	/*
	 * テキストの未入力チェックを行う関数。
	 * エラーがあればtrueをなければfalseを返却する。
	 */
	function emptyCheck(id){

		//テキストボックスの内容を取得し,変数に格納する
		var text = $(id).val();

		//エラーチェックを行い、エラーがあればアラートを表示する
		if(jsTrim(text).length == 0){

			$(id).css("background-color","#FFB6C1");
			return true;

		}else{

			$(id).css("background-color","#FFFFFF");
			return false;

		}

	}

});