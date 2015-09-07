<?php
/**
 * =====================================================================================
 プログラム名  ：	勤怠管理システム（Web版）
 プログラム説明：社員の勤怠情報を管理するシステムです。
 管理者はカレンダーを使用して視覚的に勤怠の登録、削除、変更
 を行えるほか各社員の勤怠情報の閲覧、休日、休憩時間の設定
 機能を使用することができます。

 勤怠情報とカレンダー部分はPDF,EXCEL出力することが可能です。
 作成者        ：	鈴木一
 作成日        ：	2015/8/26
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
	private $holidaydata;		//休日用データ
	private $sumWorkData;		//勤務時間表合計データ
	private	$displayData;		//勤務時間表表示用データ
	private $sumArray;			//各要素合計格納用配列
	private $aveArray;			//各要素平均格納用配列
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

		$this->work = "month";			//検索条件
		$this->year = "";				//年
		$this->month = date("Y-m");		//月
		$this->week = "";				//週
		$this->day = "";				//日
		$this->startDay = "";			//期間検索の開始日付
		$this->endDay = "";				//期間検索の終了日付
		$this->accountid = 12;			//アカウント
		$this->name = '神田太郎';		//
		$this->execute = "";			//処理種別
		$this->form = '';				//検索種別
		$this->workdata = array();		//表示用勤務時間表データ
		$this->restdata = array();		//表示用休憩時間データ
		$this->holidaydata = "";		//休日用データ
		$this->sumWorkData = "";		//勤務時間表合計データ
		$this->displayData = "";		//勤務時間表表示用データ
		$this->sumArray;				//各要素合計格納用配列
	 	$this->aveArray;				//各要素平均格納用配列
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
		$this->startday = $param;
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

	//各要素合計格納用配列
	public function setSumArray($param){
		$this->sumArray = $param;
	}

	//各要素平均格納用配列
	public function setAveArray($param){
		$this->aveArray = $param;
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
		return $this->startday;
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

	//各要素合計格納用配列
	public function getSumArray(){
		return $this->sumArray;
	}

	//各要素平均格納用配列
	public function getAveArray(){
		return $this->aveArray;
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

		//年
		if(isset($_POST["work"])){
			$this->work = $_POST["work"];
		}

		//年
		if(isset($_POST["year"])){
			$this->year = $_POST["year"];
		}

		//月
		if(isset($_POST["month"])){
			$this->month = $_POST["month"];
		}

		//週
		if(isset($_POST["week"])){
			$this->week = $_POST["week"];
		}

		//日
		if(isset($_POST["day"])){
			$this->day = $_POST["day"];
		}

		//開始日付
		if(isset($_POST["startDay"])){
			$this->startDay = $_POST["startDay"];
		}

		//終了日付
		if(isset($_POST["endDay"])){
			$this->endDay = $_POST["endDay"];
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
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	public function processing($db){

		//SQL文のWHERE句を設定
		$form = $this->form();

		//DBから合計の勤務情報を取得
		$this->selectSumWorkInfo($db,$form);

		//フォームの期間の日数を取得
		$day = $this->countDate();

		//フォームの期間の休日数を取得
		$holiday = $this->countHoliday($db);
		//合計勤務情報の数だけ処理を行う
		for($i=0;$i<count($this->sumWorkData);$i++){

			//このアカウントの休憩時間合計を取得
			$restTime = $this->selectSumRestTime($db,$i);

			//表示用の配列を初期化
			$displayInfo = "";

			//表示用の配列を作成する
			$displayInfo['accountid'] = $this->sumWorkData[$i]['accountid'];			//アカウントID
			$displayInfo['name'] = $this->sumWorkData[$i]['name'];						//名前
			$displayInfo['workday'] = $this->sumWorkData[$i]['COUNT(*)'];				//出勤日合計
			$displayInfo['business'] = $day - $holiday;									//営業日日数
			$displayInfo['absence'] = $displayInfo['business'] - $displayInfo['workday'];//欠席日数
			$displayInfo['resttime'] = $restTime/3600;	//休憩時間
			$displayInfo['worktime'] = ($this->sumWorkData['SUM( TIME_TO_SEC( TIMEDIFF( WP.workendtime, WP.workstarttime ) ) )'] - $restTime)/3600;	//労働時間合計

			//月平均労働時間
			if($this->work == 'year')
			{

				$displayInfo['aveWorktimeMonth'] = $displayInfo['worktime']/12;

			}else if($this->month == 'month'){

				$displayInfo['aveWorktimeMonth'] = $displayInfo['worktime'];

			}else{

				$displayInfo['aveWorktimeMonth'] = "";

			}
			//週平均労働時間
			if($this->work == 'year')
			{

				$displayInfo['aveWorktimeWeek'] = $displayInfo['worktime']/48;

			}else if($this->work == 'month'){

				$displayInfo['aveWorktimeWeek'] = $displayInfo['worktime']/4;

			}else if($this->work == 'week'){

				$displayInfo['aveWorktimeWeek'] = $displayInfo['worktime'];

			}else{

				$displayInfo['aveWorktimeWeek'] = "";

			}

			//フィールド変数に配列として足しこみ
			$this->displayData[] = $displayInfo;

			//合計を管理する変数に各要素を挿入
			$this->sumArray['workday'] += $displayInfo['workday'];		//出勤日数
			$this->sumArray['business'] += $displayInfo['business'];	//営業日日数
			$this->sumArray['absence'] += $displayInfo['absence'];		//欠席日数
			$this->sumArray['resttime'] += $displayInfo['resttime'];	//休憩時間合計
			$this->sumArray['worktime'] += $displayInfo['worktime'];	//勤務時間合計
			$this->sumArray['aveWorktimeMonth'] += $displayInfo['aveWorktimeMonth'];
			$this->sumArray['aveWorktimeWeek'] += $displayInfo['aveWorktimeWeek'];


		}

		//平均を管理する変数に各要素を代入
		$this->aveArray['workday'] = $this->sumArray['workday'];		//出勤日数
		$this->aveArray['business'] = $this->sumArray['business'];	//営業日日数
		$this->aveArray['absence'] = $this->sumArray['absence'];		//欠席日数
		$this->aveArray['resttime'] = $this->sumArray['resttime'];	//休憩時間合計
		$this->aveArray['worktime'] = $this->sumArray['worktime'];	//勤務時間合計
		$this->aveArray['aveWorktimeMonth'] = $$this->sumArray['aveWorktimeMonth'];
		$this->aveArray['aveWorktimeWeek'] = $this->sumArray['aveWorktimeWeek'];
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

	private function selectWorkplaninfo($db,$accountid){

		//期間を算出し$formに格納する。
		$form = $this->form();

		//MySQL文の用意
		$sql = "SELECT accountid,day,workstarttime,workendtime,time_to_sec(timediff(workendtime,workstarttime))
				FROM workplaninfo WHERE accountid = {$accountid} AND day {$form} ORDER BY day";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_row($result)){
			$data[] = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data;
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

	private function form(){
		if($this->work == 'year'){
			$where = "LIKE '{$this->year}%'";
			$this->infomation = date('Y年', strtotime($this->year));
		}

		if($this->work == 'month'){
			$where = "LIKE '{$this->month}%'";
			$this->infomation = date('Y年n月', strtotime($this->month));
		}

		if($this->work == 'week'){
			$date = date('Y-m-d',strtotime($this->month."-".$this->month));
		}

		if($this->work == 'day'){
			$where = " = '{$this->day}'";
			$this->infomation = date('Y年n月j日', strtotime($this->day));
		}

		if($this->work == 'period'){
			$where = "BETWEEN '{$this->startDay}' AND '{$this->endDay}'";
			$this->infomation = date('Y年n月j日', strtotime($this->startDay))."～".
			date('Y年n月j日', strtotime($this->endDay));
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

	private function countDate(){

		if($this->work == 'year'){
			$period = 365;
		}

		if($this->work == 'month'){
			$date('t', strtotime($date));
		}

		if($this->work == 'week'){
			$date = date('Y-m-d',strtotime($this->month."-".$this->month));
		}

		if($this->work == 'day'){
			$where = " = '{$this->day}'";
			$this->infomation = date('Y年n月j日', strtotime($this->day));
		}

		if($this->work == 'period'){
			// 日付をUNIXタイムスタンプに変換
			$timestamp1 = strtotime($this->startDay);
			$timestamp2 = strtotime($this->endDay);

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

	private function countHoliday($db){

		//期間を算出し$formに格納する。
		$form = $this->form();

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

		return $data['COUNT(*)'];

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
		$sql ="SELECT dayofweek,reststarttime,restendtime,time_to_sec(timediff(restendtime,reststarttime))as resttime,type FROM resttimeinfo WHERE dayofweek =  '{$dayOfWeek}' AND TYPE =  '{$type}'";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($array = mysql_fetch_array($result)){
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
		$sql ="SELECT WP.accountid, COUNT( * ) , WP.day, WP.workstarttime, WP.workendtime, SUM( TIME_TO_SEC( TIMEDIFF( WP.workendtime, WP.workstarttime ) ) ) , A.name,P.`p-name` FROM workplaninfo WP INNER JOIN accountinfo A ON A.accountid = WP.accountid  INNER JOIN positioninfo P ON A.positionid = P.positionid WHERE WP.day {$this->form()} GROUP BY WP.accountid;";

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

		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}

	/*====================================================================================
	 *概要：
	 *	SumRestTime
	 *機能説明：
	 *	データベース情報とインデックス番号を引数にそのアカウントの特定期間の
	 *	休憩時間を算出して返却する。
	 *引数：
	 *	データベース情報,$i(インデックス番号)
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

	private function selectSumRestTime($db,$i){

		//戻り値となる休憩時間の合計を宣言
		$sumRestTime = 0;

		//勤務時間のデータを取得
		$workplanInfo = $this->selectWorkplaninfo($db,$this->sumWorkData[$i]['accountid']);

		//役割を取得
		$position = $this->sumWorkData[$i]['p-name'];

		//役割によってタイプを格納
		if($pisition = "講師"){
			$type = "1";
		}else{
			$type="2";
		}

		//勤務時間分ループを回し,休憩時間を算出する
		for($j=0;$j < count($workplanInfo);$j++){

			//その配列の日付を曜日情報に変換
			$datetime = new DateTime($workPlanInfo[$i]['day']);	//日付をDateTime型に変換
			$w = (int)$datetime->format('w');					//曜日を数値として格納

			//曜日とタイプを引数に休憩時間のデータを取得
			$restTime = $this->selectRestTimeInfo($db,$w,$type);

			//各時間をそれぞれ変数に格納

			$workStartTime = changeOfSecondByTime($workplanInfo[$i]['workstarttime']);	//勤務開始時間
			$workEndTime = changeOfSecondByTime($workplanInfo[$i]['workendtime']);		//勤務終了時間
			$restStartTime = changeOfSecondByTime($restTime['reststarttime']);			//休憩開始時間
			$restEndTime = changeOfSecondByTime($restTime['restendtime']);				//休憩終了時間

			//勤務時間と照合し,勤務時間内の休憩時間であれば休憩時間の合計に足しこむ
			if($workStartTime <= $restStartTime && $workEndTime >= $restEndTime){

				$sumRestTime += $restTime['restTime'];

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
		$sql = "SELECT COUNT(*) FROM holidayinfo WHERE day {$form}";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_row($result)){
			$data = $row;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data['COUNT(*)'];

	}

}
?>