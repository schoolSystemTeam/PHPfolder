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
		private $year1;				//フォーム入力年
		private $month1;			//フォーム入力月
		private $day1;				//フォーム入力日
		private $accountid;			//フォーム入力アカウントID
		private $workstarthour;		//フォーム入力勤務開始時
		private $workstartminute;	//フォーム入力勤務開始分
		private $workendhour;		//フォーム入力勤務終了時
		private $workendminute;		//フォーム入力勤務終了分
		private $period;			//年月変更値
		private $dispMonth;			//カレンダー表示月数
		private $calendar;			//日付格納用3次元配列
		private $workerList;		//勤怠情報格納用配列
		private $monthWorkerList;	//一ヶ月分の勤怠情報格納配列
		private $accountList;		//ユーザー情報格納用配列
		private $execute;			//処理種別

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

		$this->nowYear	 = "";			//今年
		$this->nowMonth  = "";			//今月
		$this->nowday 	 = "";			//今日
		$this->year 	 = "";			//表示年
		$this->month 	 = "";			//表示月
		$this->year1  	 = "";			//フォーム入力年
		$this->month1 	 = "";			//フォーム入力月
		$this->day1 	 = "";			//フォーム入力日
		$this->accountid = "";			//フォーム入力アカウントID
		$this->workstarthour = "";		//フォーム入力勤務開始時
		$this->workstartminute = "";	//フォーム入力勤務開始分
		$this->workendhour   = "";		//フォーム入力勤務終了時
		$this->workendminute = "";		//フォーム入力勤務終了分
		$this->period= "";				//年月変更値
		$this->dispMonth = "";			//カレンダー表示月数
		$this->workerList = "";			//勤怠情報格納用配列
		$this->monthWorkerList = "";	//一ヶ月分の勤怠情報格納配列
		$this->accountList = "";		//ユーザー情報格納用配列
		$this->execute = "";		//処理種別


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

		//フォーム入力年
		public function setYear1($param)
		{
			$this->year1 = $param;
		}

		//フォーム入力月
		public function setMonth1($param)
		{
			$this->month1 = $param;
		}

		//フォーム入力日
		public function setDay1($param)
		{
			$this->day1 = $param;
		}

		//フォーム入力アカウントID
		public function setAccountid($param)
		{
			$this->accountid = $param;
		}

		//フォーム入力勤務開始時
		public function setWorkStartHour($param)
		{
			$this->workstarthour = $param;
		}

		//フォーム入力勤務開始分
		public function setWorkStartMinute($param)
		{
			$this->workstartminute = $param;
		}

		//フォーム入力勤務終了時
		public function setWorkEndHour($param)
		{
			$this->workendhour = $param;
		}

		//フォーム入力勤務終了分
		public function setWorkEndMinute($param)
		{
			$this->workendminute = $param;
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

		//ユーザー情報格納用配列
		public function setAccountList($param)
		{
			$this->accountList = $param;
		}

		//処理種別
		public function setExecute($param)
		{
			$this->execute = $param;
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

		//フォーム入力年
		public function getYear1()
		{
			return $this->year1;
		}

		//フォーム入力月
		public function getMonth1()
		{
			return $this->month1;
		}

		//フォーム入力日
		public function getDay1()
		{
			return $this->day1;
		}

		//フォーム入力アカウントID
		public function getAccountid()
		{
			return $this->accountid;
		}

		//フォーム入力勤務開始時
		public function getWorkStartHour()
		{
			return $this->workstarthour;
		}

		//フォーム入力勤務開始分
		public function getWorkStartMinute()
		{
			return $this->workstartminute;
		}

		//フォーム入力勤務終了時
		public function getWorkEndHour()
		{
			return $this->workendhour;
		}

		//フォーム入力勤務終了分
		public function getWorkEndMinute()
		{
			return $this->workendminute;
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

		//ユーザー情報格納用配列
		public function getAccountList()
		{
			return $this->accountList;
		}

		//処理種別
		public function getExecute()
		{
			return $this->execute;
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
			//フォーム入力アカウントID
			if(isset($_POST['accountid']))
			{
				$this->accountid = $_POST['accountid'];
			}

			//フォーム入力年
			if(isset($_POST['formYear']))
			{
				$this->year1 = $_POST['formYear'];
			}

			//フォーム入力月
			if(isset($_POST['formMonth']))
			{
				$this->month1 = $_POST['formMonth'];
			}

			//フォーム入力日
			if(isset($_POST['formDay']))
			{
				$this->day1 = $_POST['formDay'];
			}

			//フォーム入力勤務開始時
			if(isset($_POST['workstarthour']))
			{
				$this->workstarthour = $_POST['workstarthour'];
			}

			//フォーム入力勤務開始分
			if(isset($_POST['workstartminute']))
			{
				$this->workstartminute = $_POST['workstartminute'];
			}

			//フォーム入力勤務終了時
			if(isset($_POST['workendhour']))
			{
				$this->workendhour = $_POST['workendhour'];
			}

			//フォーム入力勤務終了分
			if(isset($_POST['workendminute']))
			{
				$this->workendminute = $_POST['workendminute'];
			}

			//処理種別
			if(isset($_POST["execute"]))
			{
				$this->execute = $_POST["execute"];
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

			//全アカウント情報を取得
			$this->selectAllAccount($db);

			//表示する年月を取得
			$this->setTime();

			//表示するカレンダー部分を取得
			$this->insertCalendar($db);

			//登録機能の場合、勤怠情報を登録する
			if($this->execute == "insert"){
				$this->insertWorkPlan($db);
			}

			//削除機能の場合、勤怠情報を削除する
			if($this->execute == "delete"){
				$this->deleteWorkPlan($db);
			}

			//更新機能の場合、勤怠情報を更新する
			if($this->execute == "update"){
				$this->updateWorkPlan($db);
			}

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
	 *	selectAllAccount()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$accountListに格納する。
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

		private function selectAllAccount($db){

			//MySQL文の用意
			$sql = "SELECT * FROM accountinfo";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0):

				//繰り返し処理を使用して全取得データをbookListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$this->accountList[] = $row;

				endwhile;

			endif;

			//検索結果の開放
			mysql_free_result($result);

		}

	/*====================================================================================
	 *概要：
	 *	insertWorkPlan
	 *機能説明：
	 *	各入力フォームに入力されたデータを登録する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/31
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function insertWorkPlan($db){

			//現在の日付データを取得
			$nowdate = date("Y-m-d H:i:s");

			//MySQL文の生成
			$sql  = "INSERT INTO workplaninfo VALUES";
			$sql .= "(NULL,'{$this->accountid}','{$this->year1}-{$this->month1}-{$this->day1}',";
			$sql .= "'{$this->workstarthour}:{$this->workstartminute}','{$this->workendhour}:{$this->workendminute}','{$nowdate}','{$nowdate}')";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	deleteWorkPlan
	 *機能説明：
	 *	勤務予定のデータを削除する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/31
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function deleteWorkPlan($db){

			//MySQL文の生成
			$sql  = "DELETE FROM workplaninfo WHERE accountid = '{$this->accountid}' AND day='{$this->year1}-{$this->month1}-{$this->day1}'";


			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	updateWorkPlan
	 *機能説明：
	 *	accountidに該当する勤務予定データを更新する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/31
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function updateWorkPlan($db)
		{
			//現在の日付データを取得
			$nowdate = date("Y-m-d H:i:s");

			//SQL文のセット
			$sql = "UPDATE workplaninfo SET workstarttime = '{$this->workstarthour}:{$this->workstartminute}',workendtime = '{$this->workendhour}:{$this->workendminute}',updateday = '{$nowdate}' ";
			$sql.= "WHERE accountid = '{$this->accountid}' AND day = '{$this->year1}-{$this->month1}-{$this->day1}'";

			//SQL文の発行
			$result = mysql_query($sql,$db);
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
}

?>