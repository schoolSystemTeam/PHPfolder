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
	private $startDay;			//開始日付
	private $endDay;			//終了日付
	private $accountid;			//アカウント
	private $name;				//名前
	private $day;				//DB登録用日付
	private $status;			//ステータス
	private $memo;				//メモ
	private $execute;			//処理種別
	private $restdata;			//表示用休憩時間データ
	private $workdata;			//表示用勤務時間表データ
	private $position;			//表示用役割データ
	private $infomation;		//表示用インフォメーション
	private $statusinfo;		//入力フォーム用ステータス情報
	private $workstatus;		//表示用ステータスデータ
	private $sum;				//表示用勤務情報合計値
	private $holidayData;		//休日データ

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
		$this->name = '';				//名前
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
		$this->sum = array();			//表示用勤務情報合計値
		$this->holidayData = array();	//休日データ
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

	//表示用勤務情報合計値
	public function setSum($param){
		$this->Sum = $param;
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

	//表示用勤務情報合計値
	public function getSum(){
		return $this->sum;
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

		//検索条件
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
			$this->execute = $_POST["memo"];
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

		if($this->execute == '保存'){
			for($i=0; $i<count($this->day); $i++){
				if($this->selectStatusMemo($db,$i)){
					$this->updateStatusMemo($db,$i);
				}else{
					$this->insertStatusMemo($db,$i);
				}
			}
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


		//勤務日数と勤務時間の合計を取得
		$this->sum[] = $this->sumWork($data,$this->restdata);


		//休日のデータを取得
		$this->selectAllHoliday($db);


		//特定の種別の処理
		if($this->work == 'month'){

			//空の配列データを作成する
			$this->workdata[] = $this->createMonth($data);
		}else if($this->work == 'period'){

			//期間検索用の勤務日数と勤務時間の合計を取得
			$this->sum = $this->sumPeriodWork($data,$this->restdata);

			//空の配列データを作成する
			$this->createPeriod($data);
		}else{

			//配列として勤務情報を代入する
			$this->workdata[] = $data;
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
		$sql = "SELECT w.day,DATE_FORMAT(w.workstarttime,'%k:%i')as starttime,DATE_FORMAT(w.workendtime,'%k:%i')as endtime,
				time_to_sec(timediff(w.workendtime,w.workstarttime)),w.positionid, a.name
				FROM workplaninfo w INNER JOIN accountinfo a ON w.accountid = a.accountid
				WHERE w.accountid = {$this->accountid} AND w.day {$form} ORDER BY day";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($row = mysql_fetch_row($result)){
			$data[] = $row;
		}

		$this->name = $data[0][5];

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

				//WHERE句に追加するSQL文
				$where = "LIKE '{$this->year}%'";

				//検索フォームの初期化
				$this->month = '';
				$this->startDay = '';
				$this->endDay = '';

				//メッセージ
				$this->infomation = date('Y年', strtotime($this->year));
			}


			//月次で検索
			if($this->work == 'month'){

				//WHERE句に追加するSQL文
				$where = "LIKE '{$this->month}%'";

				//検索フォームの初期化
				$this->startDay = '';
				$this->endDay = '';

				//メッセージ
				$this->infomation = date('Y年n月', strtotime($this->month));
			}


			//期間で検索
			if($this->work == 'period'){

				//終了期間が開始期間よりも前に設定していないかチェック
				if($this->startDay > $this->endDay){
					callErrorPage("終了期間が開始期間よりも前に設定しています。再度入力してください。","personalWorkTime");
					$_SESSION['errorAccount'] = $this->accountid;
					exit;
				}

				//検索する期間が1年以上ではないかチェック
				$month1=date("Y",strtotime($this->startDay))*12+date("m",strtotime($this->startDay));
				$month2=date("Y",strtotime($this->endDay))*12+date("m",strtotime($this->endDay));
				$diff = $month2 - $month1;
				if($diff > 12){
					callErrorPage("検索する期間が1年以上です。再度入力してください。","personalWorkTime");
					$_SESSION['errorAccount'] = $this->accountid;
					exit;
				}

				//WHERE句に追加するSQL文
				$where = "BETWEEN '{$this->startDay}-01' AND '".date('Y-m-t',strtotime($this->endDay))."'";

				//検索フォームの初期化
				$this->month = '';

				//メッセージ
				if($this->startDay != $this->endDay){
					$this->infomation = date('Y年n月', strtotime($this->startDay))."～".
										date('Y年n月', strtotime($this->endDay));
				}else{
					$this->infomation = date('Y年n月', strtotime($this->startDay));
				}
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

	private function createMonth($workdata){

		//勤務表情報用の値
		$j=0;


		//指定した月の最終日を取得
		$lastDay = date("t", strtotime($this->month));


		//日数分繰り返し、配列データを作成
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
	 *	createPeriod
	 *機能説明：
	 *	期間検索で指定した月の日数分の配列を生成する。
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

	private function createPeriod($workdata){

		//勤務表情報用の値
		$k=0;


		//指定した月の差分を取得
		$date = $this->startDay."-1";
		$end = $this->endDay;
		$month1=date("Y",strtotime($date))*12+date("m",strtotime($date));
		$month2=date("Y",strtotime($end))*12+date("m",strtotime($end));
		$diff = $month2 - $month1+1;


		//日数分繰り返し、配列データを作成
		for($i=0; $i<$diff ; $i++){
			$lastDay = date("t", strtotime($date."+".$i."month"));
			$monthdata = array();
			for($j=0; $j<$lastDay; $j++){
				$day = date("Y-m-d", strtotime($date."+".$j."day +".$i."month"));


				//表示用の配列を作成
				$monthdata[$j] = array($day,'','','');


				//勤務表情報の配列にデータが存在し、かつ日付が一致している場合、代入する
				if(isset($workdata[$k])){
					if($day == $workdata[$k][0]){
						$monthdata[$j] = $workdata[$k];
						$k++;
					}
				}
			}

		//指定した月の日数分のデータを代入
		$this->workdata[$i] =$monthdata;
		}
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

	/*====================================================================================
	 *概要：
	 *	statusInsertStatusMemo
	 *機能説明：
	 *	設定したステータスとメモをDBに1行ずつ登録する。
	 *引数：
	 *	データベース情報、配列のインデックス番号
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

	private function insertStatusMemo($db,$i){

	//MySQL文の用意
	$sql ="INSERT INTO workstatusinfo VALUES
			(null,{$this->accountid},'{$this->day[$i]}',".$this->status[$i].",'".$this->memo[$i]."',
				NOW(),NOW())";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	}

	/*====================================================================================
	 *概要：
	 *	updateStatusMemo
	 *機能説明：
	 *	設定したステータスとメモを該当するアカウントと日付の行に変更する。
	 *引数：
	 *	データベース情報、配列のインデックス番号
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

	private function updateStatusMemo($db,$i){

	//MySQL文の用意
	$sql ="UPDATE workstatusinfo SET statusid = {$this->status[$i]}, memo = '{$this->memo[$i]}',
			updateday = NOW() WHERE accountid = {$this->accountid} AND day = '{$this->day[$i]}'";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	}

	/*====================================================================================
	 *概要：
	 *	selectStatusMemo
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

	private function selectStatusMemo($db,$i){

	//MySQL文の用意
	$sql ="SELECT day FROM workstatusinfo
			WHERE accountid = {$this->accountid} AND day = '{$this->day[$i]}'";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	$array = mysql_fetch_array($result);

	//結果保持用メモリを開放する
	mysql_free_result($result);

	//戻り値として返す
	return $array;

	}

	/*====================================================================================
	 *概要：
	 *	sumWork
	 *機能説明：
	 *	勤務日数と勤務時間の合計値を算出する。
	 *引数：
	 *	データベース情報,インデックス番号
	 *戻り値：
	 *	data(休日数)
	 *備考：
	 *	作成日)	2015/09/11
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function sumWork($data,$restdata){

		//勤務日数を算出し、代入
		$sum['sumDay'] = count($data);


		//変数の宣言
		$workTime = 0;


		//実働勤務時間の算出
		for($i=0;$i<count($data); $i++){


			//曜日を取得
			$datetime = new DateTime($data[$i][0]);
			$w = (int)$datetime->format('w');


			//実働時間を算出
			for($j=0; $j<count($restdata); $j++){
				if($restdata[$j]['dayofweek'] == $w){
					if($restdata[$j]['type'] == $data[$i][4]){
						$workTime += ($data[$i][3]-$restdata[$j]['resttime'])/3600;
						break;
					}
				}
			}
		}

		//合計勤務時間を代入
		$sum['sumWorkTime'] = $workTime;

		return $sum;
	}

	/*====================================================================================
	 *概要：
	 *	sumPeriodWork
	 *機能説明：
	 *	勤務日数と勤務時間の合計値を算出する。（期間検索のみ）
	 *引数：
	 *	データベース情報,$i(インデックス番号)
	 *戻り値：
	 *	data(休日数)
	 *備考：
	 *	作成日)	2015/09/11
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function sumPeriodWork($data,$restdata){

		//指定した月の差分を算出
		$month1=date("Y",strtotime($this->startDay))*12+date("m",strtotime($this->startDay));
		$month2=date("Y",strtotime($this->endDay))*12+date("m",strtotime($this->endDay));
		$diff = $month2 - $month1+1;


		//期間内の勤務日数と合計勤務日数を取得
		for($a=0; $a<$diff; $a++){
			$sum[$a]['sumDay'] = 0;
			$workTime = 0;
			$month = date('Y-m',strtotime($this->startDay."+".$a."month"));


			//勤務日数を算出
			for($b=0; $b<count($data); $b++){
				if(strstr($data[$b][0],$month)){
					$sum[$a]['sumDay'] += 1;

					$w = createDayOfWeek($data[$b][0]);

					//実働時間を算出
					for($j=0; $j<count($restdata); $j++){
						if($restdata[$j]['dayofweek'] == $w){
							if($restdata[$j]['type'] == $data[$b][4]){
								$workTime += ($data[$b][3]-$restdata[$j]['resttime'])/3600;
								break;
							}
						}
					}
				}
			}
			$sum[$a]['sumWorkTime'] = $workTime;
		}
		return $sum;
	}

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

	public function setDateClass($day){

		if(strlen($day) != 0 && !empty($day)){

			//曜日を日付から取得する
			$w = createDayOfWeek($day);

		}else{

			$w = "";

		}

		//日付と曜日ごとに条件でわけ、クラス名を格納する
		if($w == 0){

			$class = "holiday";

		}else if($this->checkEqualHoliday($day)){

			$class = "holiday";

		}else if($w == 6){

			$class = "saturday";

		}else if($w == 6){

			$class = "saturday";

		}else{

			$class = "";

		}

		return $class;
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
	private function checkEqualHoliday($day){

		//休日情報が取得できているかどうかをチェック
		if(is_array($this->holidayData))
		{

			//できていた場合ループを開始
			foreach ($this->holidayData as $value){

				//引数と一致する日付情報かをチェック
				if($day == $value['day']){

					//一致した場合その休日情報を戻り値に格納し、
					//ループを抜ける。
					$result = $value['code'];
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
		$sql = "SELECT h.day,t.code FROM holidayinfo h INNER JOIN
				typeinfo t ON h.typeid=t.typeid ORDER BY day";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_assoc($result)){
			$this->holidayData[] = $assoc;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}
}
?>