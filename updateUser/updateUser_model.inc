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
 	作成日        ：	2015/8/27
	=====================================================================================
 */

class updateUser_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $userid;		//ユーザーID
	private $password;		//パスワード
	private $checkPass;		//確認用パスワード
	private $authority;		//権限(1:一般 2:管理者)
	private $positionList;	//役割用配列
	private $colorList;		//表示色用配列
	private $accountid;		//選択したユーザーID
	private $userInfo;		//ユーザー情報
	private $accountList;	//ユーザー情報格納用配列
	private $positionid;	//役割管理用ID
	private $colorid;		//表示色管理用ID
	private $display;		//表示/非表示（1：表示 0：非表示）
	private $execute;		//処理種別

	/*====================================================================================
	 *概要：
	 *	updateUser_form
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
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

 	private function init(){

	$this->userid = "";			//ユーザーID
	$this->password = "";		//パスワード
	$this->checkPass = "";		//確認用パスワード
	$this->authority = "1";		//権限(1:一般 2:管理者)
	$this->positionList = "";	//役割用配列
	$this->colorList = "";		//表示色格納用配列
	$this->accountid = "";		//選択したユーザーID
	$this->userInfo = "";		//ユーザー情報
	$this->accountList = "";		//ユーザー情報格納用配列
	$this->positionid = "";		//役割管理用ID
	$this->colorid = "";		//表示色管理用ID
	$this->display = "";		//表示/非表示（1：表示 0：非表示）
	$this->execute = "";		//処理種別

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
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//入力ユーザーID
		public function setUserid($param)
		{
			$this->userid = $param;
		}

		//入力パスワード
		public function setPassword($param)
		{
			$this->password = $param;
		}

		//入力確認用パスワード
		public function setCheckPass($param)
		{
			$this->checkPass = $param;
		}

		//入力権限
		public function setAuthority($param)
		{
			$this->authority = $param;
		}

		//役割管理用ID
		public function setPositionid($param)
		{
			$this->positionid = $param;
		}

		//表示色管理用ID
		public function setColorid($param)
		{
			$this->colorid = $param;
		}

		//表示/非表示（1：表示 0：非表示）
		public function setDisplay($param)
		{
			$this->display = $param;
		}

		//処理種別
		public function setExecute($param)
		{
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
	 *	作成日)	2015/7/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//ユーザーID
		public function getUserid()
		{
			return $this->userid;
		}

		//パスワード
		public function getPassword()
		{
			return $this->password;
		}

		//確認用パスワード
		public function getCheckPass()
		{
			return $this->checkPass;
		}

		//権限
		public function getAuthority()
		{
			return $this->authority;
		}

		//役割格納用配列
		public function getPositionList()
		{
			return $this->positionList;
		}

		//表示色格納用配列
		public function getColorList()
		{
			return $this->colorList;
		}

		//役割管理用ID
		public function getPositionid()
		{
			return $this->positionid;
		}

		//表示色管理用ID
		public function getColorid()
		{
			return $this->colorid;
		}

		//ユーザー情報
		public function getUserinfo()
		{
			return $this->userinfo;
		}

		//ユーザー情報（各要素）
		public function getSelUserinfo($key)
		{
			return $this->userinfo["{$key}"];
		}

		//ユーザー情報格納用配列
		public function getAccountList()
		{
			return $this->accountList;
		}

		//表示/非表示
		public function getDisplay()
		{
			return $this->display;
		}

		//処理種別
		public function getExecute()
		{
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

			//ユーザー入力パスワード
			if(isset($_POST["password"]))
			{
				$this->password = $_POST["password"];
			}

			//ユーザー入力確認用パスワード
			if(isset($_POST["checkPass"]))
			{
				$this->checkPass = $_POST["checkPass"];
			}

			//ユーザー入力権限
			if(isset($_POST["authority"]))
			{
				$this->authority = $_POST["authority"];
			}

			//ユーザー入力役割管理用ID
			if(isset($_POST["positionid"]))
			{
				$this->positionid = $_POST["positionid"];
			}

			//ユーザー選択管理用ID
			if(isset($_POST["selid"]))
			{
				$this->accountid = $_POST["selid"];
			}

			//ユーザー入力役割管理用ID
			if(isset($_POST["colorid"]))
			{
				$this->colorid = $_POST["colorid"];
			}

			//表示/非表示
			if(isset($_POST["display"]))
			{
				$this->display = $_POST["display"];
			}

			//選択されたユーザーID
			if(isset($_POST["accountid"]))
			{
				$this->accountid = $_POST["accountid"];
			}

			//処理種別
			if(isset($_POST["execute"]))
			{
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
	 *	作成日)	2015/7/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function processing($db)
		{
			//役割の配列をDBから一括で受け取り格納する
			$this->selectAllPosition($db);

			//表示色の配列をDBから受け取り格納する
			$this->selectAllColor($db);

			//アカウント情報の配列をDBから受け取り格納する
			$this->selectAllAccount($db);

			//セレクトでユーザーが選択された場合、それに対応するデータを検索
				if(isset($_POST["accountid"]))
				{
					//$userInfoに連想配列で格納する
					$this->searchUser($db);
					//検索データの返却
					echo json_encode($this->userinfo);
					exit;
				}

			//処理種別によって処理を変更
			if($this->execute == "update")
			{
				//update()関数を呼び出し、更新処理を行う。
				$this->update($db);

				//アカウントIDに最初のユーザーのアカウント管理IDを格納
				$this->accountid = $this->accountList[0]["accountid"];

				//$userInfoにsearchUser関数を使用して連想配列で格納する
				$this->searchUser($db);

			}else{

				//Ajaxからの遷移ではない初期状態の場合、最初のユーザー情報を格納する

					//アカウントIDに最初のユーザーのアカウント管理IDを格納
					$this->accountid = $this->accountList[0]["accountid"];

					//$userInfoにsearchUser関数を使用して連想配列で格納する
					$this->searchUser($db);


			}
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

		private function selectAllPosition($db){

			//MySQL文の用意
			$sql = "SELECT * FROM positioninfo";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0):

				//繰り返し処理を使用して全取得データをbookListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$this->positionList[] = $row;

				endwhile;

			endif;

			//検索結果の開放
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
	 *	selectAllAccount()
	 *機能説明：
	 *	全役割情報をテーブルから全て取得し、プロパティ変数の$accountListに格納する。
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

		private function selectAllAccount($db){

			//MySQL文の用意
			$sql = "SELECT * FROM accountinfo";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0):

				//繰り返し処理を使用して全取得データをbookListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$this->accountList[] = $row;

				endwhile;

			endif;

			//検索結果の開放
			mysql_free_result($result);

		}

	/*====================================================================================
	 *概要：
	 *	searchUser()
	 *機能説明：
	 *	$useridで検索し検索結果を受け取ってuserinfoに格納する。
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

			//SQL文の生成
			$sql = "SELECT A.accountid,A.password,A.authority,A.display,P.`p-name`,C.`c-name`,C.code FROM accountinfo A INNER JOIN positioninfo P ON A.positionid = P.positionid INNER JOIN colorinfo C ON A.colorid = C.colorid WHERE A.accountid = {$this->accountid};";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果の確認
			if($rows > 0):

				//繰り返し処理を使用して全取得データをbookListに格納
				while($row = mysql_fetch_assoc($result)):
					//格納した1行データをbookListに配列で格納
					$this->userinfo = $row;

				endwhile;

			endif;

			//検索結果の開放
			mysql_free_result($result);
		}

	/*====================================================================================
	 *概要：
	 *	update
	 *機能説明：
	 *	プロパティ変数$userに該当するユーザーデータを更新する。
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

		private function update($db){

			//MySQL文の生成
			$sql = "UPDATE accountinfo SET password = '{$this->password}',authority = '{$this->authority}',positionid = {$this->positionid},colorid = {$this->colorid},display = '{$this->display}' WHERE accountid = {$this->accountid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}
}
?>
