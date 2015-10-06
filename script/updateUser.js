$(function(){

	//各値の変数定義
	var index1 = "";			//旧インデックス番号
	var accountid1 = "";		//旧アカウント管理ID
	var name1 = "";				//旧名前
	var userid1 = "";			//旧ユーザーID
	var password1 = "";			//旧パスワード
	var authority1 = ""; 		//旧ユーザー権限
	var authority_txt1 = "";	//旧ユーザー権限(文字情報)
	var worktype1 = "";			//旧勤務形態
	var worktype_txt1 = "";		//旧勤務形態（文字情報）
	var display1 = "";			//旧表示/非表示番号
	var display_txt1 = "";		//旧表示/非表示(文字情報)
	var color1 = "";			//旧表示色ID
	var color_txt1 = "";		//旧表示色名
	var code1 = "";				//旧表示色コード

	var userid2 = "";			//ユーザー入力ユーザーID
	var password2 = "";			//ユーザー入力パスワード
	var authority2 = ""; 		//ユーザー入力ユーザー権限
	var authority_txt2 = "";	//ユーザー入力ユーザー権限(文字情報)
	var worktype2 = "";			//勤務形態
	var worktype_txt2 = "";		//勤務形態（文字情報）
	var display2 = "";			//ユーザー入力表示/非表示番号
	var display_txt2 = "";		//ユーザー入力表示/非表示(文字情報)
	var color2 = "";			//ユーザー入力表示色ID
	var color_txt2 = "";		//ユーザー入力表示色名


	$(".update").click(function(){
		//選択されたユーザーの初期値を変数に格納
		index1 = $(this).data('index'); 			 	//旧インデックス番号
		accountid1 = $(this).data('accountid');		 	//旧アカウント管理ID
		name1 = $(this).data('name');				 	//旧名前
		userid1 = $(this).data('userid');				//旧ユーザーID
		password1 = $(this).data('password');			//旧パスワード
		authority1 = $(this).data('authority');	 		//旧ユーザー権限
		authority_txt1 = $("#authority"+index1).text();	//旧ユーザー権限(文字情報)
		worktype1 = $(this).data("worktype");			//旧勤務形態
		worktype_txt1 = $('#worktype'+index1).text();	//旧勤務形態（文字情報）
		display1 = $(this).data('display');				//旧表示/非表示番号
		display_txt1 = $("#display"+index1).text();	 	//旧表示/非表示(文字情報)
		color1 = $(this).data('colorid');				//旧表示色ID
		color_txt1 = $("#colorid"+index1).text();	 	//旧表示色名
		code1 = $('#update'+index1).data("code");		//旧表示色コード
		$('.execute').val($(this).data('execute'));		//旧処理種別

		//変更フォームに初期値を入力
		$('#name').text(name1);			//名前
		$('#userid').val(userid1);		//ユーザーID
		$('#password').val(password1);	//パスワード
		$('#authority').val(authority1);//ユーザー権限
		$('#worktype').val(worktype1);	//勤務形態
		$('#display').val(display1);	// 表示/非表示
		$('#colorid').val(color1);		//表示色名


		//変更フォーム用のダイアログを開く
		jQuery( '#jquery-ui-dialog' ) . dialog( 'open' );

	});

	$(".delete").click(function(){

		$('.execute').val($(this).data('execute'));

		if (!confirm('このユーザー情報を削除します。\nよろしいですか？')) {
			return false;
		}
	});

	jQuery( '#jquery-ui-dialog' ) . dialog( {
		autoOpen: false,
		width: 300,
		show: 'explode',
		hide: 'explode',
		modal: true,
		buttons: {
		'変更': function() {

		//エラーチェック用メッセージの作成
		var errMsg = new Array();

		if(jsTrim($('#userid').val()).length == 0){

			errMsg[0] = ("ユーザー名が入力されていません！");
			$("#userid").css("background-color","#FFB6C1");

		}else if($('#userid').val().match ( /[^0-9a-zA-Z_]+/ ) ){

			errMsg[0] = "ユーザー名に不正な文字が入力されています。";
			$("#userid").css("background-color","#FFB6C1");

		}else{
			$("#userid").css("background-color","#FFFFFF");

		}

		if(jsTrim($('#password').val()).length == 0){

			errMsg[1] = ("パスワードが入力されていません！");
			$("#password").css("background-color","#FFB6C1");

		}else if($('#password').val().match ( /[^0-9a-zA-Z_]+/ ) ){

			errMsg[1] = "パスワードに不正な文字が入力されています。";
			$("#password").css("background-color","#FFB6C1");

		}else{
			$("#password").css("background-color","#FFFFFF");

		}

		//エラーが発生していた場合、エラーメッセージをアラートする。
		if(errMsg.length != 0){
			alert(errMsg.join("\n"));
			return false;
		}

		console.log(color_txt1);

		if (!confirm('この内容でユーザー情報を変更します。\nよろしいですか？')) {
			return false;
		}

		//各フォームの値を変数に格納
		userid2 = $('#userid').val();							//ユーザーID
		password2 = $('#password').val();						//パスワード
		authority2 = $('#authority option:selected').val();	 	//ユーザー権限
		authority_txt2 = $("#authority option:selected").text();//ユーザー権限(文字情報)
		worktype2 = $('#worktype option:selected').val();	 	//勤務形態
		worktype_txt2 = $("#worktype option:selected").text();	//勤務形態(文字情報)
		display2 = $('#display option:selected').val();			//表示/非表示番号
		display_txt2 = $("#display option:selected").text();	//表示/非表示(文字情報)
		color2 = $('#colorid option:selected').val();			//表示色ID
		color_txt2 = $("#colorid option:selected").text();	 	//表示色名
		code2 = $("#colorid option:selected").data("code");		//色コード

		$.ajax({
			type: 'POST',
			url:'',
			data:{
			"accountid": accountid1,
			"userid": userid2,
			"password": password2,
			"authority": authority2,
			"worktype":worktype2,
			"display": display2,
			"colorid" :color2,
			"execute": "update"

		},
		success:function(data) {

			//エラーがあったかどうかを確認
			if(data.length != 0){
				alert(data);
				return false;
			}

			//結果表示用のダイアログに文章を挿入する
			//名前
			$('#nameDisp').text(name1);

			//旧ユーザーID
			$('#oldUseridDisp').text(userid1);
			//旧パスワード
			$('#oldPasswordDisp').text(password1);
			//旧権限
			$('#oldAuthorityDisp').text(authority_txt1);
			//旧勤務形態
			$('#oldWorktypeDisp').text(worktype_txt1);
			//旧acitive/inactive
			$('#oldDisplayDisp').text(display_txt1);
			//旧表示色
			$('#oldColorDisp').text(color_txt1);
			//表示色コード
			$('#oldColorDisp').css("color",code1);

			//ユーザーID
			$('#useridDisp').text(userid2);
			//パスワード
			$('#passwordDisp').text(password2);
			//権限
			$('#authorityDisp').text(authority_txt2);
			//勤務形態
			$('#worktypeDisp').text(worktype_txt2);
			// active/inacitive
			$('#displayDisp').text(display_txt2);
			//表示色
			$('#colorDisp').text(color_txt2);
			//表示色コード
			$('#colorDisp').css("color",code2);

			//変更ボタン内のデータ変数を変更する
			$("#update"+index1).data('userid',userid2);	 	 //userid
			$('#update'+index1).data('password',password2);	 //password
			$('#update'+index1).data('authority',authority2);//authority
			$('#update'+index1).data('worktype',worktype2);	 //authority
			$('#update'+index1).data('display',display2);	 //display
			$('#update'+index1).data('colorid',color2);		 //colorid
			$('#update'+index1).data('code',code2);			 //code

			//HTMLのテキストを変更する
			$('#name'+index1).css("color",code2);		//名前表示色
			$('#userid'+index1).text(userid2);		 	//ユーザーID
			$('#password'+index1).text(password2);	 	//パスワード
			$('#authority'+index1).text(authority_txt2);//権限
			$('#worktype'+index1).text(worktype_txt2);	//勤務形態
			$('#display'+index1).text(display_txt2);	// active/inactive
			$('#colorid'+index1).text(color_txt2);	 	// 表示色
			$('#colorid'+index1).css("color",code2);	// 表示色コード

			//新たなダイアログを立ち上げる
			jQuery( '#jquery-ui-dialog2' ) . dialog( 'open' );

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {

		}
		});

			jQuery( this ) . dialog( 'close' );

	},

	'キャンセル': function() {

		jQuery( this ).dialog( 'close' );
	},
	}
	} );

	jQuery( '#jquery-ui-dialog2' ) . dialog( {
		autoOpen: false,
		width: 370,
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


});