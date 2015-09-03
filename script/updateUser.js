$(function(){

	$('#select_user').on('change', function(){

		$.ajax({
			type: 'POST',
			url:'./updateUser.php',

			data:{

			"accountid": $('#select_user option:selected').val()

		},
		success:function(data) {

			console.log(JSON.parse(data));

			var user = JSON.parse(data);

			if(user['display'] == 1){
				var disp = "表示";
			}else{
				var disp = "非表示";
			}

			if(user['authority'] == 2){
				var author = "管理者";
			}else{
				var author = "ユーザー";
			}

			$('.s').text(author);
			$('#pass').text(user['password']);

			$('#d').text(disp);
			$('.p').text(user['p-name']);
			$('.c').text(user['c-name']);
			$('.c').css("color",user['code']);

		},
		error:function(XMLHttpRequest, textStatus, errorThrown) {
			alert("選択されたユーザーは存在しません。");
		}
		});
	});

	$("form").submit(function(){

		if (!confirm('設定した情報で変更します。\nよろしいですか？')) {
			return false;
		}

		//各フォームの値を変数に格納
		var password = $("input[name='password']").val();		//パスワード

		var array = new Array();


		if(jsTrim(password).length == 0){

			array[0] = "パスワードが入力されていません！";
			$("input[name='password']").css("background-color","#FFB6C1");

		}else if(password.match ( /[^0-9a-zA-Z_]+/ ) ){

			array[0] = "パスワードに不正な文字が入力されています。";
			$("input[name='password']").css("background-color","#FFB6C1");

		}else{
			$("input[name='password']").css("background-color","#FFFFFF");
		}

		if(!$("input[name='display']").prop("checked"))
		{

			array[1] = "表示/非表示の設定が選択されていません！";

		}else{
		}

		if(!$("input[name='colorid']").prop("checked"))
		{
			array[2] = "表示色が選択されていません！";

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

