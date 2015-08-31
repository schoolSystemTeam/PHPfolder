<?php

class settingRestTime_model{

	private $resttimedata;
	private $dayofweek;
	private $startHour;
	private $startMinuts;
	private $endHour;
	private $endMinuts;
	private $seminarStartHour;
	private $seminarStartMinuts;
	private $seminarEndHour;
	private $seminarEndMinuts;
	private $execute;

	//コンストラクタ定義
	public function __constract(){
		$this->init();
	}

	//初期化関数定義
	public function init(){
		$this->resttimedata = array();
		$this->dayofweek = array();
		$this->startHour = array();
		$this->startMinuts = array();
		$this->endHour = array();
		$this->endMinuts = array();
		$this->seminarStartHour = array();
		$this->seminarStartMinuts = array();
		$this->seminarEndHour = array();
		$this->seminarEndMinuts = array();
		$this->execute = '';
	}

	//各変数のセッターメソッド
	public function setRestTimeData($param){
		$this->resttimedata = $param;
	}
	public function setDayOfWeek($param){
		$this->dayofweek = $param;
	}
	public function setStartHour($param){
		$this->startHour = $param;
	}
	public function setStartMinuts($param){
		$this->startMinuts = $param;
	}
	public function setEndHour($param){
		$this->endHour = $param;
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
	public function getRestTimeData(){
		return $this->resttimedata;
	}
	public function getDayOfWeek(){
		return $this->dayofweek;
	}
	public function getStartHour(){
		return $this->startHour;
	}
	public function getStartMinuts(){
		return $this->startMinuts;
	}
	public function getEndHour(){
		return $this->endHour;
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

		if(isset($_POST['dayofweek'])){
			$this->dayofweek = $_POST['dayofweek'];
		}
		if(isset($_POST['startHour'])){
			$this->startHour = $_POST['startHour'];
		}
		if(isset($_POST['startMinuts'])){
			$this->startMinuts = $_POST['startMinuts'];
		}
		if(isset($_POST['endHour'])){
			$this->endHour = $_POST['endHour'];
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
		if(isset($_POST['seminarEndHour'])){
			$this->seminarEndHour = $_POST['seminarEndHour'];
		}
		if(isset($_POST['seminarEndMinuts'])){
			$this->seminarEndMinuts = $_POST['seminarEndMinuts'];
		}
		if(isset($_POST['execute'])){
			$this->execute = $_POST['execute'];
		}
	}

	public function prosessing($db){

		//ログインボタン押下したか判断
		if($this->execute == "休憩時間を設定"){

			if($this->select($db)){
				$this->update($db);
				$this->resttimedata = $this->select($db);
			}else{
				$this->insert($db);
				$this->resttimedata = $this->select($db);
			}
		}else{
				$this->resttimedata = $this->select($db);
		}
	}

	public function select($db){
		//入力したユーザーIDとパスワードに該当するレコードがあるか検索するSQL文の設定
		$sql = "SELECT * FROM resttimeinfo";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_assoc($result)){
			$data[] = $assoc;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $data;
	}

	public function insert($db){

		for($i=0; $i<count($this->dayofweek); $i++){
			$sql = "INSERT INTO resttimeinfo VALUE
					(null,'{$this->dayofweek[$i]}','{$this->startHour[$i]}:{$this->startMinuts[$i]}',
					'{$this->endHour[$i]}:{$this->endMinuts[$i]}','1','1',NOW(),NOW())";

			$result = mysql_query($sql,$db);

			$sql = "INSERT INTO resttimeinfo VALUE
					(null,'{$this->dayofweek[$i]}','{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
					'{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}','1','2',NOW(),NOW())";

			$result = mysql_query($sql,$db);
		}
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