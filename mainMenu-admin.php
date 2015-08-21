<?php
//現在の日付を取得
$year = date('Y');	//年
$month = date('n');	//月
$today = date('j');	//日

//去年、来年に遷移する際の処理

if(isset($_GET["kyonen"])){	//来年のカレンダー表示のリンクからの遷移かをチェック

	//strnotime関数を使用し、その年数分を足しこんだ日付データをそれぞれ取得する

	$year0 = date('Y', strtotime($_GET["kyonen"]."-".$_GET["month"]."-1 -1 year"));	//1年前の年を取得
	$month0 = date('n', strtotime($_GET["kyonen"]."-".$_GET["month"]."-1 -1 year"));//1年前の月を取得

}else if(isset($_GET["rainen"])){	//昨年のカレンダー表示リンクからの遷移かをチェック

	$year0 = date('Y', strtotime($_GET["rainen"]."-".$_GET["month"]."-1 +1 year"));	//1年先の年を取得
	$month0= date('n', strtotime($_GET["rainen"]."-".$_GET["month"]."-1 +1 year"));	//1年先の月を取得

//先月、翌月に遷移する際の処理

}else if(isset($_GET["sengetu"])){ //先月のカレンダー表示リンクからの遷移かをチェック

	$year0 = date('Y', strtotime($_GET["year"]."-".$_GET["sengetu"]."-1 -1 month"));	//1ヶ月前の年を取得
	$month0 = date('n', strtotime($_GET["year"]."-".$_GET["sengetu"]."-1 -1 month"));	//1ヶ月前の月を取得

}else if(isset($_GET["yokugetu"])){	//翌月のカレンダー表示リンクからの遷移かをチェック

	$year0 = date('Y', strtotime($_GET["year"]."-".$_GET["yokugetu"]."-1 +1 month"));	//1ヶ月先の年を取得
	$month0 = date('n', strtotime($_GET["year"]."-".$_GET["yokugetu"]."-1 +1 month")); 	//1ヶ月先の月を取得

//初期状態の場合
}else{

	//現在の日付データを日付情報として格納する。

	$year0 = $year;		//今年
	$month0 = $month;	//今月

}

//表示の決定

if(isset($_GET["disp"])){

	$dispMonth = $_GET["disp"];

}else{

	$dispMonth = 1;

}

if(isset($_POST["reset"])){
	//現在の日付データを日付情報として格納する。

	$year0 = $year;		//今年
	$month0 = $month;	//今月
	$dispMonth = 1;
}

//2ヶ月分の月情報を変数に格納

$year1  = date('Y', strtotime($year0."-".$month0."-1 +1 month"));	//1ヶ月先の年を取得
$month1 = date('n', strtotime($year0."-".$month0."-1 +1 month"));	//1ヶ月先の月を取得
$year2  = date('Y', strtotime($year0."-".$month0."-1 +2 month"));	//2ヶ月先の年を取得
$month2 = date('n', strtotime($year0."-".$month0."-1 +2 month"));	//2ヶ月先の月を取得

//フォントの色を黒で初期化
$fontcolor = "#000000";


//3か月分ループをまわして日付情報を格納する
for($calNum=0 ; $calNum < 3 ;$calNum++){

	// 月末日を取得
	$last_day = date('t', strtotime(${'year'.$calNum}."-".${'month'.$calNum}."-1"));

	//日付情報を格納するクラスclanderを「clander + ループ回数」の変数名で配列として初期化
	${'calendar'.$calNum} = array();
	$j = 0;

	// 月末日までループ

	for ($i = 1; $i < $last_day + 1; $i++) {

		// 曜日を取得
		$week[] = date('w', mktime(0, 0, 0, ${'month'.$calNum}, $i, ${'year'.$calNum}));

		// 1日の場合
		if ($i == 1) {

			// 1日目の曜日までをループ
			for ($s = 1; $s <= $week[$calNum]; $s++) {

				// 前半に空文字をセット
				${'calendar'.$calNum}[$j]['day'] = '';
				$j++;
			}
		}

		// 配列に日付をセット
		${'calendar'.$calNum}[$j]['day'] = $i;
		$j++;

		// 月末日の場合
		if ($i == $last_day) {

			// 月末日から残りをループ
			for ($e = 1; $e <= 6 - $week[$calCnt]; $e++) {

				// 後半に空文字をセット
				${'calendar'.$calNum}[$j]['day'] = '';
				$j++;
			}
		}
	}

}

