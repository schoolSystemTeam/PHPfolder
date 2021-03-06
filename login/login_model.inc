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
 	作成日        ：	2015/8/26
	=====================================================================================
 */

class login_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $userid;	//ユーザーID
	private $password;	//パスワード
	private $error;		//エラー文字列
	private $execute;	//処理種別

	/*====================================================================================
	 *概要：
	 *	login_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/26
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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function init(){
		$this->userid = '';		//ユーザーID
		$this->password = '';	//パスワード
		$this->error = "";		//エラー文字列
		$this->execute = '';	//処理種別
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
		//ユーザーID
		public function setUserid($param){
			$this->userid = $param;
		}

		//パスワード
		public function setPassword($param){
			$this->password = $param;
		}

		public function setError($param){
			$this->error = $param;
		}

		//処理種別
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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//ユーザーID
		public function getUserid(){
			return $this->userid;
		}

		//パスワード
		public function getPassword(){
			return $this->password;
		}

		//エラー文字列
		public function getError(){
			return $this->error;
		}

		//処理種別
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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//入力フォームからの取得
		public function getForm(){

			//ユーザーID
			if(isset($_POST['userid'])){
				$this->userid = $_POST['userid'];
			}

			//パスワード
			if(isset($_POST['password'])){
				$this->password = $_POST['password'];
			}

			//処理種別（POST送信）
			if(isset($_POST['execute'])){
				$this->execute = $_POST['execute'];
			}

			//処理種別（GET送信）
			if(isset($_GET['execute'])){
				$this->execute = $_GET['execute'];
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
	 *	作成日)	2015/8/26
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function prosessing($db){

			//セッション開始
			session_start();

			//ログインボタン押下したか判断
			if($this->execute == "ログイン"){
				$userinfo = $this->comfirmUser($db);

				//入力した値が一致しているか判断
				if($userinfo){

					$_SESSION['userinfo'] = $userinfo;

					//画面からの入力値をクッキーに登録
					setcookie("user",$this->userid,(time() + 30 * 86400),'/');			//ユーザーIDを登録
					setcookie("password",$this->password,(time() + 30 * 86400),'/');	//パスワードを登録

					$this->recordLogintime($db,$userinfo['accountid']);

					//メニュー画面へ遷移
					header("Location: ../mainMenu/mainMenu.php");
					exit;
				}else{

					//エラーメッセージをプロパティ変数に格納
					$this->error = "入力されたユーザー名とパスワードが間違っています。";

				}

			}else if($this->execute == "logout"){

				//セッション情報を全て破棄する
				session_destroy();

			}else{	//初期起動の場合

				//クッキーへの登録情報があればクッキーから情報を取得
				$this->userid 	= 	$_COOKIE['user'];		//ユーザーID
				$this->password = 	$_COOKIE['password'];	//パスワード
			}
		}

	/*====================================================================================
	 *概要：
	 *	comfirmUser()
	 *機能説明：
	 *	accountinfoからユーザーIDとパスワードを引数にユーザー情報を
	 *	検索する。
	 *	該当するユーザー情報を戻り値として返し、無かった場合にはfalseを
	 *	返却する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/26
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)	2015/10/29
	 *	更新者)	鈴木一紘
	 *	変更)	パスワードをハッシュ化
	  ====================================================================================
	 */

		public function comfirmUser($db){

			$hash = hash('sha256',$this->password);

			//入力したユーザーIDとパスワードに該当するレコードがあるか検索するSQL文の設定
			$sql = "SELECT * FROM accountinfo
					WHERE userid='{$this->userid}'
					AND password= '{$hash}'";

			//SQLを発行する
			$result = mysql_query($sql,$db);

			//結果セットの行数を取得する
			$assoc = mysql_fetch_assoc($result);

			//結果保持用メモリを開放する
			mysql_free_result($result);

			return $assoc;
		}

	/*====================================================================================
	 *概要：
	 *	recordLogintime()
	 *機能説明：
	 *	ログインした日時とユーザーのアカウントIDを登録する。
	 *引数：
	 *	データベース情報,ログインしたユーザーのアカウントID
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/10/29
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function recordLogintime($db,$accountid){

			//ホスト名とブラウザ名、ログイン回数を取得
			$host = $_SERVER['SERVER_ADDR'];
			$browser = $_SERVER['HTTP_USER_AGENT'];
			$num = $this->serchLoginCount($db,$accountid);

			//ログインした日時とユーザーを登録するSQL文の設定
			$sql = "INSERT logininfo
					VALUES(null,'{$accountid}',NOW(),'{$host}','{$browser}',{$num})";

			//SQLを発行する
			$result = mysql_query($sql,$db);

		}

	/*====================================================================================
	 *概要：
	 *	serchLoginCount()
	 *機能説明：
	 *	ログインした日時とユーザーのアカウントIDを登録する。
	 *引数：
	 *	データベース情報,ログインしたユーザーのアカウントID
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/10/29
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function serchLoginCount($db,$accountid){

			//入力したユーザーIDとパスワードに該当するレコードがあるか検索するSQL文の設定
			$sql = "SELECT MAX(count) AS count FROM logininfo
					WHERE accountid = '{$accountid}'";

			//SQLを発行する
			$result = mysql_query($sql,$db);

			//結果セットの行数を取得する
			$assoc = mysql_fetch_assoc($result);

			if($assoc['count'] == null){
				$assoc = 0;
			}

			//結果保持用メモリを開放する
			mysql_free_result($result);

			return $assoc['count'] + 1;
		}
}
?>