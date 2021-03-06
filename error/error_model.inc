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
 	作成日        ：	2015/9/01
	=====================================================================================
 */

class error_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $error;		//エラーメッセージ
	private $path;		//遷移先制御コマンド
	private $lp;		//リンクパス
	private $title;		//リンク名
	private $accountid;	//アカウント

	/*====================================================================================
	 *概要：
	 *	error_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/7/23
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
	 *	作成日)	2015/7/22
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

 	private function init(){

		$this->error = "";						//エラーメッセージ
		$this->path = "";						//遷移先制御用コマンド
		$this->lp = "";							//リンク先パス
		$this->title = "";						//リンク名
		$this->accountid = "";
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
	 *	作成日)	2015/7/22
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
		//エラーメッセージ
		public function getError()
		{
			return $this->error;
		}

		//遷移先制御用コマンド
		public function getPath()
		{
			return $this->path;
		}

		//リンク用パス
		public function getLp()
		{
			return $this->lp;
		}

		//リンク名
		public function getTitle()
		{
			return $this->title;
		}

		//アカウント
		public function getAccountid()
		{
			return $this->accountid;
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
	 *	作成日)	2015/7/23
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//フォーム入力からの数値受け取り関数
		public function getForm(){

			//ISBN番号(GET送信)
			if(isset($_GET["errMsg"]))
			{
				$this->error = $_GET["errMsg"];
			}

			//入力書籍タイトル
			if(isset($_GET["path"]))
			{
				$this->path = $_GET["path"];
			}

			//アカウントI(セッションから取得)
			if(isset($_SESSION["errorAccount"]))
			{
				$this->accountid = $_SESSION["errorAccount"];
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
	 *	作成日)	2015/7/22
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function processing()
		{
			//パスの種類に合わせて値を格納する
			if($this->path == "logout")
			{
				//フィールド変数に対応する値を格納

				$this->title = "[ログイン画面へ戻る]";
				$this->lp = "../login/login.php?execute=logout";

			}
			if($this->path == "menu"){

				$this->title = "[メニューへ戻る]";
				$this->lp = "../mainMenu/mainMenu.php";

			}
			 if($this->path == "insertUser"){

				$this->title = "[ユーザー登録画面へ戻る]";
				$this->lp = "../insertUser/insertUser.php";

			}

			if($this->path == "updateUser"){

				$this->title = "[ユーザー情報変更画面に戻る]";
				$this->lp = "../updateUser/updateUser.php";

			}

			if($this->path == "settingHoliday"){

				$this->title = "[休日設定画面に戻る]";
				$this->lp = "../settingHoliday/settingHoliday.php";

			}

			if($this->path == "settingRestTime"){

				$this->title = "[休憩時間設定画面に戻る]";
				$this->lp = "../settingRestTime/settingRestTime.php";

			}

			if($this->path == "personalWorkTime"){

				$this->title = "[勤務時間表(個人)画面に戻る]";
				$this->lp = "../personalWorkTime/personalWorkTime.php?accountid=".$this->accountid;

			}

			if($this->path == "overallWorkTime"){

				$this->title = "[勤務時間表(全体)画面に戻る]";
				$this->lp = "../overallWorkTime/overallWorkTime.php";

			}

		}
}
?>
