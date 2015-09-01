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
 	作成日        ：	2015/8/28
	=====================================================================================
 */

class settingHoliday_model{

	private $holiday;				//年月日
	private $type;					//公休/祝日
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
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
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
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function init(){
		$this->holiday = '';			//年月日
		$this->type = '';				//公休/祝日
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
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function setHoliday($param){
		$this->holidya = $param;
	}
	public function setType($param){
		$this->type = $param;
	}
	public function setDayOfWeek($param){
		$this->dayOfWeek = $param;
	}
	public function setStartHoliday($param){
		$this->startHoliday = $param;
	}
	public function setEndHoliday($param){
		$this->endHoliday = $param;
	}
	public function setHolidayId($param){
		$this->holidayid = $param;
	}
	public function setExecute($param){
		$this->execute = $param;
	}
	public function setTextarea($param){
		$this->textarea = $param;
	}
	public function setHolidayData($param){
		$this->holidaydata = $param;
	}
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
	 *	作成日)	2015/7/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	*/

	public function getHoliday(){
		return $this->resttimedata;
	}
	public function getType(){
		return $this->type;
	}
	public function getDayOfWeek(){
		return $this->dayOfWeek;
	}
	public function getStartHoliday(){
		return $this->startHoliday;
	}
	public function getEndHoliday(){
		return $this->endHoliday;
	}
	public function getHolidayId(){
		return $this->holidayid;
	}
	public function getExecute(){
		return $this->execute;
	}
	public function getTextarea(){
		return $this->textarea;
	}
	public function getHolidayData(){
		return $this->holidaydata;
	}
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
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function getForm(){

		if(isset($_POST['holiday'])){
			$this->holiday = $_POST['holiday'];
		}
		if(isset($_POST['type'])){
			$this->type = $_POST['type'];
		}
		if(isset($_POST['startHoliday'])){
			$this->startHoliday = $_POST['startHoliday'];
		}
		if(isset($_POST['endHoliday'])){
			$this->endHoliday = $_POST['endHoliday'];
		}
		if(isset($_POST['dayOfWeek'])){
			$this->dayOfWeek = $_POST['dayOfWeek'];
		}
		if(isset($_REQUEST['holidayid'])){
			$this->holidayid = $_REQUEST['holidayid'];
		}
		if(isset($_REQUEST['execute'])){
			$this->execute = $_REQUEST['execute'];
		}
		if(isset($_POST['textarea'])){
			$this->textarea = $_POST['textarea'];
		}
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

		if($this->execute == 'delete'){
			$this->delete($db);
		}

		if($this->execute == 'update'){
			$this->update($db);
		}

		//登録ボタンの種別を判断(個別登録)
		if($this->execute == "single"){
			$this->insert($db,$this->holiday,$this->type);
		}

		//登録ボタンの種別を判断(曜日一括登録)
		if($this->execute == "StuSun"){
			$this->insertStuSun($db);
		}

		//登録ボタンの種別を判断(CSV一括登録)
		if($this->execute == "bulk"){
			$this->insertTextArea($db);
		}

		$this->select($db);
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function select($db){
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT h.holidayid,h.day,t.typeid,t.name FROM holidayinfo h INNER JOIN
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insert($db,$holiday,$type){
		$sql = "INSERT INTO holidayinfo VALUE
				(null,'{$holiday}',{$type},'1',NOW(),NOW())";

			$result = mysql_query($sql,$db);
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertTextArea($db){
		$data = explode("\r\n",$this->textarea);

		for($i=0;$i<count($data); $i++){
			$data2 = explode(',',$data[$i]);
			if($data2[3] == '公休'){
				$data2[3] = 1;
			}else{
				$data2[3] = 2;
			}
			$this->insert($db,(string)$data2[0].+'/'.+$data2[1].+'/'.+(string)$data2[2],$data2[3]);
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertStuSun($db){
		$i=0;
		$dateEndtime = new DateTime("{$this->endHoliday}");

		while(true){
			$holiday = date('Y-m-d',strtotime("{$this->startHoliday} + {$i}day"));
			$dateStartTime = new DateTime("$holiday");
			$w = (int)$dateStartTime->format('w');

			if($dateStartTime > $dateEndtime){
				break;
			}

			if($this->dayOfWeek[0] == $w || $this->dayOfWeek[1] == $w){
				$this->insert($db,$holiday,$this->type);
			}

			$i++;
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function delete($db){
		$sql = "DELETE FROM holidayinfo WHERE holidayid={$this->deleteid}";

		$result = mysql_query($sql,$db);
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