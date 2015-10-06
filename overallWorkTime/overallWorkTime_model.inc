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
 作成日        ：	2015/9/07
 =====================================================================================
 */

class overallWorkTime_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $work;				//検索条件
	private $year;				//年
	private $month;				//月
	private $week;				//週
	private $day;				//日
	private $startDay;			//開始日付
	private $endDay;			//終了日付
	private $accountid;			//アカウント
	private $name;				//名前
	private $execute;			//処理種別
	private $restdata;			//休憩時間データ
	private $workdata;			//勤務時間表データ
	private $workplaninfo;		//勤務情報データ
	private $holidaydata;		//休日用データ
	private $sumWorkData;		//勤務時間表合計データ
	private	$displayData;		//勤務時間表表示用データ
	private $monthDispData;		//月別表示用データ
	private $accountData;		//アカウント情報表示用データ
	private $sumArray;			//各要素合計格納用配列
	private $aveArray;			//各要素平均格納用配列
	private $monthSumArray;		//月別合計格納用配列
	private $monthAveArray;		//月別平均格納用配列
	private $infomation;		//表示用インフォメーション

	/*====================================================================================
	 *概要：
	 *	insertUser_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function init(){

		$this->work = "";				//検索条件
		$this->year = "";				//年
		$this->month = "";				//月
		$this->week = "";				//週
		$this->day = "";				//日
		$this->startDay = "";			//期間検索の開始日付
		$this->endDay = "";				//期間検索の終了日付
		$this->accountid = "";			//アカウント
		$this->name = '';				//名前
		$this->execute = "";			//処理種別
		$this->form = '';				//検索種別
		$this->workdata = array();		//表示用勤務時間表データ
		$this->workplaninfo = "";		//勤務情報データ
		$this->restdata = array();		//表示用休憩時間データ
		$this->holidaydata = "";		//休日用データ
		$this->sumWorkData = "";		//勤務時間表合計データ
		$this->displayData = "";		//勤務時間表表示用データ
		$this->monthDispData = "";		//月別表示用データ
		$this->accountData = "";		//アカウント情報表示用データ
		$this->sumArray = array();			//各要素合計格納用配列
		$this->aveArray = "";			//各要素平均格納用配列
		$this->monthSumArray = "";		//月別合計表示用データ
		$this->monrthAveArray = "";		//月別平均表示用データ
		$this->infomation = '';			//表示用インフォメーション

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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */


	//検索条件
	public function setWork($param){
		$this->work = $param;
	}

	//年
	public function setYear($param){
		$this->year = $param;
	}

	//月
	public function setMonth($param){
		$this->month = $param;
	}

	//週
	public function setWeek($param){
		$this->week = $param;
	}

	//日
	public function setDay($param){
		$this->day = $param;
	}

	//期間検索の開始日付
	public function setStartDay($param){
		$this->startDay = $param;
	}

	//期間検索の終了日付
	public function setEndDay($param){
		$this->endDay = $param;
	}

	//アカウント
	public function setAccountId($param){
		$this->accountid = $param;
	}

	//名前
	public function setName($param){
		$this->name = $param;
	}

	//処理種別
	public function setExecute($param){
		$this->execute = $param;
	}

	//勤務時間表データ
	public function setWorkData($param){
		$this->workdata = $param;
	}

	//勤務情報データ
	public function setWorkPlanInfo($param)
	{
		$this->workplaninfo = $param;
	}

	//休憩時間データ
	public function setRestData($param){
		$this->restdata = $param;
	}

	//休日情報データ
	public function setHolidayData($param){
		$this->holidaydata = $param;
	}

	//勤務時間表合計データ
	public function setSumWorkData($param){
		$this->sumWorkData = $param;
	}

	//表示用勤務時間表データ
	public function setDisplayData($param){
		$this->displayData = $param;
	}

	//月別表示用データ
	public function setMonthDispData($param)
	{
		$this->monthDispData = $param;
	}

	//アカウント情報表示用データ
	public function setAccountData($param){
		$this->accountData = $param;
	}

	//各要素合計格納用配列
	public function setSumArray($param){
		$this->sumArray = $param;
	}

	//各要素平均格納用配列
	public function setAveArray($param){
		$this->aveArray = $param;
	}

	//月別合計用配列
	public function setMonthSumArray($param)
	{
		$this->monthSumArray = $param;
	}

	//月別平均用配列
	public function setMonthAveArray($param)
	{
		$this->monthAveArray = $param;
	}

	//表示用インフォメーション
	public function setInfomation($param){
		$this->infomation = $param;
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
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	//検索条件
	public function getWork(){
		return $this->work;
	}

	//年
	public function getYear(){
		return $this->year;
	}

	//月
	public function getMonth(){
		return $this->month;
	}

	//週
	public function getWeek(){
		return $this->week;
	}

	//日
	public function getDay(){
		return $this->day;
	}

	//期間検索の開始日付
	public function getStartDay(){
		return $this->startDay;
	}

	//期間検索の終了日付
	public function getEndDay(){
		return $this->endDay;
	}

	//アカウント
	public function getAccountId(){
		return $this->accountid;
	}

	//名前
	public function getName(){
		return $this->name;
	}

	//処理種別
	public function getExecute(){
		return $this->execute;
	}

	//検索種別
	public function getWorkData(){
		return $this->workdata;
	}

	//勤務情報データ
	public function getWorkPlanInfo()
	{
		return $this->workplaninfo;
	}

	//表示用休憩時間データ
	public function getRestData(){
		return $this->restdata;
	}

	//休日情報データ
	public function getHolidayData(){
		return $this->holidaydata;
	}

	//勤務時間表合計データ
	public function getSumWorkData(){
		return $this->sumWorkData;
	}

	//表示用勤務時間表データ
	public function getDisplayData(){
		return $this->displayData;
	}

	//月別表示用データ
	public function getMonthDispData()
	{
		return $this->monthDispData;
	}

	//アカウント表示用データ
	public function getAccountData(){
		return $this->accountData;
	}

	//各要素合計格納用配列
	public function getSumArray(){
		return $this->sumArray;
	}

	//各要素合計格納配列（要素選択）
	public function getSelSumArray($key){
		return $this->sumArray[$key];
	}

	//各要素平均格納用配列
	public function getAveArray(){
		return $this->aveArray;
	}

	//各要素平均格納用配列(要素選択)
	public function getSelAveArray($key){
		return $this->aveArray[$key];
	}

	//月別合計格納用配列
	public function getMonthSumArray()
	{
		return $this->monthSumArray;
	}

	//月別合計格納用配列(要素選択)
	public function getSelMonthSumArray($key)
	{
		return $this->monthSumArray[$key];
	}

	//月別平均格納用配列
	public function getMonthAveArray()
	{
		return $this->monthSumArray;
	}

	//月別平均格納用配列（要素選択）
	public function getSelMonthAveArray($key)
	{
		return $this->monthAveArray[$key];
	}

	//表示用役割データ
	public function getInfomation(){
		return $this->infomation;
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	//フォーム入力からの数値受け取り関数
	public function getForm(){

		//業務内容
		if(isset($_POST["work"])){
			$this->work = $_POST["work"];
		}

		//年
		if(isset($_POST["year"])){
			if(!empty($_POST["year"])&& strlen($_POST["year"]) != 0){
				$this->year = $_POST["year"];
			}
		}

		//月
		if(isset($_POST["month"])){
			if(!empty($_POST["month"])&& strlen($_POST["month"]) != 0){
				$this->month = $_POST["month"];
				$this->year = date("Y",strtotime($_POST["month"]));
			}
		}

		//開始日付
		if(isset($_POST["startDay"])){
			if(!empty($_POST["startDay"])&& strlen($_POST["startDay"]) != 0){
				$this->startDay = $_POST["startDay"];
				$this->year = date("Y",strtotime($_POST["startDay"]));
			}
		}

		//終了日付
		if(isset($_POST["endDay"])){
			if(!empty($_POST["endDay"])&& strlen($_POST["endDay"]) != 0){
				$this->endDay = $_POST["endDay"];
			}
		}

		//アカウント
		if(isset($_POST["accountid"])){
			$this->accountid = $_POST["accountid"];
		}

		//名前
		if(isset($_POST["name"])){
			$this->name = $_POST["name"];
		}

		//処理種別
		if(isset($_POST["execute"])){
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
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)	2015/9/14
	 *	更新者)	水島創太
	 *	変更)
	 ====================================================================================
	 */

	public function processing($db){

		//初期表示かどうかの選択
		if($this->execute == "disp"){

		}else{

			//デフォルトの状態では1ヶ月を表示するように変更。
			$this->work = "month";
			$this->month = date("Y-m");
			$this->year = date("Y",strtotime($this->month));
			$this->accountid = "%%";
			$this->startDay = date('Y-m');
			$this->endDay = date('Y-m',strtotime("+2month"));

		}

		//名前のセレクトで表示する配列をプロパティ変数に格納
		$this->selectWorkplaninfoByAccount($db);

		//SQL文のWHERE句を設定
		$form = $this->form($this->work);

		//DBから合計の勤務情報を取得
		$this->selectSumWorkInfo($db,$form);

		//フォームの期間の日数を取得
		$day = $this->countDate($this->work);

		//休日のステータスIDを取得
		$statusid = $this->selectStatusIdByName($db,"休み");

		//フォームの期間の休日数を取得
		$holiday = $this->countHoliday($db,$form);

		if($this->accountid == "%%"){
			$account = $this->accountData;
		}else{
			$account[0] = $this->accountid;
		}

		$a = 0;

		//合計勤務情報の数だけ処理を行う
		for($i=0;$i<count($account);$i++){

				if($this->accountData[$i]["accountid"] == $this->sumWorkData[$a]["accountid"]){

					//このアカウントの勤務情報データをプロパティ変数に格納
					$this->workplaninfo = $this->selectWorkplaninfo($db,$this->sumWorkData[$a]["accountid"],$form);

					//このアカウントの休憩時間合計を取得
					$restTime = $this->selectSumRestTime($db,$this->sumWorkData[$a]["accountid"]);

					//表示用の配列を初期化
					$displayInfo = array();


					//表示用の配列を作成する
					$displayInfo['accountid'] = $this->sumWorkData[$a]['accountid'];			//アカウントID
					$displayInfo['name'] = $this->sumWorkData[$a]['name'];						//名前
					$displayInfo['workday'] = $this->sumWorkData[$a]['cnt'];				//出勤日合計
					$displayInfo['business'] = $day - $holiday;									//営業日日数
					$displayInfo['absence'] = $this->selectSumAbsence($db,$statusid,$this->sumWorkData[$a]['accountid'],$form);//欠席日数
					$displayInfo['resttime'] = $restTime/3600;	//休憩時間
					$displayInfo['worktime'] = ($this->sumWorkData[$a]['sum'] - $restTime)/3600;	//労働時間合計

					//週平均労働日数
					if($this->work == 'year'){

						$displayInfo['aveWorkday'] = round($displayInfo['workday']/48,2);

					}else if($this->work == 'month'){

						$displayInfo['aveWorkday'] =round( $displayInfo['workday']/4,2);

					}else if($this->work == 'period'){

						$displayInfo['aveWorkday'] = round($displayInfo['workday']/(checkMonthPeriod($this->startDay,$this->endDay)*4));

					}else{

						$displayInfo['aveWorkday'] = "";

					}

					//月平均労働時間
					if($this->work == 'year'){

						$displayInfo['aveWorktimeMonth'] = round($displayInfo['worktime']/12,2);

					}else if($this->work == 'month'){

						$displayInfo['aveWorktimeMonth'] = $displayInfo['worktime'];

					}else if($this->work == 'period'){

						$displayInfo['aveWorktimeMonth'] = round($displayInfo['worktime']/checkMonthPeriod($this->startDay,$this->endDay),2);

					}else{

						$displayInfo['aveWorktimeMonth'] = "";

					}
					//週平均労働時間
					if($this->work == 'year'){

						$displayInfo['aveWorktimeWeek'] = round($displayInfo['worktime']/48,2);

					}else if($this->work == 'month'){

						$displayInfo['aveWorktimeWeek'] =round( $displayInfo['worktime']/4,2);

					}else if($this->work == 'period'){

						$displayInfo['aveWorktimeWeek'] = round($displayInfo['worktime']/(checkMonthPeriod($this->startDay,$this->endDay)*4),2);

					}else{

						$displayInfo['aveWorktimeWeek'] = "";

					}

					//フィールド変数に配列として足しこみ
					$this->displayData[] = $displayInfo;

					//合計を管理する変数に各要素を挿入

					$this->sumArray['workday'] += $displayInfo['workday'];		//出勤日数
					$this->sumArray['business'] = $displayInfo['business'];		//営業日日数
					$this->sumArray['absence'] += $displayInfo['absence'];		//欠席日数
					$this->sumArray['resttime'] += $displayInfo['resttime'];	//休憩時間合計
					$this->sumArray['worktime'] += $displayInfo['worktime'];	//勤務時間合計
					$this->sumArray['aveWorkday'] += $displayInfo['aveWorkday'];	//週平均出勤日数
					$this->sumArray['aveWorktimeMonth'] += $displayInfo['aveWorktimeMonth'];	//月平均労働時間合計
					$this->sumArray['aveWorktimeWeek'] += $displayInfo['aveWorktimeWeek'];		//週平均郎等時間合計

					if($a < count($this->sumWorkData)-1){
						$a++;
					}

				}else{

					//表示用の配列を作成する
					$displayInfo['accountid'] = $this->accountData[$i]["accountid"];		//アカウントID
					$displayInfo['name'] = $this->accountData[$i]["name"];					//名前
					$displayInfo['workday'] = 0;											//出勤日合計
					$displayInfo['business'] = $day - $holiday;								//営業日日数
					$displayInfo['absence'] = 0;											//欠席日数
					$displayInfo['resttime'] = 0;											//休憩時間
					$displayInfo['worktime'] = 0;											//労働時間合計

					//週平均勤務日数
					$displayInfo['aveWorkday'] ="";

					//月平均労働時間

					$displayInfo['aveWorktimeMonth'] = "";

					//週平均労働時間

					$displayInfo['aveWorktimeWeek'] = "";

					//フィールド変数に配列として足しこみ
					$this->displayData[] = $displayInfo;

					//合計を管理する変数に各要素を挿入

					$this->sumArray['workday'] += $displayInfo['workday'];		//出勤日数
					$this->sumArray['business'] = $displayInfo['business'];		//営業日日数
					$this->sumArray['absence'] += $displayInfo['absence'];		//欠席日数
					$this->sumArray['resttime'] += $displayInfo['resttime'];	//休憩時間合計
					$this->sumArray['worktime'] += $displayInfo['worktime'];	//勤務時間合計
					$this->sumArray['aveWorkday'] += $displayInfo['aveWorkday'];	//週平均出勤日数
					$this->sumArray['aveWorktimeMonth'] += $displayInfo['aveWorktimeMonth'];	//月平均労働時間合計
					$this->sumArray['aveWorktimeWeek'] += $displayInfo['aveWorktimeWeek'];		//週平均郎等時間合計

				}
			}


		//平均を管理する変数に各要素を代入
		if($this->sumWorkData != ""){	//データ件数が0ではない場合

		$this->aveArray['workday'] = round($this->sumArray['workday']/count($this->sumWorkData),2);		//出勤日数平均
		$this->aveArray['business'] = $this->sumArray['business'];										//営業日日数平均
		$this->aveArray['absence'] = round($this->sumArray['absence']/count($this->sumWorkData),2);		//欠席日数平均
		$this->aveArray['resttime'] = round($this->sumArray['resttime']/count($this->sumWorkData),2);	//休憩時間合計平均
		$this->aveArray['worktime'] = round($this->sumArray['worktime']/count($this->sumWorkData),2);	//勤務時間合計平均
		$this->aveArray['aveWorkday'] = round($this->sumArray['aveWorkday']/count($this->sumWorkData),2);//週平均出勤日数
		$this->aveArray['aveWorktimeMonth'] = round($this->sumArray['aveWorktimeMonth']/count($this->sumWorkData),2);	//月平均労働時間平均
		$this->aveArray['aveWorktimeWeek'] = round($this->sumArray['aveWorktimeWeek']/count($this->sumWorkData),2);	//週平均労働時間平均

		}

		//============================================================================================================//

		//個人表示の場合,1~12月までの表示を行う
		if($this->accountid != "%%")
		{
			//期間は月日を選択
			$months = "months";

			//合計勤務情報の数だけ処理を行う
			for($j=1;$j<=12;$j++){

				//sumWorkDataを再度初期化
				$this->sumWorkData = "";

				//フォームに選択された日の年数と月日を取得

				$monthDate = date("Y-m",strtotime("{$this->year}-{$j}"));	//月にはループの月と年を挿入

				//SQL文のWHERE句を設定
				$form2 = $this->form($months,$monthDate);

				//DBから合計の勤務情報を取得
				$this->selectSumWorkInfo($db,$form2);

				//フォームの期間の日数を取得
				$day = $this->countDate($months,$monthDate);

				//フォームの期間の休日数を取得
				$holiday = $this->countHoliday($db,$form2);

				//表示用の配列を初期化
				$displayInfo = "";

				//勤務情報がある場合のみ格納する
				if($this->sumWorkData[0] != 0){

					//このアカウントの勤務情報データをプロパティ変数に格納
					$this->workplaninfo = $this->selectWorkplaninfo($db,$this->sumWorkData[0]["accountid"],$form2);

					//このアカウントの休憩時間合計を取得
					$restTime = $this->selectSumRestTime($db,$this->sumWorkData[0]["accountid"]);

					//表示用の配列を作成する
					$displayInfo['accountid'] = $this->sumWorkData[0]['accountid'];			//アカウントID
					$displayInfo['name'] = "{$j}月";						//名前
					$displayInfo['workday'] = $this->sumWorkData[0]['cnt'];				//出勤日合計
					$displayInfo['business'] = $day - $holiday;									//営業日日数
					$displayInfo['absence'] = $this->selectSumAbsence($db,$statusid,$this->sumWorkData[0]['accountid'],$form2);//欠席日数
					$displayInfo['resttime'] = $restTime/3600;	//休憩時間
					$displayInfo['worktime'] = ($this->sumWorkData[0]['sum'] - $restTime)/3600;	//労働時間合計

					//週平均勤務日数
					$displayInfo['aveWorkday'] =round( $displayInfo['workday']/4,2);

					//月平均労働時間

					$displayInfo['aveWorktimeMonth'] = $displayInfo['worktime'];

					//週平均労働時間

					$displayInfo['aveWorktimeWeek'] =round( $displayInfo['worktime']/4,2);

					//フィールド変数に配列として足しこみ
					$this->monthDispData[] = $displayInfo;

					//合計を管理する変数に各要素を挿入

					$this->monthSumArray['workday'] += $displayInfo['workday'];		//出勤日数
					$this->monthSumArray['business'] += $displayInfo['business'];		//営業日日数
					$this->monthSumArray['absence'] += $displayInfo['absence'];		//欠席日数
					$this->monthSumArray['resttime'] += $displayInfo['resttime'];	//休憩時間合計
					$this->monthSumArray['worktime'] += $displayInfo['worktime'];	//勤務時間合計
					$this->monthSumArray['aveWorkday'] += $displayInfo['aveWorkday'];	//週平均出勤日数
					$this->monthSumArray['aveWorktimeMonth'] += $displayInfo['aveWorktimeMonth'];	//月平均労働時間
					$this->monthSumArray['aveWorktimeWeek'] += $displayInfo['aveWorktimeWeek'];		//週平均労働時間

				}else{

					//表示用の配列を作成する
					$displayInfo['accountid'] = "";									//アカウントID
					$displayInfo['name'] = "{$j}月";									//名前
					$displayInfo['workday'] = 0;									//出勤日合計
					$displayInfo['business'] = $day - $holiday;						//営業日日数
					$displayInfo['absence'] = $this->selectSumAbsence($db,$statusid,$this->accountid,$form2);//欠席日数
					$displayInfo['resttime'] = 0;															//休憩時間
					$displayInfo['worktime'] = 0;															//労働時間合計

					//週平均勤務日数
					$displayInfo['aveWorkday'] ="";

					//月平均労働時間

					$displayInfo['aveWorktimeMonth'] = "";

					//週平均労働時間

					$displayInfo['aveWorktimeWeek'] = "";

					//フィールド変数に配列として足しこみ
					$this->monthDispData[] = $displayInfo;

					//合計を管理する変数に各要素を挿入

					$this->monthSumArray['workday'] += $displayInfo['workday'];		//出勤日数
					$this->monthSumArray['business'] += $displayInfo['business'];		//営業日日数
					$this->monthSumArray['absence'] += $displayInfo['absence'];		//欠席日数
					$this->monthSumArray['resttime'] += $displayInfo['resttime'];	//休憩時間合計
					$this->monthSumArray['worktime'] += $displayInfo['worktime'];	//勤務時間合計
					$this->monthSumArray['aveWorkday'] += $displayInfo['aveWorkday'];	//週平均出勤日数
					$this->monthSumArray['aveWorktimeMonth'] += $displayInfo['aveWorktimeMonth'];	//月平均労働時間
					$this->monthSumArray['aveWorktimeWeek'] += $displayInfo['aveWorktimeWeek'];		//週平均労働時間

				}

			}



			//平均を管理する変数に各要素を代入
			if($this->monthDispData != ""):	//データ件数が0ではない場合

			$this->monthAveArray['workday'] = round($this->monthSumArray['workday']/12,2);		//出勤日数
			$this->monthAveArray['business'] = round($this->monthSumArray['business']/12,1);										//営業日日数
			$this->monthAveArray['absence'] = round($this->monthSumArray['absence']/12,2);		//欠席日数
			$this->monthAveArray['resttime'] = round($this->monthSumArray['resttime']/12,2);	//休憩時間合計
			$this->monthAveArray['worktime'] = round($this->monthSumArray['worktime']/12,2);	//勤務時間合計
			$this->monthAveArray['aveWorkday'] = round($this->monthSumArray['aveWorkday']/12,2);
			$this->monthAveArray['aveWorktimeMonth'] = round($this->monthSumArray['aveWorktimeMonth']/12,2);
			$this->monthAveArray['aveWorktimeWeek'] = round($this->monthSumArray['aveWorktimeWeek']/12,2);

			endif;
		}
	}

	/*====================================================================================
	 *概要：
	 *	selectWorkPlaninfo()
	 *機能説明：
	 *	アカウントIDを引数に情報をテーブルから全て取得し、取得した配列を返却する。。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/09/01
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)	2015/09/07
	 *	更新者)	水島創太
	 *	変更)	引数をフォームからaccountidに変更。
	 *			内部処理でもプロパティ変数のaccountidから引数を使用する処理に変更。
	 ====================================================================================
	 */

	private function selectWorkplaninfo($db,$accountid,$form){

		//MySQL文の用意
		$sql = "SELECT WP.accountid,WP.day,WP.workstarttime,WP.workendtime,
				time_to_sec(timediff(WP.workendtime,WP.workstarttime)) as worktime,
				P.`p-name`
				FROM workplaninfo WP
				INNER JOIN positioninfo P
				ON WP.positionid = P.positionid
				WHERE accountid = {$accountid} AND day {$form}
				ORDER BY day;";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_assoc($result)){
			$data[] = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data;
	}

	/*====================================================================================
	 *概要：
	 *	selectWorkPlaninfoByAccount()
	 *機能説明：
	 *	勤怠情報が登録されている全アカウント情報を取得しプロパティ変数に格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/09/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 *
	 ====================================================================================
	 */

	private function selectWorkplaninfoByAccount($db){

		//MySQL文の用意
		$sql = "SELECT WP.accountid,A.name FROM workplaninfo WP
				INNER JOIN accountinfo A ON WP.accountid = A.accountid
				GROUP BY WP.accountid ORDER BY accountid";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_assoc($result)){
			$this->accountData[] = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);
	}



	/*====================================================================================
	 *概要：
	 *	form
	 *機能説明：
	 *	SQL文のWHERE句で検索する期間を変更する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function form($work, $monthDate= ""){
		if($work == 'year'){
			$where = "LIKE '{$this->year}%'";
			$this->infomation = date('Y年', strtotime($this->year));
		}

		if($work == 'month'){
			if(!preg_match("/^[0-9]{4}-[0-9]{2}$/",$this->month)){
				callErrorPage("入力した値が正常ではありません。再度入力してください。","personalWorkTime");
				$_SESSION['errorAccount'] = $this->accountid;
				exit;
			}

			$where = "LIKE '{$this->month}%'";
			$this->infomation = date('Y年n月', strtotime($this->month));
		}

		if($work == 'period'){

			//endDayの末日を取得
			$endday = date("t", strtotime($this->endDay));

			$where = "BETWEEN '{$this->startDay}-1' AND '{$this->endDay}-{$endday}'";
			$this->infomation = date('Y年n月', strtotime($this->startDay))."～".
			date('Y年n月', strtotime($this->endDay));
		}

		if($work == 'months'){
			$where = "LIKE '{$monthDate}%'";
		}

		return $where;
	}

	/*====================================================================================
	 *概要：
	 *	countHoliday
	 *機能説明：
	 *	選ばれたフォームの日数を計算し,返却する
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function countDate($work,$months = ""){

		if($work == 'year'){
			$period = 365;
		}

		if($work == 'month'){
			$period = date('t', strtotime($this->month));
		}

		if($work == 'months'){
			$period = date('t', strtotime($months));
		}

		if($work == 'period'){

			//終了日の末日を取得
			$endday = date("t", strtotime($this->endDay));

			// 日付をUNIXタイムスタンプに変換
			$timestamp1 = strtotime($this->startDay."-1");
			$timestamp2 = strtotime($this->endDay."-{$endday}");

			// 何秒離れているかを計算
			$seconddiff = abs($timestamp2 - $timestamp1);

			// 日数に変換
			$period = $seconddiff / (60 * 60 * 24);

		}

		return $period;

	}


	/*====================================================================================
	 *概要：
	 *	countHoliday
	 *機能説明：
	 *	SQL文のcount句を使用し、休日数を数える
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function countHoliday($db,$form){

		//MySQL文の用意
		$sql = "SELECT COUNT(*) FROM holidayinfo WHERE day {$form}";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_row($result)){
			$data = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data[0];

	}

	/*====================================================================================
	 *概要：
	 *	createMonth
	 *機能説明：
	 *	入力フォームに入力された期間のデータのカレンダーを作成する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function createMonth($db,$workdata){

		$j=0;

		$lastDay = date("t", strtotime($this->year."-".$this->month));

		for($i=0; $i<$lastDay; $i++){
			$day = date("Y-m-d", strtotime($this->month."-".$i."+ 1day"));

			$monthdata[$i] = array($day,'','','');

			if(isset($workdata[$j])){
				if($day == $workdata[$j][0]){
					$monthdata[$i] = $workdata[$j];
					$j++;
				}
			}
		}
		return $monthdata;
	}

	/*====================================================================================
	 *概要：
	 *	selectRestTimeInfo
	 *機能説明：
	 *	resttimreinfoから条件に一致する休憩時間情報を取得する。
	 *引数：
	 *	データベース情報,$dayOfWeek（曜日）,$type(種別)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectRestTimeInfo($db,$dayOfWeek,$type){

		//MySQL文の用意
		$sql ="SELECT dayofweek,reststarttime,restendtime,time_to_sec(timediff(restendtime,reststarttime))as resttime,type
				FROM resttimeinfo WHERE dayofweek = '{$dayOfWeek}' AND TYPE = '{$type}'";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($array = mysql_fetch_assoc($result)){
			$data[] = $array;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data;

	}

	/*====================================================================================
	 *概要：
	 *	selectSumWorkInfo
	 *機能説明：
	 *	データベースからacoountinfo,workplaninfo,positioninfoを結合し合計のデータを
	 *	配列として取得し,$sumWorkDataに格納する
	 *引数：
	 *	データベース情報,$form(期間)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/09/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectSumWorkInfo($db,$form){

		//MySQL文の用意
		$sql ="SELECT A.name, WP.accountid, (COUNT(*)-COUNT( WP.statusid = 3 )) as cnt , WP.day, WP.workstarttime, WP.workendtime,
			 SUM( TIME_TO_SEC( TIMEDIFF( WP.workendtime, WP.workstarttime ) ) ) as sum
			 FROM accountinfo A
			 LEFT JOIN workplaninfo WP ON A.accountid = WP.accountid
			 WHERE WP.day {$form}
			 AND WP.accountid LIKE '{$this->accountid}'
			 GROUP BY WP.accountid;";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//件数を獲得
		$rows = mysql_num_rows($result);

		//検索結果の確認
		if($rows > 0){

			//繰り返し処理を使用して全取得データをsumWorkDataに格納
			while($row = mysql_fetch_assoc($result)):

			//格納した1行データをsumWorkDataに配列で格納
			$this->sumWorkData[] = $row;

			endwhile;

		}else{

			$this->sumWorkData[] = 0;

		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}

	/*====================================================================================
	 *概要：
	 *	selectSumRestTime
	 *機能説明：
	 *	そのアカウントの特定期間の
	 *	休憩時間を算出して返却する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	sumRestTime(休憩時間合計)
	 *備考：
	 *	作成日)	2015/09/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectSumRestTime($db){

		//戻り値となる休憩時間の合計を宣言
		$sumRestTime = 0;

		//勤務時間のデータを取得
		$workPlanInfo = $this->workplaninfo;

		//勤務時間分ループを回し,休憩時間を算出する
		for($j=0;$j < count($workPlanInfo);$j++){

			//役割を取得
			$position = $workPlanInfo[$j]["p-name"];

			//役割によってタイプを格納
			if($position = "講師"){
				$type = "1";
			}else{
				$type="2";
			}

			//その配列の日付を曜日情報に変換
			$datetime = new DateTime($workPlanInfo[$j]['day']);	//日付をDateTime型に変換
			$w = (int)$datetime->format('w');					//曜日を数値として格納

			//曜日とタイプを引数に休憩時間のデータを取得
			$restTime = $this->selectRestTimeInfo($db,$w,$type);

			//各時間をそれぞれ変数に格納

			$workStartTime = changeOfSecondByTime($workPlanInfo[$j]['workstarttime']);	//勤務開始時間
			$workEndTime = changeOfSecondByTime($workPlanInfo[$j]['workendtime']);		//勤務終了時間
			$restStartTime = changeOfSecondByTime($restTime[0]["reststarttime"]);			//休憩開始時間
			$restEndTime = changeOfSecondByTime($restTime[0]["restendtime"]);				//休憩終了時間

			//勤務時間と照合し,勤務時間内の休憩時間であれば休憩時間の合計に足しこむ
			if($workStartTime <= $restStartTime && $workEndTime >= $restEndTime){

				$sumRestTime += $restTime[0]['resttime'];

			}

		}

		return $sumRestTime;

	}

	/*====================================================================================
	 *概要：
	 *	selectHolidayByForm
	 *機能説明：
	 *	特定期間の休日数をカウントし、値を返す。
	 *引数：
	 *	データベース情報,$i(インデックス番号)
	 *戻り値：
	 *	data(休日数)
	 *備考：
	 *	作成日)	2015/09/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectHolidayByForm($db){

		//フォームから期間を取得
		$form = $this->form();

		//MySQL文の用意
		$sql = "SELECT COUNT(*) as cnt FROM holidayinfo WHERE day {$form}";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_assoc($result)){
			$data = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data['cnt'];

	}

	/*====================================================================================
	 *概要：
	 *	selectSumAbsence
	 *機能説明：
	 *	そのアカウントの特定期間の
	 *	欠席数を算出して返却する。
	 *引数：
	 *	データベース情報,ステータスID,アカウントID
	 *戻り値：
	 *	sumAbsence(休憩時間合計)
	 *備考：
	 *	作成日)	2015/09/14
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectSumAbsence($db,$statusid,$accountid,$form){

		//SQL文をセット
		$sql = "SELECT COUNT(*) as cnt
				FROM workstatusinfo
				WHERE accountid = {$accountid}
				AND statusid = {$statusid}
				AND day {$form}";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//件数を獲得
		$rows = mysql_num_rows($result);

		if($rows>0){

			//結果セットの行数を取得する
			while($row = mysql_fetch_assoc($result)){
				$data = $row;
			}

			//結果保持用メモリを開放する
			mysql_free_result($result);

			return $data['cnt'];

		}else{

			return 0;

		}
	}


	/*====================================================================================
	 *概要：
	 *	selectStatusIdByName
	 *機能説明：
	 *	引数にした名前と一致するステータスのIDが何番か取得する。
	 *引数：
	 *	データベース情報,名前
	 *戻り値：
	 *	true or false
	 *備考：
	 *	作成日)	2015/09/14
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function selectStatusIdByName($db,$name){

		//MySQL文の用意
		$sql = "SELECT * FROM statusinfo
				WHERE name = '{$name}'";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットで取得した件数をrowsに代入する。
		$rows = mysql_num_rows($result);

		//データがあったかどうかでtrueかfalseを格納
		if($rows>0){
			while($row = mysql_fetch_assoc($result)){
				$data = $row;
			}
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data["statusid"];
	}
}
?>