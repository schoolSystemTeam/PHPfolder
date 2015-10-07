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
	//ダイアログ表示機能

	$("#workstarthourAll").val("9");
	$("#workendhourAll").val("18");


	//勤怠登録機能

	jQuery( '.day-calendar' ) . click( function() {

		//セレクトのイベントを発動させる
		$('#jquery-ui-dialog-form-name').trigger('change');

		//各IDのinput=hiddenに値を挿入

		$('#year').val($(this).data('year'));	//押下時の年
		$('#month').val($(this).data('month'));	//押下時の月
		$('#day').val($(this).data('day'));		//押下時の日付

		//勤務開始時間と勤務終了時間にデフォルト値をセットする。
		$('select#jquery-ui-dialog-form-hour').val('9');	//勤務開始時間
		$('select#jquery-ui-dialog-form-endhour').val('18');//勤務終了時間
		$('select#jquery-ui-dialog-form-status').val('6');	//ステータス

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
				"positionid": $('#jquery-ui-dialog-form-position option:selected').val(),
				"statusid": $('#jquery-ui-dialog-form-status option:selected').val(),
				"execute": "insert"

			},
			success:function(data) {

				//errMsg1に戻り値としてエラーメッセージを格納
				var errMsg1 = JSON.parse(data);

				//エラーがあったかどうかをチェック
				if(errMsg1.length != 0)
				{
					//エラーが発生した場合,エラーメッセージを表示する
					alert(errMsg1.join("\n"));
					return false;
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

	//名前の選択が変更された場合
	$('#jquery-ui-dialog-form-name').change(function(){

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"accountid": $('#jquery-ui-dialog-form-name option:selected').val(),
			"execute": "searchAccount"

		},
		success:function(data) {

			var accountInfo = JSON.parse(data);

			if(accountInfo["worktype"] == 2)
			{
				$('select#jquery-ui-dialog-form-status option[value=3]').attr("disabled", "disabled");

			}else{

				$('select#jquery-ui-dialog-form-status option[value=3]').removeAttr("disabled");

			}

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

	});

	// 数値をフォーマットする
	function numFormat( num ) {

		var ret = ("0"+num).slice(-2);

		return ret;

	}

} );


jQuery( function() {
	jQuery( 'span#change,span#change2') . click( function() {

		//変更機能を押下時に初期値をセット

		$('#workplanid').val($(this).data('workplanid'));	//勤務情報IDをhiddenにセット
		$('#year2').val($(this).data('year'));				//年をhiddenにセット
		$('#month2').val($(this).data('month'));			//月をhiddenにセット
		$('#day2').val($(this).data('day'));				//日をhiddenにセット
		$('#accountid2').val($(this).data('accountid'));	//アカウントIDをhiddenにセット

		//勤務形態を取得して変数に代入
		var worktype = $(this).data('worktype');	//勤務形態

		//勤務形態が非常勤講師の場合,休みのステータスを選択できなくする
		if(worktype == 2){

			$('select#jquery-ui-dialog-form-status2 option[value=3]').attr("disabled","disabled");

		}else{

			$('select#jquery-ui-dialog-form-status2 option[value=3]').removeAttr("disabled");

		}

		//セレクタで選択された役割
		$( 'select#jquery-ui-dialog-form-position2' ).val($(this).data('positionid'));

		//年月日をカレンダー日付フォームに初期値として設定
		$('#insertWorkDate').val($(this).data('year')+"/"+$(this).data('month')+"/"+$(this).data('day'));

		//開始時
		$( 'select#jquery-ui-dialog-form-hour2' ).val($(this).data('starthour'));

		//開始分
		$( 'select#jquery-ui-dialog-form-minute2' ).val($(this).data('startminute'));

		//終了時
		$( 'select#jquery-ui-dialog-form-endhour2' ).val($(this).data('endhour'));

		//終了分
		$( 'select#jquery-ui-dialog-form-endminute2' ).val($(this).data('endminute'));

		//ステータス
		$( 'select#jquery-ui-dialog-form-status2' ).val($(this).data('statusid'));

		//名前を入力
		$('.changename').text($(this).data('name'));

		jQuery( '#jquery-ui-dialog2' ) . dialog( 'open' );


	} );

	jQuery( '#jquery-ui-dialog2' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'変更': function() {

		//日付の空白チェック
		if(jsTrim($('#insertWorkDate').val()).length == 0){

			alert("日付が入力されていません！");
			return false;

		}

		if (!confirm('この勤務情報を変更します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}
		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"workplanid": $(':hidden[name="workplanid"]').val(),
			"updateDate": $("input[name='updateDate']").val(),
			"positionid": $('#jquery-ui-dialog-form-position2 option:selected').val(),
			"workstarthour": $('#jquery-ui-dialog-form-hour2 option:selected').val(),
			"workstartminute": $('#jquery-ui-dialog-form-minute2 option:selected').val(),
			"workendhour": $('#jquery-ui-dialog-form-endhour2 option:selected').val(),
			"workendminute": $('#jquery-ui-dialog-form-endminute2 option:selected').val(),
			"statusid": $('#jquery-ui-dialog-form-status2 option:selected').val(),
			"formYear": $(':hidden[name="year2"]').val(),
			"formMonth": $(':hidden[name="month2"]').val(),
			"formDay": $(':hidden[name="day2"]').val(),
			"accountid": $(':hidden[name="accountid2"]').val(),
			"execute": "update"

		},
		success:function(data) {

			//errMsg2に戻り値としてエラーメッセージを格納
			var errMsg2 = JSON.parse(data);

			//エラーがあったかどうかをチェック
			if(errMsg2.length != 0)
			{
				//エラーが発生した場合,エラーメッセージを表示する
				alert(errMsg2.join("\n"));
				return false;
			}

			location.reload();

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

		jQuery( this ).dialog( 'close' );

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
			"accountid": $(':hidden[name="accountid2"]').val(),
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

	// 前後スペース削除(全角半角対応)

	function jsTrim( val ) {

		var ret = val;

		ret = ret.replace( /^[\s]*/, "" );

		ret = ret.replace( /[\s]*$/, "" );

		return ret;

	}
} );

jQuery( function() {

	//イベント登録機能

	jQuery( '.event' ) . click( function() {
		//各IDのinput=hiddenに値を挿入

		$('#year3').val($(this).data('year'));		//押下時の年
		$('#month3').val($(this).data('month'));	//押下時の月
		$('#day3').val($(this).data('day'));		//押下時の日付

		//セレクトボックスに値を挿入する為のトリガーを強制起動
		$('#userName').trigger('change');


		//登録フォーム用のダイアログを開く
		jQuery( '#jquery-ui-dialog3' ) . dialog( 'open' );
	} );

	jQuery( '#userName' ).change( function() {

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"formYear": $(":hidden[name='year3']").val(),
			"formMonth": $(":hidden[name='month3']").val(),
			"formDay": $(":hidden[name='day3']").val(),
			"accountid":$("#userName option:selected").val(),
			"execute": "searchUser"

		},
		success:function(data) {

			//errMsg4に戻り値としてエラーメッセージを格納
			var workPlanInfo = JSON.parse(data);

			console.log(workPlanInfo);

			//エラーがあったかどうかをチェック
			if(workPlanInfo.length != 0)
			{
				$('select#jquery-ui-dialog-form-hour3').val(workPlanInfo['starthour']);
				$('select#jquery-ui-dialog-form-endhour3').val(workPlanInfo['endhour']);
				$('select#jquery-ui-dialog-form-minute3').val(workPlanInfo['startminute']);
				$('select#jquery-ui-dialog-form-endminute3').val(workPlanInfo['endminute']);
			}else{

				//勤務開始時間と勤務終了時間にデフォルト値をセットする。
				$('select#jquery-ui-dialog-form-hour3').val('9');	//勤務開始時間
				$('select#jquery-ui-dialog-form-endhour3').val('18');//勤務終了時間

			}

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

	} );

	//ダイアログ内の設定
	jQuery( '#jquery-ui-dialog3' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'登録': function() {

		if (!confirm('このイベント情報を登録します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"accountid":$('#userName option:selected').val(),
			"eventid": $('#eventid option:selected').val(),
			"workstarthour": $('#jquery-ui-dialog-form-hour3 option:selected').val(),
			"workstartminute": $('#jquery-ui-dialog-form-minute3 option:selected').val(),
			"workendhour": $('#jquery-ui-dialog-form-endhour3 option:selected').val(),
			"workendminute": $('#jquery-ui-dialog-form-endminute3 option:selected').val(),
			"formYear": $(':hidden[name="year3"]').val(),
			"formMonth": $(':hidden[name="month3"]').val(),
			"formDay": $(':hidden[name="day3"]').val(),
			"execute": "insertEvent"

		},
		success:function(data) {


			//errMsg1に戻り値としてエラーメッセージを格納
			var errMsg3 = JSON.parse(data);

			//エラーがあったかどうかをチェック
			if(errMsg3.length != 0)
			{
				//エラーが発生した場合,エラーメッセージを表示する
				alert(errMsg3.join("\n"));
				return false;
			}
			//var d = '<div class="work"><span id="change" data-name="管理者" data-workplanid="133" data-accountid="3" data-year="2015" data-month="9" data-day="7" data-positionid="4" data-starthour="9" data-startminute="00" data-endhour="18" data-endminute="00" style="color:black">管理者</span><span id="time">09~<span id="position" style="color:red">セ</span></div>';
			//$('.work-calendar').eq(18).append(d);
			location.reload();

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

		jQuery( this ).dialog( 'close' );

	},

	'キャンセル': function() {
		jQuery( this ) . dialog( 'close' );
	},
	}
	} );
} );


jQuery( function() {
	jQuery( 'span#eventDisp' ) . click( function() {
		$('#eventplanid').val($(this).data('eventplanid'));
		$('select#eventid2').val($(this).data('eventid'));
		$('select#userName2').val($(this).data('accountid'));
		$('#year4').val($(this).data('year'));
		$('#month4').val($(this).data('month'));
		$('#day4').val($(this).data('day'));
		$('#accountid4').val($(this).data('accountid'));
		$('.datepicker').val($(this).data('year')+"/"+$(this).data('month')+"/"+$(this).data('day'));
		jQuery( '#jquery-ui-dialog4' ) . dialog( 'open' );

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"formYear": $(":hidden[name='year4']").val(),
			"formMonth": $(":hidden[name='month4']").val(),
			"formDay": $(":hidden[name='day4']").val(),
			"accountid":$("#userName2 option:selected").val(),
			"execute": "searchUser"

		},
		success:function(data) {

			//errMsg4に戻り値としてエラーメッセージを格納
			var workPlanInfo = JSON.parse(data);

			//エラーがあったかどうかをチェック
			if(workPlanInfo.length != 0)
			{
				$('select#jquery-ui-dialog-form-hour4').val(workPlanInfo['starthour']);
				$('select#jquery-ui-dialog-form-endhour4').val(workPlanInfo['endhour']);
				$('select#jquery-ui-dialog-form-minute4').val(workPlanInfo['startminute']);
				$('select#jquery-ui-dialog-form-endminute4').val(workPlanInfo['endminute']);
			}

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

	} );

	jQuery( '#userName2' ).change( function() {

		console.log($(":hidden[name='year4']").val());
		console.log($(":hidden[name='month4']").val());
		console.log($(":hidden[name='day4']").val());
		console.log($("#userName2 option:selected").val());

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"formYear": $(":hidden[name='year4']").val(),
			"formMonth": $(":hidden[name='month4']").val(),
			"formDay": $(":hidden[name='day4']").val(),
			"accountid":$("#userName2 option:selected").val(),
			"execute": "searchUser"

		},
		success:function(data) {

			//errMsg4に戻り値としてエラーメッセージを格納
			var workPlanInfo = JSON.parse(data);

			//エラーがあったかどうかをチェック
			if(workPlanInfo.length != 0)
			{
				$('select#jquery-ui-dialog-form-hour4').val(workPlanInfo['starthour']);
				$('select#jquery-ui-dialog-form-endhour4').val(workPlanInfo['endhour']);
				$('select#jquery-ui-dialog-form-minute4').val(workPlanInfo['startminute']);
				$('select#jquery-ui-dialog-form-endminute4').val(workPlanInfo['endminute']);
			}

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

	} );

	jQuery( '#jquery-ui-dialog4' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'変更': function() {
		if (!confirm('このイベント情報を変更します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}
		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"eventplanid": $(":hidden[name='eventplanid']").val(),
			"formYear": $(":hidden[name='year4']").val(),
			"formMonth": $(":hidden[name='month4']").val(),
			"formDay": $(":hidden[name='day4']").val(),
			"updateDate": $("input[name='updateDate2']").val(),
			"eventid": $('#eventid2 option:selected').val(),
			"workstarthour": $('#jquery-ui-dialog-form-hour4 option:selected').val(),
			"workstartminute": $('#jquery-ui-dialog-form-minute4 option:selected').val(),
			"workendhour": $('#jquery-ui-dialog-form-endhour4 option:selected').val(),
			"workendminute": $('#jquery-ui-dialog-form-endminute4 option:selected').val(),
			"accountid":$("#userName2 option:selected").val(),
			"oldAccount":$(":hidden[name='accountid4']").val(),
			"execute": "updateEvent"

		},
		success:function(data) {

			//errMsg4に戻り値としてエラーメッセージを格納
			var errMsg4 = JSON.parse(data);

			//エラーがあったかどうかをチェック
			if(errMsg4.length != 0)
			{
				//エラーが発生した場合,エラーメッセージを表示する
				alert(errMsg4.join("\n"));
				return false;
			}

			location.reload();

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

		jQuery( this ).dialog( 'close' );


	},
	'削除': function() {
		if (!confirm('このイベント情報を削除します。\nよろしいですか？')) {
			jQuery( this ).dialog( 'close' );
			return false;
		}

		$.ajax({
			type: 'POST',
			url:'../mainMenu/mainMenu.php',
			data:{
			"eventplanid": $(":hidden[name='eventplanid']").val(),
			"formYear": $(":hidden[name='year4']").val(),
			"formMonth": $(":hidden[name='month4']").val(),
			"formDay": $(":hidden[name='day4']").val(),
			"accountid":$(":hidden[name='accountid4']").val(),
			"execute": "deleteEvent"

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
		if(jsTrim($('#startDay1').val()).length == 0)
		{
			errArray[1] = "開始期間が選択されていません。日付を選択して下さい！";
		}

		//登録終了期間の空白チェック
		if(jsTrim($('#endDay1').val()).length == 0)
		{
			errArray[2] = "終了期間が選択されていません。日付を選択して下さい！";
		}

		if(errArray.length != 0){
			alert(errArray.join("\n"));
			return false;
		}

		if (!confirm('この内容で一括登録を行います。\nよろしいですか？')) {
			return false;
		}

	});

	$('#allDelete').click(function() {

		//エラーメッセージを格納する配列を作成
		var errArray2 = new Array();

		//チェックボックスがチェックされているか確認する変数
		var checkComfirm = 0;

		//チェックボックスの空白チェック
		//チェックボックスの空白チェック

		for(var i = 1;i <= 7; i++){

			if($("#week" +i).prop('checked')){

				checkComfirm += 1;

			}

		}

		if(checkComfirm == 0)
		{
			errArray2[0] = "曜日が選択されていません。曜日を選択して下さい！";
		}

		//登録開始期間の空白チェック
		if(jsTrim($('#startDay2').val()).length == 0)
		{
			errArray2[1] = "開始期間が選択されていません。日付を選択して下さい！";
		}

		//登録終了期間の空白チェック
		if(jsTrim($('#endDay2').val()).length == 0)
		{
			errArray2[2] = "終了期間が選択されていません。日付を選択して下さい！";
		}

		if(errArray2.length != 0){
			alert(errArray2.join("\n"));
			return false;
		}

		if (!confirm('この内容で一括削除を行います。\nよろしいですか？')) {
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

} );

$(function() {

	$(".datepicker").datepicker();
	$(".datepicker").datepicker("option", "showOn", 'button');

});


$(function(){

	$('span#eventDisp').hover(function(){

		$( ".event" ).tooltip("disable");

	} );

	$('.event').hover(function(){

		$( ".event" ).tooltip("enable");

	} );

});