?>

<!DOCTYPE html>
<html lang="ja">
	<head>
		<meta charset="UTF-8">
		<link rel="stylesheet" href="design.css">
		<link rel="stylesheet" href="content.css">
		<link rel="stylesheet" href="./jquery-ui.css">
		<script src="./jquery-1.11.3.min.js"></script>
		<script src="./jquery-ui.js"></script>
		<script>

		jQuery( function() {
	   		jQuery( '#jquery-ui-tabs' ) . tabs( {
	        	active: <?php echo $dispMonth;?>,
	    	} );
		} );

		 $(function(){
		        $("#tabMenu li a").on("click", function() {
		            $("#tabBoxes div").hide();
		            $($(this).attr("href")).fadeToggle();
		        });
		        return false;
		    });

	    $(function(){
	        $("#acMenu dt").on("click", function() {
	            $(this).next().slideToggle();
	        });
	    });

		jQuery( function() {
		    jQuery( '.day-calendar' ) . click( function() {
		    	console.log($(this).data('year'));
		    	console.log($(this).data('month'));
				console.log($(this).data('day'));
				$('#year').val($(this).data('year'));
				$('#month').val($(this).data('month'));
				$('#day').val($(this).data('day'));

		        jQuery( '#jquery-ui-dialog' ) . dialog( 'open' );
		    } );
		    var date = 250;
		    var name = jQuery( '#jquery-ui-dialog-form-name' );
		    var hour = jQuery( '#jquery-ui-dialog-form-hour' );
		    var minute = jQuery( '#jquery-ui-dialog-form-minute' );
		    var endhour = jQuery( '#jquery-ui-dialog-form-endhour' );
		    var endminute = jQuery( '#jquery-ui-dialog-form-endminute' );

		    jQuery( '#jquery-ui-dialog' ) . dialog( {
		        autoOpen: false,
		        width: 350,
		        show: 'explode',
		        hide: 'explode',
		        modal: true,
		        buttons: {
		            '登録': function() {
		                if ( name . val() || hour . val() ) {

		                	$.ajax({
			  				      type: 'POST',
			  				      url:'test.php',
			  				      data:{
									"name": $('select[name="jquery-ui-dialog-form-name"]').val(),
			  						"insertYear": $(':hidden[name="year"]').val(),
			  						"insertMonth": $(':hidden[name="month"]').val(),
			  						"insertDay": $(':hidden[name="day"]').val()

			  				      },
			  				      success:function(data) {
			  				        alert("登録しました。");
			  				      },
			  				      error:function(XMLHttpRequest, textStatus, errorThrown) {

			  				   	 　}
			  				 });

		                    jQuery( 'div.work-calendar' ) . append(
		                        '<div id="work"><span id="change" data-name=name>' + name . val() +
		                        '</span> ' + hour . val() +
		                        ':' + minute . val() + '~' + endhour . val() +
		                        ':' + endminute . val() + '&nbsp;講  </div>'
		                    );
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
			    $('.changename').text($('span#change').data('name'));
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
	                if ( hour2 . val() ) {
	                    jQuery( 'span#time' ) . text(
	    	                hour2 . val() + ':' + minute2 . val() +
	    	                '~' + endhour2 . val() + ':' + endminute2 . val()
	                    );
	                    jQuery( this ).dialog( 'close' );
	                }
	                jQuery( this ) . dialog( 'close' );
	            },
	            '削除': function() {
	            	$("div#work").remove();
	                jQuery( this ) . dialog( 'close' );
	            },
	            'キャンセル': function() {
	                jQuery( this ) . dialog( 'close' );
	            },
	        }
	    } );
	} );
		</script>
		<style>

			#jquery-ui-tabs {
   				font-size: 16px;
			}

			#jquery-ui-tabs ul li{
				float: right;
			}

		</style>
		<title>メインメニュー画面</title>
	</head>
	<body>
		<div class="container">
			<header class="box">
				<h1 class="title">勤怠管理システム</h1>
			</header>

			<div class="box width70 clearfix">
				<div class="userInfo float-left">
					<p>ユーザー名 : admin / 権限 : 管理者</p>
				</div>
				<div class="userInfo float-right">
					<p><a href="#">ログアウト</a></p>
				</div>
			</div>

			<div class="box menu"><!-- ヘッダーメニュー-->
				<ul id="dropmenu">
	 				<li><a href="#">メニュー</a>
	   			 		<ul>
	    				</ul>
	 				 </li>
	  				<li><a href="ovarallWarkTime.html">勤務時間表</a>
	   					<ul>
	   					</ul>
	 				</li>
	 				<li><a href="settingHoliday.html">休日設定</a>
	    				<ul>
	   					</ul>
	 				</li>
	  				<li><a href="#">ユーザー設定</a>
	   					<ul>
     					 	<li><a href="changePassword.html">パスワード変更</a></li>
	     					<li><a href="updateUser.html">ユーザー設定変更</a></li>
	     					<li><a href="insertUser.html">ユーザー登録</a></li>
	   					</ul>
	  				</li>
	  				<li><a href="settingRestTime.html">休憩時間設定</a>
	   					<ul>
	   					</ul>
	  				</li>
				</ul>
			</div>

			<div class="box main-container mainMenuCalendar clearfix">
				<br>
				<br>

				<div id="jquery-ui-tabs">
    				<ul>
    					<li><a href="#jquery-ui-tabs-3">3ヶ月</a></li>
        				<li><a href="#jquery-ui-tabs-2">2ヶ月</a></li>
        				<li><a href="#jquery-ui-tabs-1">1ヶ月</a></li>
        				<form action="" method="POST">
        					<input type="submit" name="reset" value="本日の日付に戻る">
        				</form>
    				</ul>


						<dl id="acMenu">
							<dt>曜日一括設定</dt>
								<dd>
									<div id="holidaybox">
										<ul id="tabMenu" class="clearfix">
											<li><a href="#tabBox1">登録</a></li>
											<li><a href="#tabBox2">削除</a></li>
										</ul>

										<div class="holidayForm">

											<div id="tabBoxes">

												<div id="tabBox1">
													月<input type="checkbox" name="dayOfWeek" value="monday" >
													火<input type="checkbox" name="dayOfWeek" value="tuesday" >
													水<input type="checkbox" name="dayOfWeek" value="wednesday" >
													木<input type="checkbox" name="dayOfWeek" value="thursday" >
													金<input type="checkbox" name="dayOfWeek" value="fryday" >
													土 <input type="checkbox" name="dayOfWeek" value="saturday" >
													日 <input type="checkbox" name="dayOfWeek" value="sunday">

													<br>
													<br>

													<strong>期間選択：</strong>
													&nbsp;
													開始日付 ： <input type="date" name="startHoliday">
													終了日付 ： <input type="date" name="endHoliday">
													<br>
													<br>
													氏名：
													<select name="nameSel">
										            	<option value="神田太郎">神田太郎</option>
										            	<option value="東京太郎">東京太郎</option>
										            	<option value="秋葉流">秋葉流</option>
										            </select>
										        	&nbsp;
													 出勤時間：
													 <select name="startWorkHour">
										            	<option value="8">8</option>
										            	<option value="9">9</option>
										            	<option value="10">10</option>
										            </select>
													時
													<select name="startWorkMinute">
										            	<option value="00">00</option>
										            	<option value="10">10</option>
										            	<option value="20">20</option>
										            	<option value="30">30</option>
										            	<option value="40">40</option>
										            	<option value="50">50</option>
										            </select>
													 分
													 &nbsp;
													 退勤時間：
													 <select name="startWorkHour">
										            	<option value="18">18</option>
										            	<option value="19">19</option>
										            	<option value="20">20</option>
										            </select>
													 時
													 <select name="startWorkMinute">
										            	<option value="00">00</option>
										            	<option value="10">10</option>
										            	<option value="20">20</option>
										            	<option value="30">30</option>
										            	<option value="40">40</option>
										            	<option value="50">50</option>
										            </select>
													 分

										            <br>
										            <br>

													<input type="submit" value="登録">

												</div>
												<div id="tabBox2">
														月<input type="checkbox" name="dayOfWeek" value="monday" >
													火<input type="checkbox" name="dayOfWeek" value="tuesday" >
													水<input type="checkbox" name="dayOfWeek" value="wednesday" >
													木<input type="checkbox" name="dayOfWeek" value="thursday" >
													金<input type="checkbox" name="dayOfWeek" value="fryday" >
													土 <input type="checkbox" name="dayOfWeek" value="saturday" >
													日 <input type="checkbox" name="dayOfWeek" value="sunday">

													<br>
													<br>

													<strong>期間選択：</strong>
													&nbsp;
													開始日付 ： <input type="date" name="startHoliday">
													終了日付 ： <input type="date" name="endHoliday">
													<br>
													<br>
													氏名：
													<select name="nameSel">
										            	<option value="神田太郎">神田太郎</option>
										            	<option value="東京太郎">東京太郎</option>
										            	<option value="秋葉流">秋葉流</option>
										            </select>
										        	&nbsp;
													 出勤時間：
													 <select name="startWorkHour">
										            	<option value="8">8</option>
										            	<option value="9">9</option>
										            	<option value="10">10</option>
										            </select>
													時
													<select name="startWorkMinute">
										            	<option value="00">00</option>
										            	<option value="10">10</option>
										            	<option value="20">20</option>
										            	<option value="30">30</option>
										            	<option value="40">40</option>
										            	<option value="50">50</option>
										            </select>
													 分
													 &nbsp;
													 退勤時間：
													 <select name="startWorkHour">
										            	<option value="18">18</option>
										            	<option value="19">19</option>
										            	<option value="20">20</option>
										            </select>
													 時
													 <select name="startWorkMinute">
										            	<option value="00">00</option>
										            	<option value="10">10</option>
										            	<option value="20">20</option>
										            	<option value="30">30</option>
										            	<option value="40">40</option>
										            	<option value="50">50</option>
										            </select>
													 分

										            <br>
										            <br>

													<input type="submit" value="削除">

												</div>


											</div>

										</div>
									</div>

							</dd>

						</dl>


    				<div id="jquery-ui-tabs-1"><!-- 1ヶ月分のカレンダーを表示 -->

						<table>
							<tr>
								<th width="100%" colspan="7" style="background-color: #B3F8FA; text-align: center; font-weight: bold;">
									<a href="mainMenu-admin.php?kyonen=<?php echo $year0;?>&month=<?php echo $month0;?>&disp=2">&lt;&lt;</a>
									 &nbsp;&nbsp;
									 <a href="mainMenu-admin.php?sengetu=<?php echo $month0;?>&year=<?php echo$year0;?>&disp=2">&lt;</a>
									 &nbsp;&nbsp;&nbsp;
									<?php echo $year0; ?>年<?php echo $month0; ?>月
									&nbsp;&nbsp;
									<a href="mainMenu-admin.php?yokugetu=<?php echo $month0;?>&year=<?php echo$year0;?>&disp=2">&gt;</a>
									&nbsp;&nbsp;&nbsp;
									<a href="mainMenu-admin.php?rainen=<?php echo $year0;?>&month=<?php echo $month0;?>&disp=2">&gt;&gt;</a>
								</th>
							</tr>
    						<tr>
        						<th style="color: red;">日</th>
        						<th>月</th>
        						<th>火</th>
       							<th>水</th>
        						<th>木</th>
        						<th>金</th>
        						<th style="color: blue;">土</th>
    						</tr>

		    				<tr>
		    					<?php
		    						$cnt = 0;
		    					?>
    							<?php foreach ($calendar0 as $key => $value): ?>

								<?php

									//現在の日にちのカレンダーかつ,日付が一致しループの一回目の場合、本日日付のカレンダーの色を変更する

									if($year0 == $year && $month0 == $month && $value['day'] == $today && $calCnt == 0){
										$stylecolor="#EEF1F1";
									}else{
										$stylecolor="#FFFFFF";
									}

									//土日の色を変更する

		        					if($cnt == 0){
										$fontcolor="red";
		    						}else if($cnt == 6){
										$fontcolor="blue";
		    						}else{
		    							$fontcolor="#000000";
		    						}
		        				?>

								<td style="background-color: <?php echo $stylecolor;?>; color:<?php echo $fontcolor;?>;">
		        					<?php $cnt++; ?>

		        					<div class="day-calendar" data-year="<?php echo $year0;?>" data-month="<?php echo $month0;?>" data-day="<?php echo $value['day']; ?>">
		        						<?php echo $value['day']; ?>
		       						</div>
		        					<?php if($value['day'] == 8){?>
		        					<div class="work-calendar">
		        						<div id="work"><span id="change" data-name="神田太郎">神田太郎</span>  <span id="time">12:00~18:00</span>  講</div>
		        					</div>
		        					<?php }?>
		        				</td>


		    					<?php if ($cnt == 7): ?>
		    				</tr>

		    				<tr>
		    					<?php $cnt = 0; ?>

		   						<?php endif; ?>
		    					<?php
		    						endforeach;
		    					?>
		   				 	</tr>
						</table>
					</div>

   					 <div id="jquery-ui-tabs-2">
						<?php
							//for文を2か月分ループさせる
							for($calCnt = 0 ; $calCnt < 2 ; $calCnt++):
						?>

							<table>
								<tr>
									<th width="100%" colspan="7" style="background-color: #B3F8FA; text-align: center; font-weight: bold;">

										<?php if($calCnt == 0):?>
											<a href="mainMenu-admin.php?kyonen=<?php echo $year0;?>&month=<?php echo $month0;?>">&lt;&lt;</a>
											 &nbsp;&nbsp;
											 <a href="mainMenu-admin.php?sengetu=<?php echo $month0;?>&year=<?php echo$year0;?>">&lt;</a>
									 		&nbsp;&nbsp;&nbsp;
										<?php endif;?>

										<?php echo ${'year'.$calCnt}; ?>年<?php echo ${'month'.$calCnt}; ?>月

										<?php if($calCnt == 0):?>
											&nbsp;&nbsp;
											<a href="mainMenu-admin.php?yokugetu=<?php echo $month0;?>&year=<?php echo$year0;?>">&gt;</a>
											&nbsp;&nbsp;&nbsp;
											<a href="mainMenu-admin.php?rainen=<?php echo $year0;?>&month=<?php echo $month0;?>">&gt;&gt;</a>
										<?php endif;?>

									</th>
								</tr>
	    						<tr>
	        						<th style="color: red;">日</th>
	        						<th>月</th>
	        						<th>火</th>
	       							<th>水</th>
	        						<th>木</th>
	        						<th>金</th>
	        						<th style="color: blue;">土</th>
	    						</tr>

			    				<tr>
			    					<?php $cnt = 0; ?>
	    							<?php foreach (${'calendar'.$calCnt} as $key => $value): ?>

									<?php
										if($year0 == $year && $month0 == $month && $value['day'] == $today && $calCnt == 0){
											$stylecolor="#EEF1F1";
										}else{
											$stylecolor="#FFFFFF";
										}

			        					if($cnt == 0){
											$fontcolor="red";
			    						}else if($cnt == 6){
											$fontcolor="blue";
			    						}else{
			    							$fontcolor="#000000";
			    						}
			        				?>

									<td style="background-color: <?php echo $stylecolor;?>; color:<?php echo $fontcolor;?>;">
			        					<?php $cnt++; ?>

			        					<div class="day-calendar" data-year="<?php echo ${'year'.$calCnt};?>" data-month="<?php echo ${'month'.$calCnt};?>" data-day="<?php echo $value['day']; ?>">
			        						<?php echo $value['day']; ?>
			       						</div>
			        					<?php if($value['day'] == 8){?>
			        					<div class="work-calendar">
			        						<div id="work"><span id="change" data-name="神田太郎">神田太郎</span>  <span id="time">12:00~18:00</span>  講</div>
			        					</div>
			        					<?php }?>
			        				</td>


			    					<?php if ($cnt == 7): ?>
			    				</tr>

			    				<tr>
			    					<?php $cnt = 0; ?>

			   						<?php endif; ?>
			    					<?php   endforeach; ?>
			   				 	</tr>
							</table>

						<?php endfor;?>
					</div><!-- jquery-ui-tabs-2 -->

   					 <div id="jquery-ui-tabs-3">

						<?php
							//for文を3か月分ループさせる
							for($calCnt = 0 ; $calCnt < 3 ; $calCnt++):
						?>

							<table>
								<tr>
									<th width="100%" colspan="7" style="background-color: #B3F8FA; text-align: center; font-weight: bold;">

										<?php if($calCnt == 0):?>
											<a href="mainMenu-admin.php?kyonen=<?php echo $year0;?>&month=<?php echo $month0;?>&disp=0">&lt;&lt;</a>
											 &nbsp;&nbsp;
											 <a href="mainMenu-admin.php?sengetu=<?php echo $month0;?>&year=<?php echo$year0;?>&disp=0">&lt;</a>
											 &nbsp;&nbsp;&nbsp;
										<?php endif;?>

										<?php echo ${'year'.$calCnt}; ?>年<?php echo ${'month'.$calCnt}; ?>月

										<?php if($calCnt == 0):?>
											&nbsp;&nbsp;
											<a href="mainMenu-admin.php?yokugetu=<?php echo $month0;?>&year=<?php echo$year0;?>&disp=0">&gt;</a>
											&nbsp;&nbsp;&nbsp;
											<a href="mainMenu-admin.php?rainen=<?php echo $year0;?>&month=<?php echo $month0;?>&disp=0">&gt;&gt;</a>
										<?php endif;?>

									</th>
								</tr>
	    						<tr>
	        						<th style="color: red;">日</th>
	        						<th>月</th>
	        						<th>火</th>
	       							<th>水</th>
	        						<th>木</th>
	        						<th>金</th>
	        						<th style="color: blue;">土</th>
	    						</tr>

			    				<tr>
			    					<?php $cnt = 0; ?>
	    							<?php foreach (${'calendar'.$calCnt} as $key => $value): ?>

									<?php
										if($year0 == $year && $month0 == $month && $value['day'] == $today && $calCnt == 0){
											$stylecolor="#EEF1F1";
										}else{
											$stylecolor="#FFFFFF";
										}

			        					if($cnt == 0){
											$fontcolor="red";
			    						}else if($cnt == 6){
											$fontcolor="blue";
			    						}else{
			    							$fontcolor="#000000";
			    						}
			        				?>

									<td style="background-color: <?php echo $stylecolor;?>; color:<?php echo $fontcolor;?>;">
			        					<?php $cnt++; ?>

			        					<div  class="day-calendar" data-year="<?php echo ${'year'.$calCnt};?>" data-month="<?php echo ${'month'.$calCnt};?>" data-day="<?php echo $value['day']; ?>">
			        						<?php echo $value['day']; ?>
			       						</div>
			        					<?php if($value['day'] == 8){?>
			        					<div class="work-calendar">
			        						<div id="work"><span id="change" data-name="神田太郎">神田太郎</span>  <span id="time">12:00~18:00</span>  講</div>
			        					</div>
			        					<?php }?>
			        				</td>


			    					<?php if ($cnt == 7): ?>
			    				</tr>

			    				<tr>
			    					<?php $cnt = 0; ?>

			   						<?php endif; ?>
			    					<?php endforeach; ?>
			   				 	</tr>
							</table>

						<?php endfor;?>

   					 </div><!-- jquery-ui-tabs-3" -->

				</div><!-- jquery-ui-tabs -->

			</div><!-- box main-container  -->



