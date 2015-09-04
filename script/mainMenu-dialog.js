/*
 *概要：
 *	mainMenu-dialog.js
 *機能説明：
 *	メインメニュー部分の各ダイアログの表示（勤怠登録,削除,修正フォーム）と
 *	ajaxを使用した各処理を行う。
 *備考：
 *	作成日)	2015/9/01
 *	作成者)	水島創太
 *	説明）
 *	更新日)	2015/09/02
 *	更新者)	水島創太
 *	変更)	一括登録と一括削除のエラー処理を行うように変更
 */
jQuery( function() {

	//勤怠登録機能

	jQuery( '.day-calendar' ) . click( function() {

		//各IDのinput=hiddenに値を挿入

		$('#year').val($(this).data('year'));	//押下時の年
		$('#month').val($(this).data('month'));	//押下時の月
		$('#day').val($(this).data('day'));		//押下時の日付

		//登録フォーム用のダイアログを開く
		jQuery( '#jquery-ui-dialog' ) . dialog( 'open' );
	} );
	var date = 250;
	var name = jQuery( '#jquery-ui-dialog-form-name' );
	var hour = jQuery( '#jquery-ui-dialog-form-hour' );
	var minute = jQuery( '#jquery-ui-dialog-form-minute' );
	var endhour = jQuery( '#jquery-ui-dialog-form-endhour' );
	var endminute = jQuery( '#jquery-ui-dialog-form-endminute' );

	//ダイアログ内の設定
	jQuery( '#jquery-ui-dialog' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'登録': function() {
		if ( name . val() || hour . val() ) {

			if (!confirm('この勤務情報を登録します。\nよろしいですか？')) {
				jQuery( this ).dialog( 'close' );
				return false;
			}

			$.ajax({
				type: 'POST',
				url:'../mainMenu/mainMenu.php',
				data:{
				"accountid": $('#jquery-ui-dialog-form-name option:selected').val(),
				"formYear": $(':hidden[name="year"]').val(),
				"formMonth": $(':hidden[name="month"]').val(),
				"formDay": $(':hidden[name="day"]').val(),
				"workstarthour": $('#jquery-ui-dialog-form-hour option:selected').val(),
				"workstartminute": $('#jquery-ui-dialog-form-minute option:selected').val(),
				"workendhour": $('#jquery-ui-dialog-form-endhour option:selected').val(),
				"workendminute": $('#jquery-ui-dialog-form-endminute option:selected').val(),
				"execute": "insert"

			},
			success:function(data) {

				//errMsg1に戻り値としてエラーメッセージを格納
				var errMsg1 = JSON.parse(data);

				//エラーがあったかどうかをチェック
				if(errMsg1 instanceof Array)
				{
					//エラーが発生した場合,エラーメッセージを表示する
					alert(errMsg1.join("\n"));
				}

				location.reload();

			},
			error:function(XMLHttpRequest, textStatus, errorThrown) {

			}
			});

			jQuery( this ).dialog( 'close' );
		}
		jQuery( this ) . dialog( 'close' );
	},

	'キャンセル': function() {
		jQuery( this ) . dialog( 'close' );
	},
	}
	} );
} );


