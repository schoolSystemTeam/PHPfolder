<?php
/**
 * =====================================================================================
 プログラム名  ：	勤怠管理システム（Web版）
 プログラム説明：社員の勤怠情報を管理するシステムです。
 管理者はカレンダーを使用して視覚的に勤怠の登録、削除、変更
 を行えるほか各社員の勤怠情報の閲覧、休日、休憩時間の設定
 機能を使用することができます。

 勤怠情報とカレンダー部分はPDF,EXCEL出力することが可能です。
 作成者        ：	水島創
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
	private $oldAccount;		//旧アカウントID
	private $workplanid;		//フォーム入力勤務予定管理ID
	private $workstarthour;		//フォーム入力勤務開始時
	private $workstartminute;	//フォーム入力勤務開始分
	private $workendhour;		//フォーム入力勤務終了時
	private $workendminute;		//フォーム入力勤務終了分
	private $positionid;		//フォーム入力役割管理ID
	private $workstartdate;		//勤務開始日時
	private $workenddate;		//勤務終了日時
	private $period;			//年月変更値
	private $dispMonth;			//カレンダー表示月数
	private $calendar;			//日付格納用3次元配列
	private $workerList;		//勤怠情報格納用配列
	private $monthWorkerList;	//一ヶ月分の勤怠情報格納配列
	private $accountList;		//ユーザー情報格納用配列
	private $positionList;		//役割情報格納用配列
	private $dayOfWeek;			//曜日格納用配列
	private $holidayData;		//全休日情報
	private $eventData;			//全イベント情報
	private $errMsg;			//エラーメッセージ格納用変数
	private $execute;			//処理種別

	//イベント関連プロパティ変数
	private $eventid;			//イベントID
	private $eventplanid;		//イベント情報管理ID
	private $eventInfo;			//各イベント情報

	/*====================================================================================
	 *概要：
	 *	mainMenu_form
	 *機能説明：
	 *	コンストラクタ
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

		$this->thisYear	 = "";			//今年
		$this->thisMonth  = "";			//今月
		$this->today 	 = "";			//今日
		$this->year 	 = "";			//表示年
		$this->month 	 = "";			//表示月
		$this->year1  	 = "";			//フォーム入力年
		$this->month1 	 = "";			//フォーム入力月
		$this->day1 	 = "";			//フォーム入力日
		$this->accountid = "";			//フォーム入力アカウントID
		$this->oldAccount = "";			//旧アカウントID
		$this->workplanid = "";			//フォーム入力勤務予定管理ID
		$this->workstarthour = "";		//フォーム入力勤務開始時
		$this->workstartminute = "";	//フォーム入力勤務開始分
		$this->workendhour   = "";		//フォーム入力勤務終了時
		$this->workendminute = "";		//フォーム入力勤務終了分
		$this->positionid = "";			//フォーム入力役割管理ID
		$this->workstartdate = "";		//勤務開始日時
		$this->workenddate	 = "";		//勤務終了日時
		$this->period= "";				//年月変更値
		$this->dispMonth = "";			//カレンダー表示月数
		$this->calendar	 = "";			//日付格納用3次元配列
		$this->workerList = "";			//勤怠情報格納用配列
		$this->monthWorkerList = "";	//一ヶ月分の勤怠情報格納配列
		$this->accountList = "";		//ユーザー情報格納用配列
		$this->positionList = "";		//役割情報格納用配列
		$this->dayOfWeek = "";			//曜日格納用配列
		$this->holidayData = "";		//休日情報用配列
		$this->eventData = "";			//全イベント情報用配列
		$this->calendarColorList = "";	//カレンダー色情報格納用変数
		$this->errMsg = array();		//エラーメッセージ
		$this->execute = "";			//処理種別

		//イベント関連
		$this->eventid = "";			//イベントID
		$this->eventplanid = "";		//イベント情報管理ID
		$this->eventInfo = "";			//イベント情報

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

	//旧アカウントID
	public function setOldAccount($param)
	{
		$this->oldAccount = $param;
	}

	//フォーム入力勤務管理ID
	public function setWorkplanid($param)
	{
		$this->workplanid = $param;
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

	//フォーム入力役割管理ID
	public function setPositionid($param)
	{
		$this->positionid = $param;
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

	//役割情報格納用配列
	public function setPositionList($param)
	{
		$this->positionList = $param;
	}

	//休日情報用配列
	public function setHolidayData($param)
	{
		$this->holidayData = $param;
	}

	//全イベント情報用配列
	public function setEventData($param)
	{
		$this->eventData = $param;
	}

	//エラーメッセージ
	public function setErrMsg($param)
	{
		$this->errMsg = $param;
	}

	//処理種別
	public function setExecute($param)
	{
		$this->execute = $param;
	}

	//イベントID
	public function setEventid($param)
	{
		$this->eventid = $param;
	}

	//イベント情報管理ID
	public function setEventPlanid($param)
	{
		$this->eventplanid = $param;
	}

	//イベント情報
	public function setEventInfo($param)
	{
		$this->eventInfo = $param;
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
	 *	作成日)	2015/8/26
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

	//旧アカウントID
	public function getOldAccount()
	{
		return $this->oldAccount;
	}

	//フォーム入力勤務管理ID
	public function getWorkplanid()
	{
		return $this->workplanid;
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

	//フォーム入力役割管理ID
	public function getPositionid()
	{
		return $this->positionid;
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

	//役割情報格納用配列
	public function getPositionList()
	{
		return $this->positionList;
	}

	//全休日情報
	public function getHolidayData()
	{
		return $this->holidayData;
	}

	//全イベント情報格納用配列
	public function getEventData()
	{
		return $this->eventData;
	}

	//全イベント情報格納用配列（インデックス）
	public function getSelEventData($key)
	{
		return $this->eventData[$key];
	}

	//カレンダー色情報
	public function getSelCalenderColor($key1,$key2,$key3)
	{
		return $this->calendarColorList[$key1][$key2]["{$key3}"];
	}

	//エラーメッセージ
	public function getErrMsg()
	{
		return $this->errMsg;
	}

	//処理種別
	public function getExecute()
	{
		return $this->execute;
	}

	//イベントID
	public function getEventid()
	{
		return $this->eventid;
	}

	//イベント情報管理ID
	public function getEventPlanid()
	{
		return $this->eventplanid;
	}

	//イベント情報
	public function getEventInfo()
	{
		return $this->eventInfo;
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

			$this->dispMonth = 0;

		}
		//フォーム入力アカウントID
		if(isset($_POST['accountid']))
		{
			$this->accountid = $_POST['accountid'];
		}

		//旧アカウントID
		if(isset($_POST['oldAccount']))
		{
			$this->oldAccount = $_POST['oldAccount'];
		}

		//フォーム入力勤務管理ID
		if(isset($_POST['workplanid']))
		{
			$this->workplanid = $_POST['workplanid'];
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

		//フォーム入力更新日
		if(isset($_POST['updateDate']))
		{
			$this->workstartdate = $_POST['updateDate'];

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

		//フォーム入力役割管理ID
		if(isset($_POST['positionid']))
		{
			$this->positionid = $_POST['positionid'];
		}

		//曜日格納用配列
		if(isset($_POST['dayOfWeek']))
		{
			$this->dayOfWeek = $_POST['dayOfWeek'];
		}

		//勤務開始日時
		if(isset($_POST['startWorkingday']))
		{
			$this->workstartdate = $_POST['startWorkingday'];
		}

		//勤務終了日時
		if(isset($_POST['endWorkingday']))
		{
			$this->workenddate = $_POST['endWorkingday'];
		}

		//イベントID
		if(isset($_POST["eventid"]))
		{
			$this->eventid = $_POST["eventid"];
		}

		//イベント情報管理ID
		if(isset($_POST["eventplanid"]))
		{
			$this->eventplanid = $_POST["eventplanid"];
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
	 *	作成日)	2015/8/28
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

		//全休日情報を取得
		$this->selectAllHoliday($db);

		//全役割情報を取得
		$this->selectAllPosition($db);

		//全イベント情報を取得
		$this->eventInfo = selectAllEvent($db);

		//表示する年月を取得
		$this->setTime();

		//表示するカレンダー部分を取得
		$this->insertCalendar($db);

		//登録機能の場合、勤怠情報を登録する
		if($this->execute == "insert"){

			if($this->checkWorkInfo($db,"{$this->year1}-{$this->month1}-{$this->day1}") != false)
			{
				$this->errMsg[] = "既にこの日付には同じメンバーが登録されています！";

			}else{
				$this->insertWorkPlan($db);
			}
			echo json_encode($this->errMsg);
			exit;


		}

		//削除機能の場合、勤怠情報を削除する
		if($this->execute == "delete"){

			$this->deleteWorkPlan($db);
		}

		//更新機能の場合、勤怠情報を更新する
		if($this->execute == "update"){

			$this->updateWorkPlan($db);

			echo json_encode($this->errMsg);
			exit;

		}

		//イベント登録機能の場合、イベント登録機能を使用
		if($this->execute == "insertEvent")
		{

			//セミナーのポジション情報を取得
			$positionInfo = $this->selectPositionName($db,"セミナー");

			//プロパティ変数にセミナー情報を登録
			$this->positionid = $positionInfo['positionid'];

			//プロパティ変数に登録する
			$this->workplanid = $this->searchWorkPlanId($db);

		//登録する日付のイベント件数を取得
		$count = $this->countEventPlan($db,"{$this->year1}-{$this->month1}-{$this->day1}");

		//件数のエラーチェック
		if($count >= 3){

			$this->errMsg[] = "一日に登録できるイベント数は3件までです。";

		}

		//重複処理のエラーチェック
		if($this->searchEventPlan($db,"{$this->year1}-{$this->month1}-{$this->day1}") != false)
		{
			$this->errMsg[] = "既にこの日付には同じイベントが登録されています！";

		}

		//エラーがあった場合、処理を中断する
		if(count($this->errMsg) == 0){

			//関数を使用し情報を更新
			$this->checkOfMethodWorkPlan($db);

			//エラーが無いか確認
			if(count($this->errMsg) == 0){


				//イベント情報を登録
				$this->insertEventPlan($db);

			}


		}



			echo json_encode($this->errMsg);
			exit;



		}

		//イベント削除機能の場合、イベント削除機能を使用
		if($this->execute == "deleteEvent")
		{

			//プロパティ変数に勤怠情報管理IDを登録
			$this->workplanid = $this->searchWorkPlanId($db);

			//勤怠情報を削除
			$this->deleteWorkPlan($db);

			//イベント情報を削除
			$this->deleteEventPlan($db);
		}

		//イベント情報更新機能でユーザーが選択された場合、対応する勤務情報を返す
		if($this->execute == "searchUser")
		{
			//勤務情報を空の配列で初期化
			$workPlanInfo = array();

			//フィールド変数にセットされた値を元に情報を検索
			$workPlanInfo = $this->checkWorkInfo($db,"{$this->year1}-{$this->month1}-{$this->day1}");

			//情報が取得できたかで条件分岐
			if($workPlanInfo != false){
				//必要な情報のみを返却
				$workPlanInfo2 = array(
								  "starthour" => createHour($workPlanInfo[0]["workstarttime"]),
								  "endhour" => createHour($workPlanInfo[0]["workendtime"]),
								  "startminute" => createMinute($workPlanInfo[0]["workstarttime"]),
								  "endminute" => createMinute($workPlanInfo[0]["workendtime"])
								);
			}else{
				//固定値を入力
				$workPlanInfo2 = array(
								  "starthour" => "9",
								  "endhour" => "18",
								  "startminute" => "00",
								  "endminute" => "00"
								);
			}

			//取得した配列をエンコードして返却する
			echo json_encode($workPlanInfo2);
			exit;

		}

		//イベント情報更新機能の場合、イベント更新機能を使用
		if($this->execute == "updateEvent")
		{

			//旧アカウント番号と新アカウント番号を比較
			if($this->accountid == $this->oldAccount)
			{

				//セミナーのポジション情報を取得
				$positionInfo = $this->selectPositionName($db,"セミナー");

				//プロパティ変数にセミナー情報を登録
				$this->positionid = $positionInfo['positionid'];

				//プロパティ変数に登録する
				$this->workplanid = $this->searchWorkPlanId($db);

				//取得した勤怠情報プロパティ変数のworkplanidに挿入
				$this->updateWorkPlan($db);

				//イベント情報を更新
				$this->updateEventPlan($db);

			}else{

				//セミナーのポジション情報を取得
				$positionInfo = $this->selectPositionName($db,"セミナー");

				//プロパティ変数にセミナー情報を登録
				$this->positionid = $positionInfo['positionid'];

				//プロパティ変数に登録する
				$this->workplanid = $this->searchWorkPlanId($db);

				//関数を使い,担当者情報を更新する
				$this->checkOfMethodWorkPlan($db);



				//イベント情報を更新
				$this->updateEventPlan($db);

				//旧アカウント番号をプロパティ変数に代入
				$this->accountid = $this->oldAccount;

				//講師のポジション情報を取得
				$positionInfo = $this->selectPositionName($db,"講師");

				//プロパティ変数に講師のID情報を登録
				$this->positionid = $positionInfo['positionid'];

				//プロパティ変数に勤務情報を登録する
				$this->workplanid = $this->searchWorkPlanId($db);

				//前任の担当者だったものの勤務情報を変更
				$this->updateWorkPlanByPosition($db);



			}
			echo json_encode($this->errMsg);
			exit;

		}

		//一括登録機能の場合、一括登録機能を使用
		if($this->execute == "insertAll")
		{
			//講師のポジション情報を取得
			$positionInfo = $this->selectPositionName($db,"講師");

			//プロパティ変数に講師のID情報を登録
			$this->positionid = $positionInfo['positionid'];

			$this->insertAllWorkPlan($db);
			header("location: ./mainMenu.php");
			exit;
		}

		//一括削除機能の場合、一括削除機能を使用
		if($this->execute == "deleteAll")
		{
			$this->deleteAllWorkPlan($db);
			header("location: ./mainMenu.php");
			exit;
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
				$this->year[0] = $this->thisYear;	//今年
				$this->month[0] = $this->thisMonth;	//今月
			}

		}else{

			//初期値以外の場合、それぞれの処理にあった年月を挿入する。

			if(isset($_POST["reset"]))
			{
				$this->year[0] = $this->thisYear;	//今年
				$this->month[0] = $this->thisMonth;	//今月
			}else{
				$this->year[0] = date('Y', strtotime($_GET["year"]."-".$_GET["month"]."-1 ".$this->period));
				$this->month[0] = date('n', strtotime($_GET["year"]."-".$_GET["month"]."-1 ".$this->period));
			}





		}

		//resetの場合,初期値を挿入する
		if(isset($_POST["reset"]))
		{
			$this->year[0] = $this->thisYear;	//今年
			$this->month[0] = $this->thisMonth;	//今月
		}

		//2ヶ月分の月情報を変数に格納
		for($i=1;$i<=2;$i++)
		{
			//$iヶ月先の年を取得
			$this->year[]  = date('Y', strtotime($this->getSelYear(0)."-".$this->getSelMonth(0)."-1 +".$i." month"));
			//$iヶ月先の月を取得
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

		//カレンダーの色を格納する変数
		$colorList = "";

		// 月末日を取得
		$last_day = date('t', strtotime($this->year[$calNum]."-".$this->month[$calNum]."-1"));

		//日付情報を格納するクラスclanderを「calender + ループ回数」の変数名で配列として初期化
		$j = 0;

		// 月末日までループ

		for ($i = 1; $i < $last_day + 1; $i++) {

			// 曜日を取得
			$week[$calNum][] = date('w', mktime(0, 0, 0, $this->month[$calNum], $i, $this->year[$calNum]));

			// 1日の場合
			if ($i == 1) {

				//日曜日場合のみ違う値を設定
				if($week[$calNum][0] == 0)
				{
					$week[$calNum][0] = 7;
				}

				// 1日目の曜日までをループ
				for ($s = 1; $s < $week[$calNum][0]; $s++) {

					// 前半に空文字をセット
					$calendar[$j]['day'] = '';	//カレンダーの日付部分に空文字を格納

					//関数を使用し、勤怠情報があれば$monthWorkerListに格納
					$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$calendar[$j]['day']);

					$colorList[$j]['code'] = "#FFFFFF";	//色情報に白のコードを格納
					$j++;
				}
			}

			// 配列に日付をセット //

			$calendar[$j]['day'] = $i;	//日付を格納

			//関数を使用し、勤怠情報があれば$monthWorkerListに格納
			$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$i);

			//関数を使用し,イベント情報を日付をインデックス番号に格納
			$this->eventData["{$this->year[$calNum]}-{$this->month[$calNum]}-{$i}"] = $this->selectThreeEventByDay($db,"{$this->year[$calNum]}-{$this->month[$calNum]}-{$i}");

			$j++;

			// 月末日の場合
			if ($i == $last_day) {

				// 月末日から残りをループ
				for ($e = 1; $e <= 6 - $week[$calNum][$last_day-1]; $e++) {

					// 後半に空文字をセット
					$calendar[$j]['day'] = '';

					//関数を使用し、勤怠情報があれば$monthWorkerListに格納
					$this->searchWorkInfo($db,$this->year[$calNum],$this->month[$calNum],$calendar[$j]['day']);

					//色情報として白のコードを格納
					$colorList[$j]['code'] = "#FFFFFF";
					$j++;
				}
			}
		}

		//全取得情報をそれぞれのプロパティ変数に配列として加算
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
		$sql = "SELECT A.accountid,SUBSTRING(A.name, 1, 4) as name,WP.positionid, P.`p-name`,
						P.color,C.code,WP.workplanid,WP.day,WP.workstarttime,WP.workendtime
						FROM accountinfo A
						INNER JOIN colorinfo C ON A.colorid = C.colorid
						INNER JOIN workplaninfo WP ON A.accountid = WP.accountid
						INNER JOIN positioninfo P ON WP.positionid = P.positionid
						WHERE WP.day = '{$year}-{$month}-{$day}'
						ORDER BY WP.workstarttime; ";


		//SQL文の発行
		$result = mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = @ mysql_num_rows($result);

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
			$workerInfo['positionid'] = "";
			$workerInfo['p-name'] = "";
			$workerInfo['code'] = "";
			$workerInfo['workplanid'] = "";
			$workerInfo['workstarttime'] = "";
			$workerInfo['workendtime'] = "";

			$workerInfo2[] = $workerInfo;

			$this->monthWorkerList[] = $workerInfo2;

			//戻り値にfalseを挿入
			$tf = false;

		}

		//検索結果の開放
		@mysql_free_result($result);

		//戻り値として真偽を返す
		return $tf;
	}

	/*====================================================================================
	 *概要：
	 *	checkWorkInfo($db,$date)
	 *機能説明：
	 *	アカウント情報と日付に合致する勤怠情報をDBから取得し、情報があればアカウント情報の配列を,ない場合はfalseを返す。
	 *引数：
	 *	データベース情報,日付
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

	private function checkWorkInfo($db,$date)
	{
		//日付データ格納用配列を定義
		$workerInfo = "";

		//SQL構文をセット
		$sql = "SELECT A.accountid,A.name,P.`p-name`,C.code,WP.workplanid,WP.day,WP.workstarttime,WP.workendtime
				FROM accountinfo A
				INNER JOIN workplaninfo WP ON A.accountid = WP.accountid
				INNER JOIN positioninfo P ON WP.positionid = P.positionid
				INNER JOIN colorinfo C ON A.colorid = C.colorid ";
		$sql .= "WHERE A.accountid = {$this->accountid} AND WP.day = '{$date}'";

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

			//戻り値に勤怠情報を挿入
			$return = $workerInfo;

		}else{

			//戻り値にfalseを挿入
			$return = false;

		}

		//検索結果の開放
		mysql_free_result($result);

		//戻り値として真偽を返す
		return $return;
	}


	/*====================================================================================
	 *概要：
	 *	selectAllAccount()
	 *機能説明：
	 *	全アカウント情報をテーブルから全て取得し、プロパティ変数の$accountListに格納する。
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
	 *	selectAllPosition()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$positionListに格納する。
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

	private function selectAllPosition($db){

		//MySQL文の用意
		$sql = "SELECT * FROM positioninfo";

		//SQL文の発行
		$result = mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0):

		//繰り返し処理を使用して全取得データをbookListに格納
		while($row = mysql_fetch_assoc($result)):
		//格納した1行データをbookListに配列で格納
		$this->positionList[] = $row;

		endwhile;

		endif;

		//検索結果の開放
		mysql_free_result($result);

	}

	/*====================================================================================
	 *概要：
	 *	selectPositionName()
	 *機能説明：
	 *	全役割情報のDBからセミナー情報のみを取得する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/25
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectPositionName($db,$name){

		//MySQL文の用意
		$sql = "SELECT * FROM positioninfo
				WHERE `p-name` = '{$name}'";

		//SQL文の発行
		$result = mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0):

		//繰り返し処理を使用して全取得データをbookListに格納
		while($row = mysql_fetch_assoc($result)):
		//格納した1行データをbookListに配列で格納
		$positionInfo = $row;

		endwhile;

		endif;

		//検索結果の開放
		mysql_free_result($result);

		//取得した配列を返却する
		return $positionInfo;

	}


	/*====================================================================================
	 *概要：
	 *	insertWorkPlan
	 *機能説明：
	 *	各入力フォームに入力されたデータを登録する。
	 *	エラーが発生した場合,エラーメッセージをフィールド変数に
	 *	格納し,falseを戻り値として返す
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

		//必要なデータを変数に格納

		$date = "{$this->year1}-{$this->month1}-{$this->day1}";	//日付
		$startTime = "{$this->workstarthour}:{$this->workstartminute}";	//勤務開始時刻
		$endTime = "{$this->workendhour}:{$this->workendminute}";	//勤務終了時刻

		//時刻が不正な入力ではないかをエラーチェック
		if(strtotime("{$date} {$startTime}:00") >= strtotime("{$date} {$endTime}:00"))
		{
			$this->errMsg[] = "勤怠時刻が不正です！正しい労働時間を設定して下さい！";
			return false;
		}

		//2重複登録ではないかをチェック
		if($this->checkWorkInfo($db,$date) != false){

			$this->errMsg[] = "既にそのユーザーは現在の日付に登録されています！";
			return false;
		}


		//現在の日付データを取得
		$nowdate = date("Y-m-d H:i:s");

		//MySQL文の生成
		$sql  = "INSERT INTO workplaninfo VALUES";
		$sql .= "(NULL,'{$this->accountid}','{$date}',";
		$sql .= "'{$startTime}','{$endTime}',{$this->positionid},'{$nowdate}','{$nowdate}')";

		//SQL文の発行
		$result = mysql_query($sql,$db);

	}

	/*====================================================================================
	 *概要：
	 *	insertAllWorkPlanOnce
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

	private function insertWorkPlanOnce($db,$date){

		//現在の日付データを取得
		$nowdate = date("Y-m-d H:i:s");

		//MySQL文の生成
		$sql  = "INSERT INTO workplaninfo VALUES";
		$sql .= "(NULL,'{$this->accountid}','{$date}',";
		$sql .= "'{$this->workstarthour}:{$this->workstartminute}',
				 '{$this->workendhour}:{$this->workendminute}',
		          {$this->positionid},'{$nowdate}','{$nowdate}')";

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
		$sql  = "DELETE FROM workplaninfo WHERE workplanid = {$this->workplanid}";


		//SQL文の発行
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	deleteWorkPlanOnce
	 *機能説明：
	 *	引数の勤務予定のデータを削除する。
	 *引数：
	 *	データベース情報,勤怠予定管理ID
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

	private function deleteWorkPlanOnce($db,$workplanid){

		//MySQL文の生成
		$sql  = "DELETE FROM workplaninfo WHERE workplanid = {$workplanid}";


		//SQL文の発行
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	updateWorkPlan
	 *機能説明：
	 *	accountidに該当する勤務予定データを更新する。
	 *	エラーが発生した場合、エラーメッセージを格納し戻り値falseを返す。
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
		$startTime = "{$this->workstarthour}:{$this->workstartminute}";	//勤務開始時刻
		$endTime = "{$this->workendhour}:{$this->workendminute}";	//勤務終了時刻

		//勤怠情報が存在しているかをチェック

		$workInfo = $this->searchWorkPlan($db);	//勤怠情報

		if(!preg_match('/^([1-9][0-9]{3})\/([1-9]{1}|1[0-2]{1})\/([1-9]{1}|[1-2]{1}[0-9]{1}|3[0-1]{1})$/',$this->workstartdate)
		&& !preg_match('/^([1-9][0-9]{3})\/(0[1-9]{1}|1[0-2]{1})\/(0[1-9]{1}|[1-2]{1}[0-9]{1}|3[0-1]{1})$/', $this->workstartdate)){

			$this->errMsg[] = "入力された日付情報が不正です。YYYY/MM/DDの形式で入力して下さい！";

		}else{

			//年月日に日付を分ける
			$year = createDateYMD($this->workstartdate,"y");
			$month =  createDateYMD($this->workstartdate,"m");
			$day =  createDateYMD($this->workstartdate,"d");

			//正当な日付かどうかをチェック
			if(!checkdate($month,$day,$year)){

				$this->errMsg[] = "入力された日付情報は存在しない日付です！";

			}

		}

		if(!$workInfo)
		{
			$this->errMsg[] = "勤怠情報が存在していなかったため更新処理は行えませんでした。";

		}

		//時刻が不正な入力ではないかをエラーチェック
		if(strtotime("{$workInfo['day']} {$startTime}:00") >= strtotime("{$workInfo['day']} {$endTime}:00"))
		{
			$this->errMsg[] = "勤怠時刻が不正です！正しい労働時間を設定して下さい！";

		}

	//他の日付の更新する場合、その人の勤怠情報が既に登録されていないかをチェック
		if(strtotime("{$this->workstartdate}") != strtotime("{$this->year1}-{$this->month1}-{$this->day1}")){
			//2重複登録ではないかをチェック
			if($this->checkWorkInfo($db,$this->workstartdate) != false){

				$this->errMsg[] = "既にそのユーザーは現在の日付に登録されています！";

			}
		}



		if(count($this->errMsg)!= 0){
			return false;
		}

		//SQL文のセット
		$sql = "UPDATE workplaninfo
				SET day = '{$this->workstartdate}',
				workstarttime = '{$startTime}',
				workendtime = '{$endTime}',
				positionid = {$this->positionid},
				updateday = NOW() ";
		$sql.= "WHERE workplanid = '{$this->workplanid}'";

		//SQL文の発行
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	updateWorkPlanByPosition
	 *機能説明：
	 *	accountidに該当する勤務予定データを更新する。
	 *	エラーが発生した場合、エラーメッセージを格納し戻り値falseを返す。
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

	private function updateWorkPlanByPosition($db)
	{
		$startTime = "{$this->workstarthour}:{$this->workstartminute}";	//勤務開始時刻
		$endTime = "{$this->workendhour}:{$this->workendminute}";	//勤務終了時刻

		$workInfo = $this->searchWorkPlan($db);	//勤怠情報

		//時刻が不正な入力ではないかをエラーチェック
		if(strtotime("{$workInfo['day']} {$startTime}:00") >= strtotime("{$workInfo['day']} {$endTime}:00"))
		{
			$this->errMsg[] = "勤怠時刻が不正です！正しい労働時間を設定して下さい！";
			return false;
		}

		//SQL文のセット
		$sql = "UPDATE workplaninfo
				SET positionid = '{$this->positionid}',
				updateday = NOW() ";
		$sql.= "WHERE workplanid = '{$this->workplanid}'";

		//SQL文の発行
		$result = mysql_query($sql,$db);
	}


	/*====================================================================================
	 *概要：
	 *	insertAllWorkPlan()
	 *機能説明：
	 *	曜日情報をフォームから受け取り、受け取った曜日と特定の期間分の勤怠情報を
	 * 	登録する。
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
	private function insertAllWorkPlan($db)
	{

		//カウンタ変数を0で初期化
		$cnt=0;

		//勤務開始時間と終了時間を変数に格納
		$startTime = "{$this->workstarthour}:{$this->workstartminute}";	//勤務開始時間
		$endTime = "{$this->workendhour}:{$this->workendminute}";		//勤務終了時間

		//不正な期日が選択されていないかをエラーチェック
		if(strtotime("{$this->workstartdate}") >= strtotime("{$this->workenddate}"))
		{
			callErrorPage("不正な期間が選択されたため、一括登録は行えませんでした。","menu");
			exit;
		}

		//一年以上の期日選択ではないかをチェック
		if(((strtotime("{$this->workenddate}") - strtotime("{$this->workstartdate}")) / ( 60 * 60 * 24)) >= 365)
		{
			callErrorPage("1年以上の期間が選択されたため、一括登録は行えませんでした。","menu");
			exit;
		}

		//不正な時間選択ではないかをチェック
		if(strtotime("{$this->workstartdate} {$startTime}:00") >= strtotime("{$this->workstartdate} {$endTime}:00"))
		{
			callErrorPage("勤怠時刻が不正です！正しい労働時間を設定して下さい！","menu");
			exit;
		}

		//期間の終了日をDateTimeで変換
		$dateEndtime = new DateTime("{$this->workenddate}");

		//ループ開始
		while(true){

			//開始日にループ分に日数を足しこんだ日付をcheckdayに格納
			$checkdate = date('Y-m-d',strtotime("{$this->workstartdate} + {$cnt}day"));

			//checkdateをDateTimeで変換
			$dateStartTime = new DateTime("{$checkdate}");

			//期間外に達した場合、ループを抜ける
			if($dateStartTime > $dateEndtime){
				break;
			}

			//checkdateの曜日を取得
			$w = (int)$dateStartTime->format('w');

			//各曜日と一致している場合,DBに勤怠情報を登録する。
			if(in_array($w,$this->dayOfWeek))
			{
				if($this->checkWorkInfo($db,"{$checkdate}") != false)
				{
					callErrorPage("{$checkdate}には既に同じユーザーが登録されていたため,一括登録処理を中断しました。","menu");
					exit;
				}

				//専用の関数を使用し、勤怠情報を登録
				$this->insertWorkPlanOnce($db,$checkdate);
			}

			//カウンター変数を追加
			$cnt++;
		}

	}

	/*====================================================================================
	 *概要：
	 *	deleteAllWorkPlan()
	 *機能説明：
	 *	曜日情報をフォームから受け取り、受け取った曜日と特定の期間分の勤怠情報を
	 * 	に該当するものを削除する。
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
	private function deleteAllWorkPlan($db)
	{

		//カウンタ変数を0で初期化
		$cnt=0;

		//不正な期日が選択されていないかをエラーチェック
		if(strtotime("{$this->workstartdate}") >= strtotime("{$this->workenddate}"))
		{
			callErrorPage("不正な期間が選択されたため、一括削除は行えませんでした。","menu");
			exit;
		}

		//一年以上の期日選択ではないかをチェック
		if(((strtotime("{$this->workenddate}") - strtotime("{$this->workstartdate}")) / ( 60 * 60 * 24)) >= 365)
		{
			callErrorPage("1年以上の期間が選択されたため、一括削除は行えませんでした。","menu");
			exit;
		}

		//期間の終了日をDateTimeで変換
		$dateEndtime = new DateTime("{$this->workenddate}");

		//ループ開始
		while(true){

			//開始日にループ分に日数を足しこんだ日付をcheckdayに格納
			$checkdate = date('Y-m-d',strtotime("{$this->workstartdate} + {$cnt}day"));

			//checkdateをDateTimeで変換
			$dateStartTime = new DateTime("{$checkdate}");

			//期間外に達した場合、ループを抜ける
			if($dateStartTime > $dateEndtime){
				break;
			}

			//checkdateの曜日を取得
			$w = (int)$dateStartTime->format('w');

			//各曜日と一致している場合,DB内の削除処理をおこなう
			if(in_array($w,$this->dayOfWeek))
			{
				//勤怠情報を格納する変数,workInfo
				$workInfo = "";

				//checkWorkInfoを使用して該当する勤怠データがあるかを検索
				$workInfo = $this->checkWorkInfo($db,$checkdate);

				//データがあるかどうかで処理を変更する
				if($workInfo != false)
				{
					foreach($workInfo as $key => $val):

					$this->deleteWorkPlanOnce($db,$val['workplanid']);

					endforeach;
				}

			}

			//カウンター変数を追加
			$cnt++;
		}

	}

	/*====================================================================================
	 *概要：
	 *	selectAllHoliday()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$holidayDataに格納する。
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

	private function selectAllHoliday($db){

		//MySQL文の用意
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT h.holidayid,h.day,h.holidayName,t.typeid,t.code
				FROM holidayinfo h
				INNER JOIN typeinfo t ON h.typeid=t.typeid
				ORDER BY day";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_assoc($result)){

			$this->holidayData[] = $assoc;

		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}

	private function selectThreeEventByDay($db,$date){



		//MySQL文の用意
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT EP.eventplanid, E.eventid, E.eventName, E.shortName, E.color, EP.day,EP.accountid,A.name,C.code
		        FROM eventplaninfo EP
		        INNER JOIN eventinfo E ON EP.eventid = E.eventid
		        INNER JOIN accountinfo A ON EP.accountid = A.accountid
		        INNER JOIN colorinfo C ON A.colorid = C.colorid
		        WHERE day = '{$date}'
		        ORDER BY E.eventid
		        LIMIT 0 , 3";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		if($rows>0){
			//結果セットの行数を取得する
			while($assoc = mysql_fetch_assoc($result)){

				$eventInfo[] = $assoc;

			}
		}else{

			$eventInfo2 = array("eventplanid"=>"",
							   	"eventid"=>"",
								"eventName"=>"",
								"shortName"=>"",
								"color"=>"",
								"eventplanid"=>"",
								"day"=>"",
								"accountid"=>"",
								"name"=>""
								);

								$eventInfo[] = $eventInfo2;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		//取得した連想配列を返却する
		return $eventInfo;

	}

	/*====================================================================================
	 *概要：
	 *	selectThreeEventByDay()
	 *機能説明：
	 *	その日付に該当するイベント情報を3つまで格納し、連想配列として返す。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	eventInfo
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
	 *	setDateClass
	 *機能説明：
	 *	日付情報を引数にクラスを選択し、格納する
	 *引数：
	 *	$date(日付情報)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/09/10
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	public function setDateClass($year,$month,$day){

		//日付を作成
		$date = "{$year}-{$month}-{$day}";

		if(strlen($day) != 0 && !empty($day)){

			//曜日を日付から取得する
			$w = createDayOfWeek($date);

		}else{

			$w = "";

		}



		//日付と曜日ごとに条件でわけ、クラス名を格納する

		if($w == 0){

			$class = "holiday";

		}else if($this->checkEqualHoliday($date)){

			$class = "holiday";

		}else if($w == 6){

			$class = "saturday";

		}else{

			$class = "";

		}

		return $class;
	}

	/*====================================================================================
	 *概要：
	 *	setDateId
	 *機能説明：
	 *	日付情報を引数にIDを選択し、格納する
	 *引数：
	 *	$date(日付情報)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/09/11
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	public function setDateId($year,$month,$day){

		//戻り値用の変数
		$id = "";

		//日付を作成
		$date = "{$year}-{$month}-{$day}";

		//本日の日付を作成
		$today = date("Y-n-j");

		//本日の日付とカレンダーが一致する場合
		if($date == $today){

			$id = "today";

		}

		return $id;
	}

	/*====================================================================================
	 *概要：
	 *	checkEqualHoliday($date)
	 *機能説明：
	 *	日付情報を引数に休日のデータと一致するものがないかを検索し一致した場合、
	 *	その日付情報を戻り値として返し、そうでは無かった場合falseを返す。
	 *引数：
	 *	$date
	 *戻り値：
	 *	$result
	 *備考：
	 *	作成日)	2015/09/02
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */
	public function checkEqualHoliday($date)
	{
		//休日情報が取得できているかどうかをチェック
		if(is_array($this->holidayData))
		{

			//できていた場合ループを開始
			foreach ($this->holidayData as $value)
			{
				//引数と一致する日付情報かをチェック
				if($date == date("Y-n-j",strtotime($value['day'])))
				{
					//一致した場合その休日情報を戻り値に格納し、
					//ループを抜ける。
					$result = $value;
					break;

				}

				$result = false;
			}

			//出来ていなければ戻り値にfalseを格納する
		}else{

			$result = false;

		}

		return $result;
	}

	/*====================================================================================
	 *概要：
	 *	searchWorkPlan($db)
	 *機能説明：
	 *	仕事情報をidを元に検索し、結果があれば取得した結果を
	 *	ない場合にはfalseを返す
	 *引数：
	 *	$db
	 *戻り値：
	 *	$workPlan
	 *備考：
	 *	作成日)	2015/09/02
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */
	private function searchWorkPlan($db)
	{
		//SQL文をセット
		$sql = "SELECT * FROM workplaninfo WHERE workplanid = {$this->workplanid}";

		//SQL文の発行
		$result = mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0){

			//繰り返し処理を使用して全取得データをworkPlanに格納
			while($row = mysql_fetch_assoc($result)):
			//格納した1行データを$workPlanに配列で格納
			$workPlan = $row;

			endwhile;

		}else{

			$workPlan = false;

		}

		//検索結果の開放
		mysql_free_result($result);

		return $workPlan;
	}

	/*====================================================================================
	 *概要：
	 *	insertEventPlan
	 *機能説明：
	 *	日数とイベントIDを引数にイベントを登録する。
	 *	エラーが発生し場合,falseを値として返す。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/11
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function insertEventPlan($db){

		//必要なデータを変数に格納

		$date = "{$this->year1}-{$this->month1}-{$this->day1}";	//日付

		//MySQL文の生成
		$sql  = "INSERT INTO eventplaninfo VALUES";
		$sql .= "(NULL,'{$this->eventid}',{$this->accountid},'{$date}',";
		$sql .= "NOW(),NOW())";
		//SQL文の発行
		$result = mysql_query($sql,$db);


	}

	/*====================================================================================
	 *概要：
	 *	searchEventPlan
	 *機能説明：
	 *	日数とイベントIDを引数にDBを検索し、あった場合にはその検索情報を,
	 *	なかった場合にはfalseを返す
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/11
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function searchEventPlan($db,$date){

		//MySQL文の生成
		$sql  = "SELECT * FROM eventplaninfo
				 WHERE eventid = {$this->eventid} AND day = '{$date}'";

		//SQL文の発行
		$result = mysql_query($sql,$db);


		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0){

			//繰り返し処理を使用して全取得データをeventPlanInfoに格納
			while($row = mysql_fetch_assoc($result)):
			//格納した1行データをeventPlanInfoに配列で格納
			$eventPlanInfo = $row;

			endwhile;

		}else{

			$eventPlanInfo = false;

		}

		//検索結果の開放
		mysql_free_result($result);

		//検索結果を戻り値として返す
		return $eventPlanInfo;

	}

	/*====================================================================================
	 *概要：
	 *	countEventPlan
	 *機能説明：
	 *	db情報と日付を引数に日付と一致するイベントの件数を取得する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */


	private function countEventPlan($db,$date){
		$sql = "SELECT COUNT( * ) AS cnt
				FROM  `eventplaninfo`
				WHERE DAY =  '{$date}'";

		//SQL文の発行
		$result = mysql_query($sql,$db);


		//検索結果の件数を取得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0){

			//繰り返し処理を使用して全取得データをeventPlanInfoに格納
			while($row = mysql_fetch_assoc($result)):
			//格納した1行データをeventPlanInfoに配列で格納
			$eventPlanInfo = $row;

			endwhile;

		}else{

			$eventPlanInfo["cnt"] = false;

		}

		//検索結果の開放
		mysql_free_result($result);

		//検索結果を戻り値として返す
		return $eventPlanInfo["cnt"];


	}

	/*====================================================================================
	 *概要：
	 *	deleteEventPlan
	 *機能説明：
	 *	イベント情報管理番号を引数に対象のイベント情報を
	 *	削除する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/14
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function deleteEventPlan($db){

		//MySQL文の生成
		$sql = "DELETE FROM eventplaninfo WHERE eventplanid = {$this->eventplanid}";

		//SQL文の発行
		$result = mysql_query($sql,$db);


	}

	/*====================================================================================
	 *概要：
	 *	updateEventPlan
	 *機能説明：
	 *	イベント情報管理番号を引数に対象のイベント情報を
	 *	更新する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/14
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function updateEventPlan($db){

		//選択されたイベント情報を格納
		$eventInfo = $this->searchEventPlan($db,$this->workstartdate);

		//重複処理のエラーチェック
		if($eventInfo != false && $this->eventid != $eventInfo['eventid'])
		{
			$this->errMsg[] = "既にこの日付には同じイベントが登録されています！";
			return false;
		}

		//MySQL文の生成
		$sql = "UPDATE eventplaninfo
				SET eventid = {$this->eventid},
				accountid = '{$this->accountid}',
				updateday = NOW()
				WHERE eventplanid = {$this->eventplanid}";

		//SQL文の発行
		$result = mysql_query($sql,$db);


	}

	/*====================================================================================
	 *概要：
	 *	searchWorkPlanId
	 *機能説明：
	 *	勤務情報を調べそれと一致するworkplanidを戻り値として返す。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/25
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function searchWorkPlanId($db){

		//プロパティ変数に日付を登録
		$this->workstartdate = "{$this->year1}/{$this->month1}/{$this->day1}";

		//勤怠情報を調べ、同じかどうかをチェックする
		$workplanInfo = $this->checkWorkInfo($db,"{$this->workstartdate}");

		//プロパティ変数に登録する
		return $workplanInfo[0]['workplanid'];

	}



	/*====================================================================================
	 *概要：
	 *	checkOfMethodWorkPlan
	 *機能説明：
	 *	勤務情報登録を既に登録されているかどうかで
	 *	使用するメソッドを使い分ける
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/25
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function checkOfMethodWorkPlan($db)
	{

			if($this->checkWorkInfo($db,"{$this->workstartdate}") == false)
			{

				$this->insertWorkPlan($db);

			}else{

				//取得した勤怠情報プロパティ変数のworkplanidに挿入

				$this->updateWorkPlan($db);

			}
	}

}
?>