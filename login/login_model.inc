<?php

class login_model{

	private $userid;
	private $password;

	//コンストラクタ定義
	public function __constract(){
		$this->init();
	}

	//初期化関数定義
	public function init(){
		$this->userid = '';
		$this->password = '';
	}

	//各変数のセッターメソッド
	public function setUserid($param){
		$this->userid = $param;
	}
	public function setPassword($param){
		$this->password = $param;
	}

	//各変数のゲッターメソッド
	public function getUserid(){
		return $this->userid;
	}
	public function getPassword(){
		return $this->password;
	}

	//各フォームから値を取得

}
?>