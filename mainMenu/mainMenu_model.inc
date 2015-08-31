<?php
/**
 * =====================================================================================
	プログラム名  ：	勤怠管理システム（Web版）
 	プログラム説明：社員の勤怠情報を管理するシステムです。
 				管理者はカレンダーを使用して視覚的に勤怠の登録、削除、変更
 				を行えるほか各社員の勤怠情報の閲覧、休日、休憩時間の設定
 				機能を使用することができます。

 				勤怠情報とカレンダー部分はPDF,EXCEL出力することが可能です。
 	作成者        ：	水島創太
 	作成日        ：	2015/8/28
	=====================================================================================
 */

class mainMenu_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

		private $thisYear;			//今年
		private $thisMonth;			//今月
		private $today;				//今日
		private $year;				//表示年格納用配列
		private $month;				//表示月格納用配列
		private $year1;				//表示月の1ヶ月後の年
		private $month1;			//表示月の1ヶ月の月
		private $year2;				//表示月の2ヶ月の年
		private $month2;			//表示月の2ヶ月後の月
		private $period;			//年月変更値
		private $dispMonth;			//カレンダー表示月数
		private $calendar;			//日付格納用3次元配列
		private $workerList;		//勤怠情報格納用配列
		private $monthWorkerList;	//一ヶ月分の勤怠情報格納配列

	/*====================================================================================
	 *概要：
	 *	updateUser_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	function __construct(){

		$this->init();

	}

	/*====================================================================================
	 *概要：
	 *	init
	 *機能説明：
	 *	プロパティ初期化
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

 	private function init(){

		$this->nowYear 	= "";	//今年
		$this->nowMonth = "";	//今月
		$this->nowday 	= "";	//今日
		$this->year 	= "";	//表示年
		$this->month 	= "";	//表示月
		$this->year1  	= "";	//1ヶ月先の表示年
		$this->month1 	= "";	//1ヶ月先の表示月
		$this->year2  	= "";	//2ヶ月先の表示年
		$this->month2 	= "";	//2ヶ月先の表示月
		$this->period= "";		//年月変更値
		$this->dispMonth = "";	//カレンダー表示月数
		$this->workerList = "";	//勤怠情報格納用配列
		$this->monthWorkerList = "";	//一ヶ月分の勤怠情報格納配列

	}

	/*====================================================================================
	 *概要：
	 *	setter関数
	 *機能説明：
	 *	値をフィールド変数に格納
	 *引数：
	 *	各種格納する値
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
		//今年
		public function setThisYear($param)
		{
			$this->thisYear = $param;
		}

		//今月

		public function setThisMonth($param)
		{
			$this->thisMonth = $param;
		}

		//今日
		public function setToday($param)
		{
			$this->today = $param;
		}

		//表示年格納用配列
		public function setYear($param)
		{
			$this->year = $param;
		}

		//表示月格納用配列
		public function setMonth($param)
		{
			$this->month = $param;
		}

		//年月変更値
		public function setPeriod($param)
		{
			$this->period = $param;
		}


		//カレンダー表示月数
		public function setDispMonth($param)
		{
			$this->dispMonth = $param;
		}

		//日付格納用3次元配列
		public function setCalendar($param)
		{
			$this->calendar = $param;
		}

		//勤怠情報格納用配列
		public function setWorkerList($param)
		{
			$this->workerList = $param;
		}


	/*====================================================================================
	 *概要：
	 *	getter関数
	 *機能説明：
	 *	値をフィールド変数から取得
	 *引数：
	 *	なし
	 *戻り値：
	 *	各種格納した値
	 *備考：
	 *	作成日)	2015/7/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//今年
		public function getThisYear()
		{
			return $this->thisYear;
		}

		//今月

		public function getThisMonth()
		{
			return $this->thisMonth;
		}

		//今日
		public function getToday()
		{
			return $this->today;
		}

		//表示年格納用配列
		public function getYear()
		{
			return $this->year;
		}

		//表示月格納用配列
		public function getMonth()
		{
			return $this->month;
		}

		//表示年
		public function getSelYear($key)
		{
			return $this->year[$key];
		}
		//表示月
		public function getSelMonth($key)
		{
			return $this->month[$key];
		}

		//年月変更値
		public function getPeriod()
		{
			return $this->period;
		}


		//カレンダー表示月数
		public function getDispMonth()
		{
			return $this->dispMonth;
		}

		//日付格納用3次元配列
		public function getCalendar()
		{
			return $this->calendar;
		}

		//日付格納用2次元配列
		public function getSelCalendar($key)
		{
			return $this->calendar[$key];
		}

		//勤怠情報格納用配列
		public function getWorkerList()
		{
			return $this->workerList;
		}

		//勤怠情報
		public function getSelWorkerList($key1,$key2)
		{
			return $this->workerList[$key1][$key2];
		}


	/*====================================================================================
	 *概要：
	 *	getForm関数
	 *機能説明：
	 *	フォームに入力された値を受け取る
	 *引数：
	 *	フォーム入力された値
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//フォーム入力からの数値受け取り関数
		public function getForm(){

			//去年、来年に遷移する際の処理
			if(isset($_GET["changeTime"]))
			{
				$comand = $_GET["changeTime"];

				if($comand == "kyonen")
				{
					//月日の変化選択部分に値を格納
					$this->period = "-1 year";

				}

				if($comand == "rainen")
				{
					//月日の変化選択部分に値を格納
					$this->period = "+1 year";

				}

				if($comand == "sengetu")
				{
					//月日の変化選択部分に値を格納
					$this->period = "-1 month";
				}

				if($comand == "yokugetu")
				{
					//月日の変化選択部分に値を格納
					$this->period = "+1 month";
				}
			}


			//来年のカレンダー表示のリンクからの遷移かをチェック
			if(isset($_GET["kyonen"])){


			}

			//カレンダー表示月数
			if(isset($_GET["disp"])){

				$this->dispMonth = $_GET["disp"];

			}else{

				$this->dispMonth = 1;

			}

		}

	/*====================================================================================
	 *概要：
	 *	processing
	 *機能説明：
	 *	全体の処理判定を行う
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/7/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function processing($db)
		{
			//プロパティ関数の初期値をセット
			$this->thisYear = date('Y');
			$this->thisMonth = date('n');
			$this->today  = date('j');

			//表示する年月を取得
			$this->setTime();

			//表示するカレンダー部分を取得
			$this->insertCalendar($db);
		}

	/*====================================================================================
	 *概要：
	 *	setTime()
	 *機能説明：
	 *	プロパティ変数に適切な年月日を挿入する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function setTime()
		{
			//
			if($this->period == ""){
				//現在の日付データを日付情報として格納する。
				if(!isset($_POST["reset"]))
				{
					$this->year[] = $this->thisYear;	//今年
					$this->month[] = $this->thisMonth;	//今月
				}

			}else{

				//初期値以外の場合、それぞれの処理にあった年月を挿入する。

					if(isset($_POST["reset"]))
					{
						$this->year[] = $this->thisYear;	//今年
						$this->month[] = $this->thisMonth;	//今月
					}else{
						$this->year[] = date('Y', strtotime($_GET["year"]."-".$_GET["month"]."-1 ".$this->period));
						$this->month[] = date('n', strtotime($_GET["year"]."-".$_GET["month"]."-1 ".$this->period));
					}





			}

			//2ヶ月分の月情報を変数に格納
			for($i=1;$i<=2;$i++)
			{
				//1ヶ月先の年を取得
				$this->year[]  = date('Y', strtotime($this->getSelYear(0)."-".$this->getSelMonth(0)."-1 +".$i." month"));
				//1ヶ月先の月を取得
				$this->month[] = date('n', strtotime($this->getSelYear(0)."-".$this->getSelMonth(0)."-1 +".$i." month"));
			}

		}

	/*====================================================================================
	 *概要：
	 *	insertCalendar()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$calendarListに格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function insertCalendar($db)
		{
			//年数の配列分ループをまわして日付情報を格納する
			for($calNum=0 ; $calNum < count($this->year) ;$calNum++):

				//日付を格納する変数
				$calendar = "";

				// 月末日を取得
				$last_day = date('t', strtotime($this->year[$calNum]."-".$this->month[$calNum]."-1"));

				//日付情報を格納するクラスclanderを「clander + ループ回数」の変数名で配列として初期化
				$j = 0;

				// 月末日までループ

				for ($i = 1; $i < $last_day + 1; $i++) {

					// 曜日を取得
					$week[] = date('w', mktime(0, 0, 0, $this->month[$calNum], $i, $this->year[$calNum]));

					// 1日の場合
					if ($i == 1) {

						// 1日目の曜日までをループ
						for ($s = 1; $s <= $week[$calNum]; $s++) {

							// 前半に空文字をセット
							$calendar[$j]['day'] = '';
							$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$calendar[$j]['day']);
							$j++;
						}
					}

					// 配列に日付をセット
					$calendar[$j]['day'] = $i;
					$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$calendar[$j]['day']);
					$j++;

					// 月末日の場合
					if ($i == $last_day) {

						// 月末日から残りをループ
						for ($e = 1; $e <= 6 - $week[$calCnt]; $e++) {

							// 後半に空文字をセット
							$calendar[$j]['day'] = '';
							$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$calendar[$j]['day']);
							$j++;
						}
					}
				}

				$this->calendar[] = $calendar;
				$this->workerList[] = $this->monthWorkerList;

				//1ヶ月分のデータを格納する変数を初期化
				$this->monthWorkerList = "";
			endfor;
		}

	/*====================================================================================
	 *概要：
	 *	searchWorkInfo($db,$year,$month,$day)
	 *機能説明：
	 *	日付に合致する勤怠情報をDBから取得し、その情報があれば$searchWorkListに格納,なければ
	 *	空白を挿入する。
	 *	情報があればtrueをない場合はfalseを返す。
	 *引数：
	 *	データベース情報,年,月,日
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function searchWorkInfo($db,$year,$month,$day)
		{
			//日付データ格納用配列を定義
			 $workerInfo = "";

			//SQL構文をセット
			$sql = "SELECT A.accountid,A.name,P.`p-name`,C.code,WP.day,WP.workstarttime,WP.workendtime FROM accountinfo A INNER JOIN positioninfo P ON A.positionid = P.positionid INNER JOIN colorinfo C ON A.colorid = C.colorid INNER JOIN workplaninfo WP ON A.accountid = WP.accountid ";
			$sql .= "WHERE WP.day = '{$year}-{$month}-{$day}'";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0){

				//繰り返し処理を使用して全取得データをworkerListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$workerInfo[] = $row;

				endwhile;

				//格納した日付データ配列を$workerListに追加
				$this->monthWorkerList[] = $workerInfo;

				//戻り値にtureを挿入
				$tf = true;

			}else{

				//日付データ配列に空白をセット
				$workerInfo['accountid'] = "";
				$workerInfo['name'] = "";
				$workerInfo['p-name'] = "";
				$workerInfo['code'] = "";
				$workerInfo['workstarttime'] = "";
				$workerInfo['workendtime'] = "";

				$workerInfo2[] = $workerInfo;

				$this->monthWorkerList[] = $workerInfo2;

				//戻り値にfalseを挿入
				$tf = false;

			}

			//検索結果の開放
			mysql_free_result($result);

			//戻り値として真偽を返す
			return $tf;
		}

	/*====================================================================================
	 *概要：
	 *	searchUser()
	 *機能説明：
	 *	$useridで検索し検索結果を受け取ってuserinfoに格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */



	/*====================================================================================
	 *概要：
	 *	update
	 *機能説明：
	 *	プロパティ変数$userに該当するユーザーデータを更新する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */


}

/*
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

$year1  = date('Y', strtotime(date('Y')."-".date('n')."-1 +1 month"));	//1ヶ月先の年を取得
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

}*/
?>