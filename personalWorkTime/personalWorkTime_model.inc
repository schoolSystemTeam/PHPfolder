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
 	作成日        ：	2015/9/8
	=====================================================================================
 */

class personalWorkTime_model{

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
	private $status;			//ステータス
	private $memo;				//メモ
	private $execute;			//処理種別
	private $restdata;			//表示用休憩時間データ
	private $workdata;			//表示用勤務時間表データ
	private $position;			//表示用役割データ
	private $infomation;		//表示用インフォメーション
	private $statusinfo;		//入力フォーム用ステータス情報
	private $workstatus;		//表示用ステータスデータ

	/*====================================================================================
	 *概要：
	 *	construct
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/8
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
	 *	作成日)	2015/9/8
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
		$this->name = '神田太郎';		//名前
		$this->status = "";				//ステータス
		$this->memo = "";				//メモ
		$this->execute = "";			//処理種別
		$this->form = "";				//検索種別
		$this->workdata = array();		//表示用勤務時間表データ
		$this->restdata = array();		//表示用休憩時間データ
		$this->position = "";			//表示用役割データ
		$this->infomation = "";			//表示用インフォメーション
		$this->statusinfo = array();	//入力フォーム用ステータス情報
		$this->workstatus = array();	//表示用ステータスデータ
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
	 *	作成日)	2015/9/8
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

	//ステータス
	public function setStatus($param){
		$this->status = $param;
	}

	//メモ
	public function setMemo($param){
		$this->memo = $param;
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

	//表示用検索を行った日付
	public function setStatusInfo($param){
		$this->statusinfo = $param;
	}

	//表示用ステータスデータ
	public function setWorkStatus($param){
		$this->workstatus = $param;
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
	 *	作成日)	2015/9/8
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

	//ステータス
	public function getStatus(){
		return $this->status;
	}

	//メモ
	public function getMemo(){
		return $this->memo;
	}

	//処理種別
	public function getExecute(){
		return $this->execute;
	}

	//検索種別
	public function getWorkData(){
		return $this->workdata;
	}

	//表示用休憩時間
	public function getRestData(){
		return $this->restdata;
	}

	//表示用役割データ
	public function getPosition(){
		return $this->position;
	}

	//表示用検索を行った日付
	public function getInfomation(){
		return $this->infomation;
	}

	//入力フォーム用ステータス情報
	public function getStatusInfo(){
		return $this->statusinfo;
	}

	//表示用ステータスデータ
	public function getWorkStatus(){
		return $this->workstatus;
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
	 *	作成日)	2015/9/8
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
		if($_SERVER["REQUEST_METHOD"] != "POST"){
			$this->accountid = $_GET["accountid"];
		}else{
    		$this->accountid = $_POST["accountid"];
		}

		//名前
		if(isset($_POST["name"])){
			$this->name = $_POST["name"];
		}

		//ステータス
		if(isset($_POST["status"])){
			$this->status = $_POST["status"];
		}

		//メモ
		if(isset($_POST["memo"])){
			$this->memo = $_POST["memo"];
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
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function processing($db){

		//他のページから遷移したときの処理
		if($this->execute == ''){
			$this->month = date('Y-m');
			$this->work = 'month';
		}

		//SQL文のWHERE句を設定
		$form = $this->form();

		//DBから指定の期間内の勤務情報を取得
		$data = $this->selectWorkplaninfo($db,$form);

		//役割の取得
		$this->workstatus = $this->selectWorkStatusInfo($db, $form);

		//ステータスの取得
		$this->statusinfo = $this->statusInfo($db);

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
	 *	selectWorkplaninfo
	 *機能説明：
	 *	特定の期間から勤務情報をテーブルから取得する。
	 *引数：
	 *	データベース情報、期間を指定するWHERE句
	 *戻り値：
	 *	ある期間内の勤務情報
	 *備考：
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function selectWorkplaninfo($db,$form){

		//MySQL文の用意
		$sql = "SELECT day,workstarttime,workendtime,time_to_sec(timediff(workendtime,workstarttime))
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
	 *	なし
	 *戻り値：
	 *	WHERE句
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

			//年次で検索
			if($this->work == 'year'){
				$where = "LIKE '{$this->year}%'";
				$this->infomation = date('Y年', strtotime($this->year));
			}

			//月次で検索
			if($this->work == 'month'){
				$where = "LIKE '{$this->month}%'";
				$this->infomation = date('Y年n月', strtotime($this->month));
			}

			//週次で検索
			if($this->work == 'week'){
				$Sat = getWeekOfDay($this->week[0], $this->week[1], 6);
				if(strtotime($Sat)>strtotime($this->week[0].'+1 month')){
					$Sat = date('Y-m-t',strtotime($this->week[0]));
				}

				$Sun = date('Y-m-d',strtotime($Sat.'-6day'));
				if(strtotime($Sun)<strtotime($this->week[0])){
					$Sun = date('Y-m-d',strtotime($this->week[0].'-1'));
				}

				$where = "BETWEEN '{$Sun}' AND '{$Sat}'";
				$this->infomation = date('Y年n月', strtotime($this->week[0]))."第".$this->week[1]."週";
			}

			//日次で検索
			if($this->work == 'day'){
				$where = " = '{$this->day}'";

				//
				$this->infomation = date('Y年n月j日', strtotime($this->day));
			}

			//期間で検索
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
	 *	月次検索で指定した月の日数分の配列を生成する。
	 *引数：
	 *	データベース情報、勤務情報
	 *戻り値：
	 *	日数分の勤務情報
	 *備考：
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function createMonth($db,$workdata){

		//勤務表情報用の値
		$j=0;

		//指定した月の最終日を取得
		$lastDay = date("t", strtotime($this->month));

		//日数分繰り返し、配列デートを作成
		for($i=0; $i<$lastDay; $i++){
			$day = date("Y-m-d", strtotime($this->month."-".$i."+ 1day"));

			//空の配列を作成
			$monthdata[$i] = array($day,'','','');

			//勤務表情報の配列にデータが存在し、かつ日付が一致している場合、代入する
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
	 *	休憩時間の曜日、休憩時間、種別をresttimeinfoテーブルから取得する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	休憩時間情報
	 *備考：
	 *	作成日)	2015/9/8
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

	//戻り値として返す
	return $data;

	}

	/*====================================================================================
	 *概要：
	 *	selectPositionInfo
	 *機能説明：
	 *	個人の名前と役割をpositioninfoテーブルから取得する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	名前と役割を取得した変数
	 *備考：
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function selectPositionInfo($db){

	//MySQL文の用意
	$sql ="SELECT a.name, p.`p-name` FROM positioninfo p INNER JOIN accountinfo a
			ON p.positionid=a.positionid WHERE a.accountid = '{$this->accountid}'";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	while($array = mysql_fetch_array($result)){
		$data = $array;
	}

	//結果保持用メモリを開放する
	mysql_free_result($result);

	//戻り値として返す
	return $data;

	}

	/*====================================================================================
	 *概要：
	 *	selectWorkStatusInfo
	 *機能説明：
	 *	日付、ステータス番号、ステータスの名前、メモをテーブルから取得する。
	 *引数：
	 *	データベース情報、勤務情報
	 *戻り値：
	 *	日付、ステータス番号、ステータスの名前、メモを格納した配列
	 *備考：
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function selectWorkStatusInfo($db,$form){

	//MySQL文の用意
	$sql ="SELECT w.day, s.statusid, s.name, w.memo FROM workstatusinfo w INNER JOIN statusinfo s
			ON w.statusid = s.statusid
			WHERE w.accountid = '{$this->accountid}' AND w.day {$form} ORDER BY day";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	while($array = mysql_fetch_array($result)){
		$data[] = $array;
	}

	//結果保持用メモリを開放する
	mysql_free_result($result);

	//戻り値として返す
	return $data;

	}

	/*====================================================================================
	 *概要：
	 *	statusInfo
	 *機能説明：
	 *	ステータス番号と名前をstatusinfoテーブルから取得する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	ステータス番号と名前を取得した配列
	 *備考：
	 *	作成日)	2015/9/8
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	private function statusInfo($db){

	//MySQL文の用意
	$sql ="SELECT statusid, name FROM statusinfo";

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
}
?>