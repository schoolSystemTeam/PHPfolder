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

class eventList_model{

	//-----------------------------------------
	//各プロパティ変数宣言
	//-----------------------------------------

	private $eventList;		//セミナー情報配列
	private $eventid;		//イベント管理ID
	private $eventName;		//イベント名
	private $shortName;		//イベント略名
	private $color;			//表示色
	private $execute;		//処理種別

	/*====================================================================================
	 *概要：
	 *	eventList_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/28
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
	 *	作成日)	2015/9/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function init(){

		$this->eventList = array();		//セミナー情報配列
		$this->eventid = "";			//イベント管理ID
		$this->eventName = "";			//イベント名
		$this->shortName = "";			//イベント略名
		$this->color = "";				//表示色
		$this->execute = "";			//処理種別

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

	//セミナー情報配列
	public function setEventList($param)
	{
		$this->eventList = $param;
	}

	//イベント管理ID
	public function setEventId($param)
	{
		$this->eventid = $param;
	}

	//イベント名
	public function setEventName($param)
	{
		$this->eventName = $param;
	}

	//イベント略名
	public function setShortName($param)
	{
		$this->shortName = $param;
	}

	//表示色
	public function setColor($param)
	{
		$this->color = $param;
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

	//セミナー情報配列
	public function getEventList()
	{
		return $this->eventList;
	}

//イベント管理ID
	public function getEventId()
	{
		return $this->eventid;
	}

	//イベント名
	public function getEventName()
	{
		return $this->eventName;
	}

	//イベント略名
	public function getShortName()
	{
		return $this->shortName;
	}

	//表示色
	public function getColor()
	{
		return $this->color;
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

		//イベント管理ID
		if(isset($_POST["eventid"]))
		{
			$this->eventid = $_POST["eventid"];
		}

		//イベント名
		if(isset($_POST["eventName"]))
		{
			$this->eventName = $_POST["eventName"];
		}
		//イベント略名
		if(isset($_POST["shortName"]))
		{
			$this->shortName = $_POST["shortName"];
		}

		//表示色
		if(isset($_POST["color"]))
		{
			$this->color = $_POST["color"];
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
		//関数を使用してイベント情報をプロパティ変数に格納
		$this->eventList = selectAllEvent($db);

		//セミナー情報変更の場合
		if($this->execute == "update"){

			$this->updateEvent($db);

		}

		//セミナー情報削除の場合
		if($this->execute == "delete")
		{
			$this->deleteEvent($db);
			//自身に送り返し画面をリロードする
			header("location: ./eventList.php");
			exit;
		}
	}

	/*====================================================================================
	 *概要：
	 *	updateEvent()
	 *機能説明：
	 *	取得したイベント更新情報を元にDBを更新する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */

	private function updateEvent($db){

		//SQL文の生成
		$sql="UPDATE eventinfo
			SET eventName = '{$this->eventName}',
				shortName = '{$this->shortName}',
				color = '{$this->color}',
				updateday = NOW()
				WHERE eventid = {$this->eventid}";

		//SQL文の発行
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	deleteEvent()
	 *機能説明：
	 *	取得したイベントIDを元に該当するセミナー情報を削除する
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/28
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	 ====================================================================================
	 */
		private function deleteEvent($db){

			//SQL文の生成
			$sql = "DELETE FROM eventinfo
					WHERE eventid = {$this->eventid}";

			//SQL文の発行
			$result = mysql_query($sql,$db);
		}
}


?>
