jQuery( function() {

	//各変数定義
	var eventid = "";
	var eventName = "";
	var shortName = "";
	var color = "";
	var eventName2 = "";
	var shortName2 = "";
	var color2 = "";
	var index = "";

	$('.delete') . click(function() {

		if (!confirm('このセミナー情報を削除します。\nよろしいですか？')) {
			return false;
		}

	});

	//セミナー変更機能

	jQuery( '.update' ) . click( function() {

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
			$('#oldEventNameDisp').append(eventName);
			//旧イベント略名
			$('#oldShortNameDisp').append(shortName);
			//旧表示色
			$('#oldColorDisp').css("background-color",color);
			//イベント名
			$('#eventNameDisp').append(eventName2);
			//イベント略名
			$('#shortNameDisp').append(shortName2);
			//表示色
			$('#colorDisp').css("background-color",color2);

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