<div id="jquery-ui-dialog" title="勤務登録">
    <form method="post" id="insertForm">
    <fieldset>
        <p>
            <label for="jquery-ui-dialog-form-name">名前</label>
            <select name="jquery-ui-dialog-form-name" id="jquery-ui-dialog-form-name" class="text ui-widget-content ui-corner-all" />
            	<option value="神田太郎">神田太郎</option>
            	<option value="東京太郎">東京太郎</option>
            	<option value="秋葉流">秋葉流</option>
            </select>
        </p>

        <p>
            <label for="jquery-ui-dialog-form-hour">出勤時間</label>
            <select name="jquery-ui-dialog-form-hour" id="jquery-ui-dialog-form-hour" class="text ui-widget-content ui-corner-all" />
            	<option value="1">1</option>
            	<option value="2">2</option>
            	<option value="3">3</option>
            	<option value="4">4</option>
            </select>
   			時
   			<select name="jquery-ui-dialog-form-minute" id="jquery-ui-dialog-form-minute" class="text ui-widget-content ui-corner-all" />
            	<option value="00">00</option>
            	<option value="30">30</option>
            </select>
			 分
        </p>

        <p>
            <label for="jquery-ui-dialog-form-endhour">退勤時間</label>
            <select name="jquery-ui-dialog-form-endhour" id="jquery-ui-dialog-form-endhour" class="text ui-widget-content ui-corner-all" />
            	<option value="17">17</option>
            	<option value="18">18</option>
            	<option value="19">19</option>
            	<option value="20">20</option>
            </select>
   			時
   			<select name="jquery-ui-dialog-form-endminute" id="jquery-ui-dialog-form-endminute" class="text ui-widget-content ui-corner-all" />
            	<option value="00">00</option>
            	<option value="30">30</option>
            </select>
			 分
        </p>
        <input type="hidden" name="year" id="year">
        <input type="hidden" name="month" id="month">
        <input type="hidden" name="day" id="day">
    </fieldset>
    </form>
