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
 	作成日        ：	2015/8/26
	=====================================================================================
 */

class personalWorkTime_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $year;				//ユーザーID
	private $month;				//パスワード
	private $week;				//確認用パスワード
	private $day;				//権限(1:一般 2:管理者)
	private $startDay;			//名前
	private $endDay;			//電話番号
	private $accountid;			//Eメール
	private $name;				//名前
	private $status;			//ステータス
	private $memo;				//メモ
	private $execute;			//処理種別
	private $workdata;			//処理種別

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
	 *	作成日)	2015/8/26
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

 	private function init(){

		$this->year = "";				//ユーザーID
		$this->month = "";				//パスワード
		$this->week = "";				//確認用パスワード
		$this->day = "";				//権限(1:一般 2:管理者)
		$this->startDay = "";			//名前
		$this->endDay = "";				//電話番号
		$this->accountid = 12;			//Eメール
		$this->name = '神田太郎';		//名前
		$this->status = '';				//ステータス
		$this->memo = '';				//メモ
		$this->execute = "";			//処理種別
		$this->workdata = array();		//処理種別

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
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//入力ユーザーID
	public function setYear($param){
		$this->year = $param;
	}

	//入力パスワード
	public function setMonth($param){
		$this->month = $param;
	}

	//入力確認用パスワード
	public function setWeek($param){
		$this->week = $param;
	}

	//入力権限
	public function setDay($param){
		$this->day = $param;
	}

	//名前
	public function setStartDay($param){
		$this->startday = $param;
	}

	//電話番号
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

	//アカウント
	public function setStatus($param){
		$this->status = $param;
	}

	//名前
	public function setMemo($param){
		$this->memo = $param;
	}

	//処理種別
	public function setExecute($param){
		$this->execute = $param;
	}

	public function setWorkData($param){
		$this->workdata = $param;
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
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//ユーザーID
	public function getYear(){
		return $this->year;
	}

	//パスワード
	public function getMonth(){
		return $this->month;
	}

	//確認用パスワード
	public function getWeek(){
		return $this->week;
	}

	//権限
	public function getDay(){
		return $this->day;
	}

	//名前
	public function getStartDat(){
		return $this->startday;
	}

	//電話番号
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


	public function getWorkData(){
		return $this->workdata;
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
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function processing($db){
		$this->select($db);
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

	private function select($db){

		//MySQL文の用意
		$sql = "SELECT A.day,A.workstarttime,A.workendtime,time_to_sec(timediff(workendtime,workstarttime)),
				B.statusid,B.memo,C.name
				FROM workplaninfo A LEFT JOIN workstatusinfo B ON A.accountid = B.accountid
				INNER JOIN statusinfo C ON B.statusid = C.statusid WHERE accountid = {$this->accountid}";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_array($result)){
			$this->workdata[] = $assoc;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		}


	/*====================================================================================
	 *概要：
	 *	selectAllColor()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$colorListに格納する。
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

		private function selectAllColor($db){

			//MySQL文の用意
			$sql = "SELECT * FROM colorinfo";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0):

				//繰り返し処理を使用して全取得データをbookListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$this->colorList[] = $row;

				endwhile;

			endif;

			//検索結果の開放
			mysql_free_result($result);

		}

	/*====================================================================================
	 *概要：
	 *	searchUser
	 *機能説明：
	 *	入力されたユーザー名を元に該当するデータを取得。
	 *	存在すればtrueをしなければfalseを返す
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

		private function searchUser($db){

			//MySQL文の用意
			$sql = "SELECT * FROM accountinfo WHERE userid = '{$this->userid}'";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果があるかどうかをチェック
			if($rows > 0){

				//ユーザー情報が存在する場合、trueを格納
				$tf = true;

			}else{

				$tf = false;

			}

			//検索結果の開放
			mysql_free_result($result);

			//結果を返す
			return $tf;
		}

	/*====================================================================================
	 *概要：
	 *	insert
	 *機能説明：
	 *	各入力フォームに入力されたデータを登録する。
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

		private function insertStatusMemo($db){

			//MySQL文の生成
			$sql  = "INSERT INTO workstatusinfo VALUES";
			$sql .= "(NULL,{$this->accouontid},'{$this->day}','{$this->password}',{$this->status},'{$this->memo}',";
			$sql .= "NOW(),NOW()";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}
}
?>