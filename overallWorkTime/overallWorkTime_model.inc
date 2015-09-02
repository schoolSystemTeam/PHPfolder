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

	private $work;					//年月日
	private $type;					//休日の種類
	private $dayOfWeek;				//曜日
	private $startHoliday;			//休日開始日付
	private $endHoliday;			//休日終了日付
	private $holidayid;				//休日ID
	private $execute;				//処理種別
	private $textarea;				//CSV一括登録用テキストエリア
	private $holidaydata;			//休日データ
	private $page;					//ページ

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

	public function __constract(){
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
		$this->holiday = '';			//年月日
		$this->type = '';				//休日の種類
		$this->dayOfWeek = array();		//曜日
		$this->startHoliday = '';		//休日開始日付
		$this->endHoliday = '';			//休日終了日付
		$this->holidayid = '';			//休日ID
		$this->execute = '';			//処理種別
		$this->textarea = '';			//CSV
		$this->holidaydata = array();	//休日データ
		$this->page = 0;				//ページ
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
	public function setHoliday($param){
		$this->holidya = $param;
	}

	//休日の種類
	public function setType($param){
		$this->type = $param;
	}

	//曜日
	public function setDayOfWeek($param){
		$this->dayOfWeek = $param;
	}

	//休日開始日付
	public function setStartHoliday($param){
		$this->startHoliday = $param;
	}

	//休日終了日付
	public function setEndHoliday($param){
		$this->endHoliday = $param;
	}

	//休日ID
	public function setHolidayId($param){
		$this->holidayid = $param;
	}

	//処理種別
	public function setExecute($param){
		$this->execute = $param;
	}

	//CSV
	public function setTextarea($param){
		$this->textarea = $param;
	}

	//休日データ（表示用）
	public function setHolidayData($param){
		$this->holidaydata = $param;
	}

	//ページ(表示用)
	public function setPage($param){
		$this->page = $param;
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
	public function getHoliday(){
		return $this->resttimedata;
	}

	//休日の種類
	public function getType(){
		return $this->type;
	}

	//曜日
	public function getDayOfWeek(){
		return $this->dayOfWeek;
	}

	//休日開始日付
	public function getStartHoliday(){
		return $this->startHoliday;
	}

	//休日終了日付
	public function getEndHoliday(){
		return $this->endHoliday;
	}

	//休日ID
	public function getHolidayId(){
		return $this->holidayid;
	}

	//処理種別
	public function getExecute(){
		return $this->execute;
	}

	//CSV
	public function getTextarea(){
		return $this->textarea;
	}

	//休日データ（表示用）
	public function getHolidayData(){
		return $this->holidaydata;
	}

	//ページ(表示用)
	public function getPage(){
		return $this->page;
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
		if(isset($_POST['holiday'])){
			$this->holiday = $_POST['holiday'];
		}

		//休日の種類
		if(isset($_POST['type'])){
			$this->type = $_POST['type'];
		}

		//休日開始日付
		if(isset($_POST['startHoliday'])){
			$this->startHoliday = $_POST['startHoliday'];
		}

		//休日終了日付
		if(isset($_POST['endHoliday'])){
			$this->endHoliday = $_POST['endHoliday'];
		}

		//曜日
		if(isset($_POST['dayOfWeek'])){
			$this->dayOfWeek = $_POST['dayOfWeek'];
		}

		//休日ID
		if(isset($_REQUEST['holidayid'])){
			$this->holidayid = $_REQUEST['holidayid'];
		}

		//処理種別
		if(isset($_REQUEST['execute'])){
			$this->execute = $_REQUEST['execute'];
		}

		//CSV
		if(isset($_POST['textarea'])){
			$this->textarea = $_POST['textarea'];
		}

		//ページ(表示用)
		if(isset($_GET['page'])){
			$this->page = $_GET['page'];
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

	public function select($db){
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT count(h.holidayid,h.day,t.typeid,t.name FROM holidayinfo h INNER JOIN
				typeinfo t ON h.typeid=t.typeid ORDER BY day";

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