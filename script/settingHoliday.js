$(function(){

	//日付入力用datepicker仕様関数
	$(".datepicker").datepicker({
		dateFormat: 'yy-mm-dd',
		showOn: 'button'
	});

	//タブの開閉時の文字列変更（休日個別登録）
	$('#single').click(function(){
		$(this).text('◇休日個別登録');
		$('#multi').text('▼休日一括登録');
	});

	//タブの開閉時の文字列変更（休日一括登録）
	$('#multi').click(function(){
		$('#single').text('▼休日個別登録');
		$(this).text('◇休日一括登録');
	});

	$('#setSingle').click(function() {

		if (!confirm('設定した休日で登録します。\nよろしいですか？')) {
			return false;
		}

		//変数定義
		var holiday = $("input[name='holiday']").val();	//日付（フォーム入力）

		//空白のエラーチェック
		if(jsTrim(holiday).length == 0){

			alert("日付が選択されていません！");
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

	$('#setStuSun').click(function() {

		if (!confirm('選択した曜日で一括登録します。\nよろしいですか？')) {
			return false;
		}

		//変数定義

		var startDate = $("input[name='startHoliday']").val();	//開始日付（入力フォーム）
		var endDate = $("input[name='endHoliday']").val();		//終了日付（入力フォーム）
		var checkComfirm = 0;									//チェックボックス入力確認用変数
		var errArray1 = new Array();							//エラーメッセージ格納用変数

		//土曜日分のチェックボックスを確認
		if($('#saturday').prop('checked')){

			checkComfirm += 1;

		}

		//日曜日分のチェックボックスを確認
		if($('#sunday').prop('checked')){

			checkComfirm += 1;

		}

		//チェックが一つも入っていなければエラーメッセージを格納
		if(checkComfirm == 0){

			errArray1[0] = "曜日が選択されていません。曜日を選択して下さい！";

		}

		//開始日付の空白チェック
		if(jsTrim(startDate).length == 0){

			errArray1[1] = "開始日付が選択されていません。開始日付を選択して\n下さい！";

		}

		//終了日付の空白チェック
		if(jsTrim(endDate).length == 0){

			errArray1[2] = "終了日付が選択されていません。終了日付を選択して\n下さい！";

		}

		//エラーが発生していた場合、エラーメッセージをアラートする。
		if(errArray1.length != 0){
			alert(errArray1.join("\n"));
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

	$('#setBulk').click(function() {

		if (!confirm('記述した日程で一括登録します。\nよろしいですか？')) {
			return false;
		}

		//テキストエリアの入力値を変数に格納
		var textarea = $("#textarea").val();

		//空白エラーチェック
		if(jsTrim(textarea).length == 0){

			alert("テキストが記述されていません！");
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

	$('.delete').click(function() {
		if (!confirm('選択した休日を削除します。\nよろしいですか？')) {
			return false;
		}
	});

	$("dd:not(:first)").css("display","none");

	$("dl dt").click(function(){
		if($("+dd",this).css("display")=="none"){
			$("dd").slideUp();
			$("+dd",this).slideDown();
		}
	});
});

jQuery( function() {

	jQuery( 'a.update' ) . click( function() {
		$('#holidayid').val($(this).data('id'));
		$('#oldDay').val($(this).data('day'));
		$('#dialog-holiday').val($(this).data('day'));
		$('select#dialog-type').val($(this).data('type'));
		$('#dialog-name').val($(this).data('name'));

		jQuery( '#update-dialog' ) . dialog( 'open' );
	});

	jQuery( '#update-dialog' ) . dialog( {
		autoOpen: false,
		width: 350,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
			'変更': function() {

				var holiday = $('#dialog-holiday').val();

				$.ajax({
					type: 'POST',
					url:'../settingHoliday/settingHoliday.php',
					data:{
						"execute": "search"
					},

					success:function(data) {
						if(holiday.length == 0){
							alert("日付が入力されていません！");
							return false;
						}

						var existing = JSON.parse(data);
						for(var i=0; i<existing.length; i++){
							if(holiday == existing[i]['day'] && holiday != $('#oldDay').val()){
								alert("既にこの日付には休日が登録されています！");
								return false;
							}
						}

						if (!confirm('休日設定を入力した内容で変更します。\nよろしいですか？')) {
							return false;

						}else{
							jQuery( '#update-dialog' ).dialog( 'close' );
							$.ajax({
								type: 'POST',
								url:'../settingHoliday/settingHoliday.php',
								data:{
									"holidayid": $(':hidden[name="holidayid"]').val(),
									"oldDay": $('#oldDay').val(),
									"holiday": holiday,
									"type":$('#dialog-type option:selected').val(),
									"holidayName":$('#dialog-name').val(),
									"execute": "update"
								},

								success:function(data) {
									location.reload();
								},

								error:function(XMLHttpRequest, textStatus, errorThrown) {
									alert("変更処理が失敗しました。");
								}
							});
						}
					},
					error:function(XMLHttpRequest, textStatus, errorThrown) {}
				});
			},

			'キャンセル': function() {
				jQuery( this ) . dialog( 'close' );
			},
		}
	} );
} );
