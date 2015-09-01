<?php

class settingHoliday_model{

	private $holiday;
	private $type;
	private $dayOfWeek;
	private $startHoliday;
	private $endHoliday;
	private $updateid;
	private $deleteid;
	private $execute;
	private $textarea;
	private $holidaydata;
	private $page;

	//コンストラクタ定義
	public function __constract(){
		$this->init();
	}

	//初期化関数定義
	public function init(){
		$this->holiday = '';
		$this->type = '';
		$this->dayOfWeek = array();
		$this->startHoliday = '';
		$this->endHoliday = '';
		$this->updateid = '';
		$this->deleteid = null;
		$this->execute = '';
		$this->textarea = '';
		$this->holidaydata = array();
		$this->page = 0;
	}

	//各変数のセッターメソッド
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
	public function setUpdateId($param){
		$this->updateid = $param;
	}
	public function setDeleteId($param){
		$this->deleteid = $param;
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

	//各変数のセッターメソッド
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
	public function getUpdateid(){
		return $this->updateid;
	}
	public function getDeleteId(){
		return $this->deleteid;
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

	//入力フォームからの取得
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
		if(isset($_GET['updateid'])){
			$this->updateid = $_GET['updateid'];
		}
		if(isset($_GET['deleteid'])){
			$this->deleteid = $_GET['deleteid'];
		}
		if(isset($_POST['execute'])){
			$this->execute = $_POST['execute'];
		}
		if(isset($_POST['textarea'])){
			$this->textarea = $_POST['textarea'];
		}
		if(isset($_GET['page'])){
			$this->page = $_GET['page'];
		}
	}

	public function prosessing($db){

		if(isset($this->deleteid)){
			$this->delete($db);
		}

		//登録ボタンの種別を判断
		if($this->execute == "single"){
			$this->insert($db,$this->holiday,$this->type);
		}else if($this->execute == "StuSun"){
			$this->insertStuSun($db);
		}else if($this->execute == "bulk"){
			$this->insertTextArea($db);
		}

		$this->select($db);
	}

	public function select($db){
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT h.holidayid,h.day,t.name FROM holidayinfo h INNER JOIN
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

	public function insert($db,$holiday,$type){
		$sql = "INSERT INTO holidayinfo VALUE
				(null,'{$holiday}',{$type},'1',NOW(),NOW())";

			$result = mysql_query($sql,$db);
	}

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

	public function insertStuSun($db){
		$i=0;
		$dateEndtime = new DateTime("{$this->endHoliday}");

		while(true){
			$holiday = date('Y-m-d',strtotime("{$this->startHoliday} + {$i}day"));
			$dateStartTime = new DateTime("$holiday");
			$w = (int)$dateStartTime->format('w');

			if($this->dayOfWeek[0] == $w || $this->dayOfWeek[1] == $w){
				$this->insert($db,$holiday,$this->type);
			}

			if($dateStartTime > $dateEndtime){
				break;
			}
			$i++;
		}
	}

	public function delete($db){
		$sql = "DELETE FROM holidayinfo WHERE holidayid={$this->deleteid}";

		$result = mysql_query($sql,$db);
	}

	public function update($db){
		for($i=0; $i<count($this->dayofweek); $i++){
			$sql = "UPDATE resttimeinfo SET
					reststarttime = '{$this->startHour[$i]}:{$this->startMinuts[$i]}',
					restendtime = '{$this->endHour[$i]}:{$this->endMinuts[$i]}',
					updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='1'";

			$result = mysql_query($sql,$db);

			$sql = "UPDATE resttimeinfo SET
					reststarttime = '{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
					restendtime = '{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}',
					updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='2'";

			$result = mysql_query($sql,$db);
		}
	}
}
?>