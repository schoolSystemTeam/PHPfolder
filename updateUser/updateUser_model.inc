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
	private $authority;		//権限(1:一般 2:管理者)
	private $worktype;		//勤務形態（1：常勤 2：非常勤）
	private $colorList;		//表示色用配列
	private $accountid;		//選択したユーザーID
	private $userInfo;		//ユーザー情報
	private $accountList;	//ユーザー情報格納用配列
	private $jsAccountList;	//ユーザー情報JSON変換データ
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
	$this->worktype = "";		//勤務形態（1：常勤 2：非常勤）
	$this->positionList = "";	//役割用配列
	$this->colorList = "";		//表示色格納用配列
	$this->accountid = "";		//選択したユーザーID
	$this->userInfo = "";		//ユーザー情報
	$this->accountList = "";	//ユーザー情報格納用配列
	$this->jsAccountList = "";	//ユーザー情報JSON変換データ
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

		//勤務形態
		public function setWorktype($param)
		{
			$this->worktype;
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

		//勤務形態
		public function getWorktype()
		{
			return $this->worktype;
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

		//ユーザー情報変換データ
		public function getJsAccountList()
		{
			return $this->jsAccountList;
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

			//ユーザー入力ユーザーID
			if(isset($_POST["userid"]))
			{
				$this->userid = $_POST["userid"];
			}

			//ユーザー入力パスワード
			if(isset($_POST["password"]))
			{
				$this->password = $_POST["password"];
			}

			//ユーザー入力権限
			if(isset($_POST["authority"]))
			{
				$this->authority = $_POST["authority"];
			}

			//ユーザー入力勤務形態
			if(isset($_POST["worktype"]))
			{
				$this->worktype = $_POST["worktype"];
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
			//表示色の配列をDBから受け取り格納する
			$this->colorList = selectAllColor($db);

			//アカウント情報の配列をDBから受け取り格納する
			$this->selectAllAccount($db);

			//アカウント情報を変換してjsAccountListに格納
			$this->jsAccountList = json_encode($this->accountList);

			//処理種別によって処理を変更
			if($this->execute == "update")
			{

				//エラーメッセージの初期化
				$errMsg = "";

				//入力ISBNが登録済みかチェック

				//ユーザー情報を検索し変数に、格納
				$accountinfo = $this->searchUserid($db);
				if($accountinfo != false && $accountinfo["accountid"] != $this->accountid)
				{
					$errMsg = "入力ユーザーIDは既に登録済みの為、ユーザー情報の変更は行えませんでした。";
				}

				if($errMsg == ""){
					//update()関数を呼び出し、更新処理を行う。
					$this->update($db);

					//$userInfoにsearchUser関数を使用して連想配列で格納する
					$this->searchUser($db);

				}


				//エラーメッセージを返り値として戻す。
				echo $errMsg;
				exit;

			}else if($this->execute == "delete"){

				//$userInfoにsearchUser関数を使用して連想配列で格納する
				$this->searchUser($db);

				//delete()関数を呼び出し、削除処理を行う
				$this->delete($db);

				//自身に送り返し画面をリロードする
				header("location: ./updateUser.php");
				exit;


			}else{

			}
		}

	/*====================================================================================
	 *概要：
	 *	selectAllAccount()
	 *機能説明：
	 *	全役割情報をcolorinfoテーブルと内部結合して全て取得し、
	 *	プロパティ変数の$accountListに格納する。
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
			$sql = "SELECT A.accountid, A.userid, A.name,
						   A.password AS password,
						   A.authority, A.worktype, A.display, A.colorid,
						   C.`c-name`, C.code
					FROM accountinfo A
					INNER JOIN colorinfo C ON A.colorid = C.colorid";

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
	 *	searchUserid
	 *機能説明：
	 *	入力されたユーザー名を元に該当するデータを取得。
	 *	存在すればそのアカウント情報を,しなければfalseを返す
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)	2015/10/05
	 *	更新者)	水島創太
	 *	変更)	変数名をsearchUseridに変更。
	  ====================================================================================
	 */

		private function searchUserid($db){

			//MySQL文の用意
			$sql = "SELECT * FROM accountinfo WHERE userid = '{$this->userid}'";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果があるかどうかをチェック
			if($rows > 0){

				//ユーザー情報が存在する場合、ユーザー情報を格納
				//繰り返し処理を使用して全取得データを$tfに格納
				while($row = mysql_fetch_assoc($result)):
				//格納した1行データをeventPlanInfoに配列で格納
				$tf = $row;

				endwhile;

			}else{

				$tf = false;

			}

			//検索結果の開放
			mysql_free_result($result);

			//結果を返す
			return $tf;
		}


	/*====================================================================================
	 *概要：
	 *	searchUser()
	 *機能説明：
	 *	$accountidで検索し検索結果を受け取ってuserinfoに格納する。
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
			$sql = "SELECT A.accountid,A.userid,A.name,A.password,A.authority,A.display,A.colorid,
						   C.`c-name`,C.code
					FROM accountinfo A
					INNER JOIN colorinfo C ON A.colorid = C.colorid
					WHERE A.accountid = {$this->accountid};";

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
			$sql = "UPDATE accountinfo
					SET userid = '{$this->userid}',
						authority = '{$this->authority}',
						worktype = '{$this->worktype}',
						colorid = {$this->colorid},
						display = '{$this->display}',
						updateday = NOW()";

			if($this->password != ""){
				$hash = hash(sha256,$this->password);
				$sql .= ",password = '{$hash}'";
			}

			$sql .= "WHERE accountid = {$this->accountid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

/*====================================================================================
	 *概要：
	 *	delete
	 *機能説明：
	 *	プロパティ変数accountidに該当するユーザー情報を削除する
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

		private function delete($db){

			//MySQL文の生成
			$sql = "DELETE FROM accountinfo
					WHERE accountid = {$this->accountid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}


	/*====================================================================================
	 *概要：
	 *	changeUser()
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
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

/*		private function encryption($text){

			//暗号化キーの設定
			$key = md5('ITschool');

			//暗号化モジュールの使用開始
			$td  = mcrypt_module_open(MCRYPT_BLOWFISH, '', 'ecb', '');
			$key = substr($key, 0, mcrypt_enc_get_key_size($td));
			$iv  = mcrypt_create_iv(mcrypt_enc_get_iv_size($td), MCRYPT_RAND);

			//暗号化モジュールの初期化
			if (mcrypt_generic_init($td, $key, $iv) < 0) {
 				exit('error.');
			}

			//データを暗号化
			$crypt_text = mcrypt_generic($td, $text);

			//暗号化モジュール使用終了
			mcrypt_generic_deinit($td);
			mcrypt_module_close($td);

			//暗号化したパスワードを返す
			return $crypt_text;
		}

	/*====================================================================================
	 *概要：
	 *	changeUser()
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
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		/*public function decryption($text){

			//復号化キーの設定
			$key = md5('ITschool');

			//暗号化モジュールの使用開始
			$td  = mcrypt_module_open(MCRYPT_BLOWFISH, '', 'ecb', '');
			$key = substr($key, 0, mcrypt_enc_get_key_size($td));
			$iv  = mcrypt_create_iv(mcrypt_enc_get_iv_size($td), MCRYPT_RAND);

			//暗号化モジュールの初期化
			if (mcrypt_generic_init($td, $key, $iv) < 0) {
 				exit('error.');
			}

			//データを復号化
			$crypt_text = mdecrypt_generic($td, $text);

			//暗号化モジュール使用終了
			mcrypt_generic_deinit($td);
			mcrypt_module_close($td);

			//暗号化したパスワードを返す
			return $crypt_text;
		}*/
}
?>