</div>

<div id="jquery-ui-dialog2" title="出勤情報修正">
    <form>
    <fieldset>
        <p class="changename"></p>
        <p>
            <label for="jquery-ui-dialog-form-hour2">出勤時間</label>
            <select name="jquery-ui-dialog-form-hour2" id="jquery-ui-dialog-form-hour2" class="text ui-widget-content ui-corner-all" />
            	<option value="1">1</option>
            	<option value="2">2</option>
            	<option value="3">3</option>
            	<option value="4">4</option>
            </select>
   			時
   			<select name="jquery-ui-dialog-form-minute2" id="jquery-ui-dialog-form-minute2" class="text ui-widget-content ui-corner-all" />
            	<option value="00">00</option>
            	<option value="30">30</option>
            </select>
			 分
        </p>

        <p>
            <label for="jquery-ui-dialog-form-endhour2">退勤時間</label>
            <select name="jquery-ui-dialog-form-endhour2" id="jquery-ui-dialog-form-endhour2" class="text ui-widget-content ui-corner-all" />
            	<option value="17">17</option>
            	<option value="18">18</option>
            	<option value="19">19</option>
            	<option value="20">20</option>
            </select>
   			時
   			<select name="jquery-ui-dialog-form-endminute2" id="jquery-ui-dialog-form-endminute2" class="text ui-widget-content ui-corner-all" />
            	<option value="00">00</option>
            	<option value="30">30</option>
            </select>
			 分
        </p>

    </fieldset>
    </form>
</div>

			<footer class="box footer">
				<p>Copyright © 2010-2015 FusionOne Co.,Ltd. All Rights Reserved.</p>
			</footer>

		</div>	<!-- container -->
	</body>
</html>
