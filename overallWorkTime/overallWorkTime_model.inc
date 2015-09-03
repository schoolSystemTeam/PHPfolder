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
 	作成日        ：	2015/9/1
	=====================================================================================
 */

class overallWorkTime_model{

	private $year;					//年月日
	private $month;					//休日の種類
	private $week;					//曜日
	private $day;					//休日開始日付
	private $startDay;				//休日終了日付
	private $endDay;				//休日ID
	private $name;					//名前
	private $execute;				//処理種別

	/*====================================================================================
	 *概要：
	 *	constract
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function __construct(){
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function init(){
		$this->year = '';				//年月日
		$this->month = '';				//休日の種類
		$this->week = '';				//曜日
		$this->day = '';				//休日開始日付
		$this->startDay = '';			//休日終了日付
		$this->endDay = '';				//休日ID
		$this->name = '';				//名前
		$this->execute = '';			//処理種別
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//年月日
	public function setYear($param){
		$this->year = $param;
	}

	//休日の種類
	public function setMonth($param){
		$this->month = $param;
	}

	//曜日
	public function setWeek($param){
		$this->week = $param;
	}

	//休日開始日付
	public function setDay($param){
		$this->day = $param;
	}

	//休日終了日付
	public function setStartDay($param){
		$this->startDay = $param;
	}

	//休日ID
	public function setEndDay($param){
		$this->endDay = $param;
	}

	//処理種別
	public function setName($param){
		$this->name = $param;
	}

	//CSV
	public function setExecute($param){
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	*/

	//年月日
	public function getYear(){
		return $this->year;
	}

	//休日の種類
	public function getMonth(){
		return $this->month;
	}

	//曜日
	public function getWeek(){
		return $this->week;
	}

	//休日開始日付
	public function getDay(){
		return $this->day;
	}

	//休日終了日付
	public function getStartDay(){
		return $this->startDay;
	}

	//休日ID
	public function getEndDay(){
		return $this->endDay;
	}

	//処理種別
	public function getName(){
		return $this->name;
	}

	//CSV
	public function getExecute(){
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//フォーム入力からの数値受け取り関数
	public function getForm(){

		//年月日
		if(isset($_POST['year'])){
			$this->year = $_POST['year'];
		}

		//休日の種類
		if(isset($_POST['month'])){
			$this->month = $_POST['month'];
		}

		//休日開始日付
		if(isset($_POST['week'])){
			$this->week = $_POST['week'];
		}

		//休日終了日付
		if(isset($_POST['day'])){
			$this->day = $_POST['day'];
		}

		//曜日
		if(isset($_POST['startDay'])){
			$this->startDay = $_POST['startDay'];
		}

		//休日ID
		if(isset($_REQUEST['endDay'])){
			$this->endDay = $_REQUEST['endDay'];
		}

		//処理種別
		if(isset($_REQUEST['name'])){
			$this->name = $_REQUEST['name'];
		}

		//CSV
		if(isset($_POST['execute'])){
			$this->execute = $_POST['execute'];
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function prosessing($db){

		//処理種別の判断(休日設定削除)
		if($this->execute == 'delete'){
			$this->delete($db);
		}

		//処理種別の判断(休日設定変更)
		if($this->execute == 'update'){
			$this->update($db);
		}

		//処理種別の判断(個別登録)
		if($this->execute == "single"){
			$this->insert($db,$this->holiday,$this->type);
		}

		//処理種別の判断(曜日一括登録)
		if($this->execute == "StuSun"){
			$this->insertStuSun($db);
		}

		//処理種別の判断(CSV一括登録)
		if($this->execute == "bulk"){
			$this->insertTextArea($db);
		}

		$this->select($db);
	}

	/*====================================================================================
	 *概要：
	 *	select()
	 *機能説明：
	 *	DBに登録した休日情報を全て取得してholidaydata変数に配列として
	 *	格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function selectAll($db){
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT a.acountid,a.name,count(w.day), WHERE GROUP BY accountid";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_assoc($result)){
			$this->holidaydata[] = $assoc;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}

	//SELECT COUNT( workplanid ) FROM workplaninfo

	/*====================================================================================
	 *概要：
	 *	insert()
	 *機能説明：
	 *	設定した休日をDBに登録する。
	 *引数：
	 *	データベース情報、休日情報、種類
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insert($db,$holiday,$type){
		//設定した休日を登録するSQL文の設定
		$sql = "INSERT INTO holidayinfo VALUE
				(null,'{$holiday}',{$type},'1',NOW(),NOW())";

		//SQLを発行する
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	insertTextArea()
	 *機能説明：
	 *	テキストエリア内の記述をCSV方式で休日を一括で登録する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertTextArea($db){

		//改行を区切りに指定して、配列に格納する
		$data = explode("\r\n",$this->textarea);

		//休日の種類を判別する
		for($i=0;$i<count($data); $i++){
			$data2 = explode(',',$data[$i]);
			if($data2[3] == '公休'){
				$data2[3] = 1;
			}else{
				$data2[3] = 2;
			}

			//DB登録用に日付を修正
			$day = "{$data2[0]}-{$data2[1]}-{$data2[2]}";

			//insert()関数を呼び出し
			$this->insert($db,$day,$data2[3]);
		}
	}

	/*====================================================================================
	 *概要：
	 *	insertStuSun()
	 *機能説明：
	 *	ある期間内の曜日を休日として登録する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertStuSun($db){
		$i=0;

		//終了日付をオブジェクト化
		$dateEndtime = new DateTime("{$this->endHoliday}");

		//期間内の日付をループする
		while(true){

			//開始日付からインクリメントする
			$holiday = date('Y-m-d',strtotime("{$this->startHoliday} + {$i}day"));

			//日付をオブジェクト化
			$dateStartTime = new DateTime("$holiday");

			//ある日付の曜日を数値として返す
			$w = (int)$dateStartTime->format('w');

			//終了日付より後になった場合ループを抜ける
			if($dateStartTime > $dateEndtime){
				break;
			}

			//指定した曜日に該当する日付のみ登録する
			if($this->dayOfWeek[0] == $w || $this->dayOfWeek[1] == $w){
				$this->insert($db,$holiday,$this->type);
			}

			$i++;
		}
	}

	/*====================================================================================
	 *概要：
	 *	delete()
	 *機能説明：
	 *	休日設定を一つ削除する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function delete($db){
		$sql = "DELETE FROM holidayinfo WHERE holidayid={$this->holidayid}";

		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	update()
	 *機能説明：
	 *	休日設定を一つ変更する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function update($db){
		$sql = "UPDATE holidayinfo SET day = '{$this->holiday}', typeid = {$this->type}, ";
		$sql .="updateday = NOW() WHERE holidayid = {$this->holidayid}";

		$result = mysql_query($sql,$db);

	}
}
?>