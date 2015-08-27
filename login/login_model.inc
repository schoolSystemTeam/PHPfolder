<?php

class login_model{

	private $userid;
	private $password;
	private $execute;

	//コンストラクタ定義
	public function __constract(){
		$this->init();
	}

	//初期化関数定義
	public function init(){
		$this->userid = '';
		$this->password = '';
		$this->execute = '';
	}

	//各変数のセッターメソッド
	public function setUserid($param){
		$this->userid = $param;
	}
	public function setPassword($param){
		$this->password = $param;
	}
	public function setExecute($param){
		$this->execute = $param;
	}

	//各変数のセッターメソッド
	public function getUserid(){
		return $thid->userid;
	}
	public function getPassword(){
		return $this->password;
	}
	public function getExecute(){
		return $this->execute;
	}

	//入力フォームからの取得
	public function getForm(){

		if(isset($_POST['userid'])){
			$this->userid = $_POST['userid'];
		}
		if(isset($_POST['password'])){
			$this->password = $_POST['password'];
		}
		if(isset($_POST['execute'])){
			$this->execute = $_POST['execute'];
		}
	}

	public function prosessing($db){

		//セッション開始
		session_start();

		//ログインボタン押下したか判断
		if($this->execute == "ログイン"){
			$userinfo = $this->comfirmUser($db);

			//入力した値が一致しているか判断
			if($userinfo){

				$_SESSION['userinfo'] = $userinfo;
				//メニュー画面へ遷移
				header("Location: ../mainMenu/mainMenu.php");
				exit;
			}
		}
	}

	public function comfirmUser($db){
		//入力したユーザーIDとパスワードに該当するレコードがあるか検索するSQL文の設定
		$sql = "SELECT * FROM accountinfo
				WHERE userid='{$this->userid}' AND password='{$this->password}'";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		$assoc = mysql_fetch_assoc($result);

		//結果保持用メモリを開放する
		mysql_free_result($result);

		return $assoc;
	}
}
?>