jQuery( function() {
	jQuery( 'span#change' ) . click( function() {
		console.log($(this).data('starthour'));
		console.log($(this).data('startminute'));
		console.log($(this).data('endhour'));
		console.log($(this).data('endminute'));

		$('#workplanid').val($(this).data('workplanid'));
		$('#year2').val($(this).data('year'));
		$('#month2').val($(this).data('month'));
		$('#day2').val($(this).data('day'));
		$( 'select#jquery-ui-dialog-form-hour2' ).val($(this).data('starthour'));
		$( 'select#jquery-ui-dialog-form-minute2' ).val($(this).data('startminute'));
		$( 'select#jquery-ui-dialog-form-endhour2' ).val($(this).data('endhour'));
		$( 'select#jquery-ui-dialog-form-endminute2' ).val($(this).data('endminute'));
		$('.changename').text($(this).data('name'));
		jQuery( '#jquery-ui-dialog2' ) . dialog( 'open' );
	} );
	var hour2 = jQuery( '#jquery-ui-dialog-form-hour2' );
	var minute2 = jQuery( '#jquery-ui-dialog-form-minute2' );
	var endhour2 = jQuery( '#jquery-ui-dialog-form-endhour2' );
	var endminute2 = jQuery( '#jquery-ui-dialog-form-endminute2' );
	jQuery( '#jquery-ui-dialog2' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'変更': function() {
		if (hour2 . val() ) {
			if (!confirm('この勤務情報を変更します。\nよろしいですか？')) {
				jQuery( this ).dialog( 'close' );
				return false;
			}
			$.ajax({
				type: 'POST',
				url:'../mainMenu/mainMenu.php',
				data:{
				"workplanid": $(':hidden[name="workplanid"]').val(),
				"formYear": $(':hidden[name="year2"]').val(),
				"formMonth": $(':hidden[name="month2"]').val(),
				"formDay": $(':hidden[name="day2"]').val(),
				"workstarthour": $('#jquery-ui-dialog-form-hour2 option:selected').val(),
				"workstartminute": $('#jquery-ui-dialog-form-minute2 option:selected').val(),
				"workendhour": $('#jquery-ui-dialog-form-endhour2 option:selected').val(),
				"workendminute": $('#jquery-ui-dialog-form-endminute2 option:selected').val(),
				"execute": "update"

			},
			success:function(data) {

				//errMsg1に戻り値としてエラーメッセージを格納
				var errMsg2 = JSON.parse(data);

				//エラーがあったかどうかをチェック
				if(errMsg2 instanceof Array)
				{
					//エラーが発生した場合,エラーメッセージを表示する
					alert(errMsg2.join("\n"));
				}

				location.reload();

			},
			error:function(XMLHttpRequest, textStatus, errorThrown) {

			}
			});

			jQuery( this ).dialog( 'close' );
		}
		jQuery( this ) . dialog( 'close' );
	},
	'削除': function() {
		if (!confirm('この勤務情報を削除します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}
		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"workplanid": $(':hidden[name="workplanid"]').val(),
			"formYear": $(':hidden[name="year2"]').val(),
			"formMonth": $(':hidden[name="month2"]').val(),
			"formDay": $(':hidden[name="day2"]').val(),
			"execute": "delete"

		},
		success:function(data) {

			location.reload();

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});
		jQuery( this ) . dialog( 'close' );
	},
	'キャンセル': function() {
		jQuery( this ) . dialog( 'close' );
	},
	}
	} );
} );

$(function(){

	$('#allInsert').click(function() {

		if (!confirm('この内容で一括登録を行います。\nよろしいですか？')) {
			return false;
		}

			//エラーメッセージを格納する配列を作成
			var errArray = new Array();

			//チェックボックスがチェックされているか確認する変数
			var checkComfirm = 0;

			//チェックボックスの空白チェック

			for(var i = 1;i <= 7; i++){

				if($("#area" +i).prop('checked')){

					checkComfirm += 1;

				}

			}

			if(checkComfirm == 0)
			{
				errArray[0] = "曜日が選択されていません。曜日を選択して下さい！";
			}

			//登録開始期間の空白チェック
			if($('#startDay1').val() == "")
			{
				errArray[1] = "開始期間が選択されていません。日付を選択して下さい！";
			}

			//登録終了期間の空白チェック
			if($('#endDay1').val() == "")
			{
				errArray[2] = "終了期間が選択されていません。日付を選択して下さい！";
			}

			if(errArray.length != 0){
				alert(errArray.join("\n"));
				return false;
			}

	});

	$('#allDelete').click(function() {
		console.log($('#startDay2').val());
		console.log($('#endDay2').val());
		if (!confirm('この内容で一括削除を行います。\nよろしいですか？')) {
			return false;
		}

			//エラーメッセージを格納する配列を作成
			var errArray2 = new Array();

			//チェックボックスがチェックされているか確認する変数
			var checkComfirm = "";

			//チェックボックスの空白チェック
			if(!$('#week1').prop('checked')){

				checkComfirm = 1;

			}

			if(!$('#week2').prop('checked')){

				checkComfirm += 1;

			}

			if(!$('#week3').prop('checked')){

				checkComfirm += 1;

			}

			if(!$('#week4').prop('checked')){

				checkComfirm += 1;

			}

			if(!$('#week5').prop('checked')){

				checkComfirm += 1;

			}

			if(!$('#week6').prop('checked')){

				checkComfirm += 1;

			}

			if(!$('#week7').prop('checked')){

				checkComfirm += 1;

			}

			if(checkComfirm == 7)
			{
				errArray2[0] = "曜日が選択されていません。曜日を選択して下さい！";
			}

			//登録開始期間の空白チェック
			if($('#startDay2').val() == "")
			{
				errArray2[1] = "開始期間が選択されていません。日付を選択して下さい！";
			}

			//登録終了期間の空白チェック
			if($('#endDay2').val() == "")
			{
				errArray2[2] = "終了期間が選択されていません。日付を選択して下さい！";
			}

			if(errArray2.length != 0){
				alert(errArray2.join("\n"));
				return false;
			}

	});

} );
