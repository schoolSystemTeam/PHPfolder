$(function(){

				$('#update').click(function() {
					if (!confirm('上記の設定で変更します。\nよろしいですか？')) {
						return false;
					}
				});

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

			});