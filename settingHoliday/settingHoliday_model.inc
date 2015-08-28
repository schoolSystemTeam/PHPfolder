<?php

class settingHoliday_model{

	private $holiday;
	private $type;
	private $holidaydata;
	private $startHoliday;
	private $endHoliday;
	private $endMinuts;
	private $seminarStartHour;
	private $seminarStartMinuts;
	private $updateid;
	private $deleteid;
	private $execute;

	//コンストラクタ定義
	public function __constract(){
		$this->init();
	}

	//初期化関数定義
	public function init(){
		$this->holiday = '';
		$this->type = '';
		$this->holidaydata = array();
		$this->startMinuts = array();
		$this->endHour = array();
		$this->endMinuts = array();
		$this->seminarStartHour = array();
		$this->seminarStartMinuts = array();
		$this->updateid = '';
		$this->deleteid = null;
		$this->execute = '';
	}

	//各変数のセッターメソッド
	public function setHoliday($param){
		$this->holidya = $param;
	}
	public function setType($param){
		$this->type = $param;
	}
	public function setHolidayData($param){
		$this->holidaydata = $param;
	}
	public function setStartHoliday($param){
		$this->startHoliday = $param;
	}
	public function setEndHoliday($param){
		$this->endHoliday = $param;
	}
	public function setEndMinuts($param){
		$this->endMinuts = $param;
	}
	public function setSeminarStartHour($param){
		$this->seminarStartHour = $param;
	}
	public function setSeminarStartMinuts($param){
		$this->seminarStartMinuts = $param;
	}
	public function setSeminarEndHour($param){
		$this->seminarEndHour = $param;
	}
	public function setSeminarEndMinuts($param){
		$this->seminarEndMinuts = $param;
	}

	//各変数のセッターメソッド
	public function getHoliday(){
		return $this->resttimedata;
	}
	public function getType(){
		return $this->type;
	}
	public function getHolidayData(){
		return $this->holidaydata;
	}
	public function getStartHoliday(){
		return $this->startHoliday;
	}
	public function getEndHoliday(){
		return $this->endHoliday;
	}
	public function getEndMinuts(){
		return $this->endHour;
	}
	public function getSeminarStartHour(){
		return $this->seminarStartHour;
	}
	public function getSeminarStartMinuts(){
		return $this->seminarStartMinuts;
	}
	public function getSeminarEndHour(){
		return $this->seminarEndHour;
	}
	public function getSeminarEndMinuts(){
		return $this->seminarEndMinuts;
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
		if(isset($_POST['endMinuts'])){
			$this->endMinuts = $_POST['endMinuts'];
		}
		if(isset($_POST['seminarStartHour'])){
			$this->seminarStartHour = $_POST['seminarStartHour'];
		}
		if(isset($_POST['seminarStartMinuts'])){
			$this->seminarStartMinuts = $_POST['seminarStartMinuts'];
		}
		if(isset($_GET['updateid'])){
			$this->updateid = $_GET['updateid'];
		}
		if(isset($_GET['deleteid'])){
			$this->deleteid = $_GET['deleteid'];
		}
		if(isset($_POST['setSingle'])){
			$this->execute = $_POST['setSingle'];
		}
	}

	public function prosessing($db){

		if(isset($this->deleteid)){
			$this->delete($db);
		}

		//ログインボタン押下したか判断
		if($this->execute == "登録"){
				$this->insert($db);
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

	public function insert($db){
		$sql = "INSERT INTO holidayinfo VALUE
				(null,'{$this->holiday}',{$this->type},'1',NOW(),NOW())";

			$result = mysql_query($sql,$db);
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