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
 	作成日        ：	2015/8/26
	=====================================================================================
 */

class insertUser_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $userid;		//ユーザーID
	private $password;		//パスワード
	private $checkPass;		//確認用パスワード
	private $authority;		//権限(1:一般 2:管理者)
	private $name;			//名前
	private $worktype;		//勤務形態（1：常勤 2：非常勤）
	private $colorList;		//表示色用配列
	private $colorid;		//表示色管理用ID
	private $colorInfo;		//個人用色情報
	private $execute;		//処理種別

	/*====================================================================================
	 *概要：
	 *	insertUser_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
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
	 *	作成日)	2015/8/26
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
	$this->authority = "";		//権限(1:一般 2:管理者)
	$this->name = "";			//名前
	$this->worktype = "";		//勤務形態（1：常勤 2：非常勤）
	$this->positionList = "";	//役割用配列
	$this->colorList = "";		//表示色格納用配列
	$this->positionid = "";		//役割管理用ID
	$this->colorid = "";		//表示色管理用ID
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
	 *	作成日)	2015/8/26
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

		//名前
		public function setName($param)
		{
			$this->name = $param;
		}

		//勤務形態（1：常勤 2：非常勤）
		public function setWorktype($param)
		{
			$this->worktype = $param;
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
	 *	作成日)	2015/8/27
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

		//名前
		public function getName()
		{
			return $this->name;
		}

		//勤務形態（1：常勤 2：非常勤）
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

		//個人用色情報
		public function getColorInfo($key=null)
		{
			if($key == null){
				return $this->colorInfo;
			}else{
				return $this->colorInfo[$key];
			}
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

			//ユーザー入力名
			if(isset($_POST["name"]))
			{
				$this->name = $_POST["name"];
			}

			//ユーザー入力勤務形態（1：常勤 2：非常勤）
			if(isset($_POST["worktype"]))
			{
				$this->worktype = $_POST["worktype"];
			}

			//ユーザー入力役割管理用ID
			if(isset($_POST["positionid"]))
			{
				$this->positionid = $_POST["positionid"];
			}

			//ユーザー入力役割管理用ID
			if(isset($_POST["colorid"]))
			{
				$this->colorid = $_POST["colorid"];
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
	 *	作成日)	2015/8/27
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

			//画面遷移のチェック
			if($this->execute == "insert"){	//検索ボタン押下時

			// 各種エラーチェック //

				//エラーメッセージの初期化
				$errMsg = "";

				//入力ISBNが登録済みかチェック
				if($this->searchUser($db))
				{
					$errMsg = "入力ユーザーIDは既に登録済みの為、ユーザー登録は行えませんでした。<br>\n";
					callErrorPage($errMsg,"menu");
					exit;
				}

				//エラーが無ければ個人用色情報を登録
				$this->colorInfo = $this->selectColorInfo();

				//エラーが無ければ登録処理を行う
				$this->insert($db);

			}else{	//初期画面&全件表示ボタン押下時

			}
		}

	/*====================================================================================
	 *概要：
	 *	selectColorInfo()
	 *機能説明：
	 *	全色情報の配列からcoloridを引数に検索を行い、
	 *	色と一致する配列を戻り値として返す
	 *引数：
	 *	なし
	 *戻り値：
	 *	colorInfo
	 *備考：
	 *	作成日)	2015/09/15
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function selectColorInfo(){

			//全色情報をローカル変数に格納
			$colorList = $this->colorList;

			//繰り返し処理を利用して色情報を検索
			foreach($colorList as $value){

				if($this->colorid == $value["colorid"]){

					return $value;

				}

			}

		}

	/*====================================================================================
	 *概要：
	 *	searchUser
	 *機能説明：
	 *	入力されたユーザー名を元に該当するデータを取得。
	 *	存在すればtrueをしなければfalseを返す
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

			//MySQL文の用意
			$sql = "SELECT * FROM accountinfo WHERE userid = '{$this->userid}'";

			//SQL文の発行
			$result = mysql_query($sql,$db);

			//検索結果の件数を取得
			$rows = mysql_num_rows($result);

			//検索結果があるかどうかをチェック
			if($rows > 0){

				//ユーザー情報が存在する場合、trueを格納
				$tf = true;

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
	 *	insert
	 *機能説明：
	 *	各入力フォームに入力されたデータを取得しDBにアカウント情報を登録する。
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

		private function insert($db){

			//パスワードをハッシュ化
			$hash = hash(sha256,$this->password);

			//MySQL文の生成
			$sql  = "INSERT INTO accountinfo VALUES";
			$sql .= "(NULL,'{$this->userid}','{$hash}',";
			$sql .= "'{$this->authority}','{$this->name}','{$this->worktype}',NULL,";
			$sql .= "NULL,{$this->colorid},'1',NOW(),NOW())";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}
}
?>
