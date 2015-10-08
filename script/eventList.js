/*
 *概要：
 *	eventList.js
 *機能説明：
 *	eventList.phtmlのフォームのエラーチェック、及び変更機能,削除機能
 *	変更機能の結果表示ダイアログを行う。
 *備考：
 *	作成日)	2015/9/30
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

jQuery( function() {

	//各変数定義
	var eventid = "";	//旧セミナーID
	var eventName = "";	//旧セミナー名
	var shortName = "";	//旧セミナー略名
	var color = "";		//旧セミナーカラー
	var eventName2 = "";//セミナー名
	var shortName2 = "";//セミナー略名
	var color2 = "";	//セミナーカラー
	var index = "";		//インデックス番号

	//削除ボタン押下時
	$('.delete') . click(function() {

		if (!confirm('このセミナー情報を削除します。\nよろしいですか？')) {
			return false;
		}

	});

	//セミナー変更機能

	jQuery( '.update' ) . click( function() {	//変更ボタン押下時

		//各IDにフォームに現在のデータを入力

		$('#eventNameForm').val($(this).data('eventname'));	//イベント名
		$('#shortNameForm').val($(this).data('shortname'));	//イベント略名
		$('#colorForm').val($(this).data('color'));			//表示色

		//プロパティ変数にも値を代入
		eventid = $(this).data('eventid');		//イベント管理ID
		eventName = $(this).data('eventname');	//イベント名
		shortName = $(this).data('shortname');	//イベント略名
		color = $(this).data('color');			//表示色
		index = $(this).data('index');			//インデックス番号

		//登録フォーム用のダイアログを開く
		jQuery( '#jquery-ui-dialog' ) . dialog( 'open' );
	} );

	//ダイアログ内の設定
	jQuery( '#jquery-ui-dialog' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'変更': function() {

		//セミナー名の空白チェック
		if(jsTrim($('#eventNameForm').val()).length == 0){

			alert("セミナー名が入力されていません！");
			return false;

		}

		//セミナー略名の空白チェック
		if(jsTrim($('#shortNameForm').val()).length == 0){

			alert("セミナー略名が入力されていません！");
			return false;

		}

		if (!confirm('このセミナー情報を変更します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}

		$.ajax({
			type: 'POST',
			url:'',
			data:{
			"eventid": eventid,
			"eventName": $('#eventNameForm').val(),
			"shortName": $('#shortNameForm').val(),
			"color": $('#colorForm').val(),
			"execute": "update"

		},
		success:function(data) {

			//フォームに入力された情報を変数に代入
			eventName2 = $('#eventNameForm').val();
			shortName2 = $('#shortNameForm').val();
			color2 = $('#colorForm').val();

			//表の文章を入れ替える
			$('#eventName'+index).text(eventName2);
			$('#shortName'+index).text(shortName2);
			$('#eventColor'+index).css("background-color",color2);

			//結果表示用のダイアログに文章を挿入する

			//旧イベント名
			$('#oldEventNameDisp').text(eventName);
			//旧イベント略名
			$('#oldShortNameDisp').text(shortName);
			//旧表示色
			$('#oldColorDisp').css("background-color",color);
			//イベント名
			$('#eventNameDisp').text(eventName2);
			//イベント略名
			$('#shortNameDisp').text(shortName2);
			//表示色
			$('#colorDisp').css("background-color",color2);

			//指定のupdate-dataを更新する
			$('#update'+index).data("eventname",eventName2);//イベント名
			$('#update'+index).data("shortname",shortName2);//イベント略名
			$('#update'+index).data("color",color2);//表示色

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

		jQuery( this ) . dialog( 'close' );

		//新たなダイアログを立ち上げる
		jQuery( '#jquery-ui-dialog2' ) . dialog( 'open' );
	},

	'キャンセル': function() {
		jQuery( this ) . dialog( 'close' );
	},
	}
	} );

	//変更結果表示用ダイアログ
	jQuery( '#jquery-ui-dialog2' ) . dialog( {
		autoOpen: false,
		width: 500,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'閉じる': function() {

		jQuery( this ).dialog( 'close' );

	},
	}
	} );


	// 前後スペース削除(全角半角対応)

	function jsTrim( val ) {

		var ret = val;

		ret = ret.replace( /^[\s]*/, "" );

		ret = ret.replace( /[\s]*$/, "" );

		return ret;

	}

} );