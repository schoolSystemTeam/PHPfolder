<?php
/**
 * =====================================================================================
	プログラム名  ：	勤怠管理システム（Web版）
 	プログラム説明：社員の勤怠情報を管理するシステムです。
 				管理者はカレンダーを使用して視覚的に勤怠の登録、削除、変更
 				を行えるほか各社員の勤怠情報の閲覧、休日、休憩時間の設定
 				機能を使用することができます。

 				勤怠情報とカレンダー部分はPDF,EXCEL出力することが可能です。
 	作成者        ：	鈴木一紘
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
	private $restdata;			//表示用休憩時間データ
	private $workdata;			//表示用勤務時間表データ
	private $position;			//表示用役割データ
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
		$this->name = '神田太郎';		//名前
		$this->execute = "";			//処理種別
		$this->form = '';				//検索種別
		$this->workdata = array();		//表示用勤務時間表データ
		$this->restdata = array();		//表示用休憩時間データ
		$this->position = '';			//表示用役割データ
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

	//表示用勤務時間表データ
	public function setWorkData($param){
		$this->workdata = $param;
	}

	//表示用休憩時間データ
	public function setRestData($param){
		$this->restdata = $param;
	}

	//表示用休憩時間データ
	public function setPosition($param){
		$this->position = $param;
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

	//表示用役割データ
	public function getPosition(){
		return $this->position;
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

		//DBから指定の期間内の勤務情報を取得
		$data = $this->selectWorkplaninfo($db,$form);

		//休憩時間を取得
		$this->restdata = $this->selectRestTimeInfo($db);

		//役割の取得
		$this->position = $this->selectPositionInfo($db);

		//特定の種別の処理
		if($this->work == 'month'){
			$this->workdata = $this->createMonth($db,$data);
		}else{
			$this->workdata = $data;
		}
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function selectWorkplaninfo($db,$form){

		//MySQL文の用意
		$sql = "SELECT accountid,day,workstarttime,workendtime,time_to_sec(timediff(workendtime,workstarttime))
				FROM workplaninfo WHERE accountid = {$this->accountid} AND day {$form} ORDER BY day";

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
	 *	resttimreinfoから休憩時間を
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

	private function selectRestTimeInfo($db){

	//MySQL文の用意
	$sql ="SELECT dayofweek,time_to_sec(timediff(restendtime,reststarttime))as resttime,type FROM resttimeinfo";

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
	 *	insertStatusMemo
	 *機能説明：
	 *	入力フォームに入力されたステータスと備考欄を登録する。
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

	private function selectPositionInfo($db){

	//MySQL文の用意
	$sql ="SELECT a.accountid,a.name, p.`p-name` FROM positioninfo p INNER JOIN accountinfo a
			ON p.positionid=a.positionid WHERE a.accountid = '{$this->accountid}'";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	while($array = mysql_fetch_array($result)){
		$data = $array;
	}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data;

	}
}
?>