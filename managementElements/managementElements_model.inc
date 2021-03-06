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

class managementElements_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $colorid;			//カラーID
	private $c_code;			//カラーコード
	private $c_name;			//カラーネーム
	private $positionid;		//ポジションID
	private $p_name;			//役割名
	private $p_code;			//役割のカラーコード
	private $statusid;			//ステータスID
	private $s_name;			//ステータスの名前
	private $colorList;			//表示色用配列
	private $positionList;
	private $statusList;		//選択したユーザーID
	private $execute;			//処理種別

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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

 	private function init(){

 	$this->colorid = "";		//カラーID
	$this->c_code = "";		//カラーコード
	$this->c_name = "";		//カラーネーム
	$this->positionid = "";		//カラーID
	$this->p_code = "";		//カラーコード
	$this->p_name = "";		//カラーネーム
	$this->statusid = "";		//カラーID
	$this->s_name = "";		//カラーネーム
	$this->colorList = array();		//表示色格納用配列
	$this->positionList = array();	//ユーザー情報格納用配列
	$this->statusList = array();		//選択したユーザーID
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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//カラーID
		public function setColorid($param){
			$this->colorid = $param;
		}

		//カラーネーム
		public function setC_name($param){
			$this->c_name = $param;
		}

		//カラーコード
		public function setC_code($param){
			$this->c_code = $param;
		}

		//ポジションID
		public function setPositionid($param){
			$this->positionid = $param;
		}

		//役割名
		public function setP_name($param){
			$this->p_name = $param;
		}

		//役割別色コード
		public function setP_code($param){
			$this->p_code = $param;
		}

		//ステータスID
		public function setStatusid($param){
			$this->statusid = $param;
		}

		//ステータスの名前
		public function setS_name($param){
			$this->s_name = $param;
		}

		//表示色用配列
		public function setColorList($param){
			$this->colorList = $param;
		}

		//役割用配列
		public function setPositionList($param){
			$this->positionList = $param;
		}

		//ステータス用配列
		public function setStatusList($param){
			$this->statusList = $param;
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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//ユーザーID
		public function getColorid(){
			return $this->colorid;
		}

		//パスワード
		public function getC_name(){
			return $this->c_name;
		}

		//確認用パスワード
		public function getC_code(){
			return $this->c_code;
		}

		//ユーザーID
		public function getPositionid(){
			return $this->positionid;
		}

		//パスワード
		public function getP_name(){
			return $this->p_name;
		}

		//確認用パスワード
		public function getP_code(){
			return $this->p_code;
		}

		//ユーザーID
		public function getStatusid(){
			return $this->statusid;
		}

		//パスワード
		public function getS_name(){
			return $this->s_name;
		}

		//表示色格納用配列
		public function getColorList(){
			return $this->colorList;
		}

		//役割格納用配列
		public function getPositionList(){
			return $this->positionList;
		}

		//役割管理用ID
		public function getStatusList(){
			return $this->statusList;
		}

		//ユーザー情報
		public function getUserinfo(){
			return $this->userinfo;
		}

		//表示/非表示
		public function getDisplay(){
			return $this->display;
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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//フォーム入力からの数値受け取り関数
		public function getForm(){

			//カラーID
			if(isset($_POST["colorid"])){
				$this->colorid = $_POST["colorid"];
			}

			//カラーコード
			if(isset($_POST["c_code"])){
				$this->c_code = $_POST["c_code"];
			}

			//カラーネーム
			if(isset($_POST["c_name"])){
				$this->c_name = $_POST["c_name"];
			}

			//ポジションID
			if(isset($_POST["positionid"])){
				$this->positionid = $_POST["positionid"];
			}

			//役割の色
			if(isset($_POST["p_code"])){
				$this->p_code = $_POST["p_code"];
			}

			//役割の名前
			if(isset($_POST["p_name"])){
				$this->p_name = $_POST["p_name"];
			}

			//ステータスID
			if(isset($_POST["statusid"])){
				$this->statusid = $_POST["statusid"];
			}

			//ステータスの名前
			if(isset($_POST["s_name"])){
				$this->s_name = $_POST["s_name"];
			}

			//処理種別
			if(isset($_POST["execute"])){
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
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function processing($db){

			//表示色の配列をDBから受け取り格納する
			$this->colorList = selectAllColor($db);

			//役割の配列をDBから受け取り格納する
			$this->positionList = selectAllPosition($db);

			//ステータス情報の配列をDBから受け取り格納する
			$this->statusList = selectAllStatus($db);

			//処理種別によって処理を変更
			if($this->execute != ""){
				if($this->execute == "c_update"){

					//updateColorInfo()関数を呼び出し、更新処理を行う。
					$this->updateColorInfo($db);

				}

				if($this->execute == "p_update"){

					//updatePositionInfo()関数を呼び出し、更新処理を行う。
					$this->updatePositionInfo($db);

				}

				if($this->execute == "p_delete"){

					//deletePosition()関数を呼び出し、削除処理を行う。
					$this->deletePositionInfo($db);

				}

				if($this->execute == "s_update"){

					//updateStatusInfo()関数を呼び出し、更新処理を行う。
					$this->updateStatusInfo($db);

				}

				if($this->execute == "c_delete"){

					//delete()関数を呼び出し、削除処理を行う
					$this->deleteColorInfo($db);

				}

				if($this->execute == "s_delete"){

					//delete()関数を呼び出し、削除処理を行う
					$this->deleteStatusInfo($db);

				}

				//処理種別によって処理を変更
				if($this->execute == "c_insert"){

					//update()関数を呼び出し、更新処理を行う。
					$this->insertColorInfo($db);

				}

				if($this->execute == "p_insert"){

					//update()関数を呼び出し、更新処理を行う。
					$this->insertPositionInfo($db);

				}

				if($this->execute == "s_insert"){

					//update()関数を呼び出し、更新処理を行う。
					$this->insertStatusInfo($db);

				}

					//自身に送り返し画面をリロードする
					header("location: ./managementElements.php");
					exit;
			}
		}

	/*====================================================================================
	 *概要：
	 *	updateColorInfo()
	 *機能説明：
	 *	$coloridで検索し該当する情報を変更する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function updateColorInfo($db){

			//SQL文の生成
			$sql = "UPDATE colorinfo
					SET `c-name`='{$this->c_name}',code='{$this->c_code}',
						 updateday=NOW()
					WHERE colorid={$this->colorid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);

		}

	/*====================================================================================
	 *概要：
	 *	updatePositionInfo()
	 *機能説明：
	 *	$positionidで検索し該当する情報を変更する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function updatePositionInfo($db){

			//MySQL文の生成
			$sql = "UPDATE positioninfo
					SET `p-name` = '{$this->p_name}',color = '{$this->p_code}',
						 updateday=NOW()
					WHERE positionid = {$this->positionid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	updateStatusInfo()
	 *機能説明：
	 *	$coloridで検索し該当する情報を変更する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function updateStatusInfo($db){

			//MySQL文の生成
			$sql = "UPDATE statusinfo
					SET name = '{$this->s_name}', updateday=NOW()
					WHERE statusid = {$this->statusid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	deletePositioninfo()
	 *機能説明：
	 *	$positionidに該当する情報を削除する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/10/07
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function deletePositionInfo($db){

			//MySQL文の生成
			$sql = "DELETE FROM positioninfo WHERE positionid = {$this->positionid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	deleteColorInfo()
	 *機能説明：
	 *	$coloridに該当する情報を削除する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function deleteColorInfo($db){

			//MySQL文の生成
			$sql = "DELETE FROM colorinfo WHERE colorid = {$this->colorid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	deleteStatusInfo()
	 *機能説明：
	 *	$statusidに該当する情報を削除する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function deleteStatusInfo($db){

			//MySQL文の生成
			$sql = "DELETE FROM statusinfo WHERE statusid = {$this->statusid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	insertColorInfo()
	 *機能説明：
	 *	入力した色情報をcorolinfoテーブルに登録する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function insertColorInfo($db){

			//MySQL文の生成
			$sql = "INSERT INTO colorinfo
					VALUES(null,'{$this->c_name}','{$this->c_code}',1,NOW(),NOW())";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	insertPositionInfo
	 *機能説明：
	 *	入力した役割情報をpositioninfoテーブルに登録する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function insertPositionInfo($db){

			//MySQL文の生成
			$sql = "INSERT INTO positioninfo
					VALUES(null,'{$this->p_code}','{$this->p_name}',1,NOW(),NOW())";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}

	/*====================================================================================
	 *概要：
	 *	insertStatusInfo
	 *機能説明：
	 *	入力したステータス情報をstatusinfoテーブルに登録する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/30
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		private function insertStatusInfo($db){

			//MySQL文の生成
			$sql = "INSERT INTO statusinfo
					VALUES(null,'{$this->s_name}',1,NOW(),NOW())";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}
}
?>
