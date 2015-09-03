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
 	作成日        ：	2015/8/27
	=====================================================================================
 */

	class settingRestTime_model{

		//-----------------------------------------
		//各プロパティ変数宣言
		//-----------------------------------------

		private $resttimedata;		//表示用休憩時間格納用配列
		private $dayofweek;			//曜日格納用配列
		private $startHour;			//休憩開始時数格納用配列（一般）
		private $startMinuts;		//休憩開始分数格納用配列（一般）
		private $endHour;			//休憩終了時数格納用配列（一般）
		private $endMinuts;			//休憩終了分数格納用配列（一般）
		private $seminarStartHour;	//休憩開始時数格納用配列（セミナー）
		private $seminarStartMinuts;//休憩開始分数格納用配列（セミナー）
		private $seminarEndHour;	//休憩終了時数格納用配列（セミナー）
		private $seminarEndMinuts;	//休憩終了分数格納用配列（セミナー）
		private $errMsg;			//エラーメッセージ
		private $execute;			///処理種別

	/*====================================================================================
	 *概要：
	 *	settingRestTime_form
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//コンストラクタ定義
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
	 *	作成日)	2015/8/27
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//初期化関数定義
		public function init(){
			$this->resttimedata = array();			//表示用休憩時間格納用配列
			$this->dayofweek = array();				//曜日格納用配列
			$this->startHour = array();				//休憩開始時数格納用配列（一般）
			$this->startMinuts = array();			//休憩開始分数格納用配列（一般）
			$this->endHour = array();				//休憩終了時数格納用配列（一般）
			$this->endMinuts = array();				//休憩終了分数格納用配列（一般）
			$this->seminarStartHour = array();		//休憩開始時数格納用配列（セミナー）
			$this->seminarStartMinuts = array();	//休憩開始分数格納用配列（セミナー）
			$this->seminarEndHour = array();		//休憩終了時数格納用配列（セミナー）
			$this->seminarEndMinuts = array();		//休憩終了分数格納用配列（セミナー）
			$this->errMsg = "";						//エラーメッセージ
			$this->execute = '';					//処理種別
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//表示用休憩時間格納用配列
		public function setRestTimeData($param){
			$this->resttimedata = $param;
		}

		//曜日格納用配列
		public function setDayOfWeek($param){
			$this->dayofweek = $param;
		}

		//休憩開始時数格納用配列（一般)
		public function setStartHour($param){
			$this->startHour = $param;
		}

		//休憩開始分数格納用配列（一般）
		public function setStartMinuts($param){
			$this->startMinuts = $param;
		}

		//休憩終了時数格納用配列（一般）
		public function setEndHour($param){
			$this->endHour = $param;
		}

		//休憩終了分数格納用配列（一般）
		public function setEndMinuts($param){
			$this->endMinuts = $param;
		}

		//休憩開始時数格納用配列（セミナー）
		public function setSeminarStartHour($param){
			$this->seminarStartHour = $param;
		}

		//休憩開始分数格納用配列（セミナー）
		public function setSeminarStartMinuts($param){
			$this->seminarStartMinuts = $param;
		}

		//休憩終了時数格納用配列（セミナー）
		public function setSeminarEndHour($param){
			$this->seminarEndHour = $param;
		}

		//休憩終了分数格納用配列（セミナー）
		public function setSeminarEndMinuts($param){
			$this->seminarEndMinuts = $param;
		}

		//エラーメッセージ
		public function setErrMsg($param)
		{
			$this->errMsg = $param;
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//表示用休憩時間格納用配列
		public function getRestTimeData(){
			return $this->resttimedata;
		}
		//曜日格納用配列
		public function getDayOfWeek(){
			return $this->dayofweek;
		}


		//休憩開始時数格納用配列（一般）
		public function getStartHour(){
			return $this->startHour;
		}

		//休憩開始分数格納用配列（一般）
		public function getStartMinuts(){
			return $this->startMinuts;
		}

		//休憩終了時数格納用配列（一般）
		public function getEndHour(){
			return $this->endHour;
		}

		//休憩終了分数格納用配列（一般）
		public function getEndMinuts(){
			return $this->endMinuts;
		}

		//休憩開始時数格納用配列（セミナー)
		public function getSeminarStartHour(){
			return $this->seminarStartHour;
		}

		//休憩開始分数格納用配列（セミナー）
		public function getSeminarStartMinuts(){
			return $this->seminarStartMinuts;
		}

		//休憩終了時数格納用配列（セミナー）
		public function getSeminarEndHour(){
			return $this->seminarEndHour;
		}

		//休憩終了分数格納用配列（セミナー）
		public function getSeminarEndMinuts(){
			return $this->seminarEndMinuts;
		}

		//エラーメッセージ
		public function getErrMsg()
		{
			return $this->errMsg;
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		//入力フォームからの取得
		public function getForm(){

			//曜日格納用配列
			if(isset($_POST['dayofweek'])){
				$this->dayofweek = $_POST['dayofweek'];
			}

			//休憩開始時数（一般）
			if(isset($_POST['startHour'])){
				$this->startHour = $_POST['startHour'];
			}

			//休憩開始分数（一般）
			if(isset($_POST['startMinuts'])){
				$this->startMinuts = $_POST['startMinuts'];
			}

			//休憩終了時数（一般）
			if(isset($_POST['endHour'])){
				$this->endHour = $_POST['endHour'];
			}

			//休憩終了分数（一般）
			if(isset($_POST['endMinuts'])){
				$this->endMinuts = $_POST['endMinuts'];
			}

			//休憩開始時数（セミナー）
			if(isset($_POST['seminarStartHour'])){
				$this->seminarStartHour = $_POST['seminarStartHour'];
			}

			//休憩開始分数（セミナー）
			if(isset($_POST['seminarStartMinuts'])){
				$this->seminarStartMinuts = $_POST['seminarStartMinuts'];
			}

			//休憩終了時数（セミナー）
			if(isset($_POST['seminarEndHour'])){
				$this->seminarEndHour = $_POST['seminarEndHour'];
			}

			//休憩終了分数（セミナー）
			if(isset($_POST['seminarEndMinuts'])){
				$this->seminarEndMinuts = $_POST['seminarEndMinuts'];
			}

			//処理種別
			if(isset($_POST['execute'])){
				$this->execute = $_POST['execute'];
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function prosessing($db){

			//設定ボタン押下したか判断
			if($this->execute == "休憩時間を設定"){

				//曜日分ループをまわす
				for($i=0; $i<count($this->dayofweek); $i++){

					/*=====================================
					 * 関数を使用して、既に登録されているデータかを
					 * 判定しそれぞれの処理にあった関数を呼び出す
					  =====================================*/

					//休憩の開始時間と終了時間をそれぞれ変数に格納

					//一般休憩開始時間
					$startTime = changeOfSecond($this->startHour[$i],$this->startMinuts[$i]);
					//一般休憩終了時間
					$endTime = changeOfSecond($this->endHour[$i],$this->endMinuts[$i]);
					//セミナー休憩開始時間
					$seminarStartTime = changeOfSecond($this->seminarStartHour[$i],$this->seminarStartMinuts[$i]);
					//セミナー休憩終了時間
					$seminarEndTime = changeOfSecond($this->seminarEndHour[$i],$this->seminarEndMinuts[$i]);


					//時刻が不正ではないかチェック
					if(!checkOfTimeError($startTime,$endTime))
					{
						//不正な時刻だった場合、エラーメッセージを格納

						$msgWD = checkDayOfWeek($this->dayofweek[$i]);
						$this->resttimedata = $this->selectByType($db,"1",$this->dayofweek[$i]);

						$this->errMsg .= "不正な時間設定のため,{$msgWD}の一般休憩時間設定はできませんでした。<br><br>\n\n";

					}else{	//エラーが無ければ処理を行う

						//一般の処理
						if($this->selectByType($db,"1",$this->dayofweek[$i])){

							$this->updateByNormal($db,$i);
							$this->resttimedata = $this->selectByType($db,"1",$this->dayofweek[$i]);

						}else{

							$this->insertByNormal($db,$i);
							$this->resttimedata = $this->selectByType($db,"1",$this->dayofweek[$i]);
						}

					}

					//セミナーの時刻が不正ではないかチェック
					if(!checkOfTimeError($startTime,$endTime))
					{//不正な時刻だった場合

						//曜日を関数を使用して取得
						$msgWD = checkDayOfWeek($this->dayofweek[$i]);

						//エラーメッセージを格納
						$this->errMsg .= "不正な時間設定のため,{$msgWD}のセミナー休憩時間設定はできませんでした。<br><br>\n\n";
						$this->resttimedata = $this->selectByType($db,"2",$this->dayofweek[$i]);

					}else{	//エラーが無ければ処理を行う

						//セミナーの処理
						if($this->selectByType($db,"2",$this->dayofweek[$i])){

							$this->updateBySeminar($db,$i);
							$this->resttimedata = $this->selectByType($db,"2",$this->dayofweek[$i]);

						}else{

							$this->insertBySeminar($db,$i);
							$this->resttimedata = $this->selectByType($db,"2",$this->dayofweek[$i]);
						}

					}

				}

				//エラーがあった場合,エラーページに遷移する
				if($this->errMsg != "")
				{
					callErrorPage($this->errMsg,"menu");
					exit;
				}

//				if($this->select($db)){
//					$this->update($db);
//					$this->resttimedata = $this->select($db);
//				}else{
//					$this->insert($db);
//					$this->resttimedata = $this->select($db);
//				}
			}else{
					$this->resttimedata = $this->select($db);
			}
		}

	/*====================================================================================
	 *概要：
	 *	select()
	 *機能説明：
	 *
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function select($db){
			//resttimeinfoのデータ全てを検索するSQL文の設定
			$sql = "SELECT * FROM  `resttimeinfo` ORDER BY  `resttimeinfo`.`dayofweek` ASC ";

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

	/*====================================================================================
	 *概要：
	 *	selectByTypeAndDay()
	 *機能説明：
	 *
	 *	セミナーと一般の種別と曜日を引数に検索を行い、検索結果を返す。
	 *
	 *引数：
	 *	データベース情報,$type
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/03
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function selectByType($db,$type,$dayOfWeek){
			//入力したユーザーIDとパスワードに該当するレコードがあるか検索するSQL文の設定
			$sql = "SELECT * FROM resttimeinfo WHERE dayofweek = '{$dayOfWeek}' AND type = '{$type}'";

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

	/*====================================================================================
	 *概要：
	 *	insert()
	 *機能説明：
	 *
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
//
//		public function insert($db,$i){
//
//
//
//				$sql = "INSERT INTO resttimeinfo VALUE
//						(null,'{$this->dayofweek[$i]}','{$this->startHour[$i]}:{$this->startMinuts[$i]}',
//						'{$this->endHour[$i]}:{$this->endMinuts[$i]}','1','1',NOW(),NOW())";
//
//				$result = mysql_query($sql,$db);
//
//				$sql = "INSERT INTO resttimeinfo VALUE
//						(null,'{$this->dayofweek[$i]}','{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
//						'{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}','1','2',NOW(),NOW())";
//
//				$result = mysql_query($sql,$db);
//
//		}

	/*====================================================================================
	 *概要：
	 *	insertOfNormal()
	 *機能説明：
	 *	インデックス番号とタイプを引数に一般の休憩時間を
	 *	登録する。
	 *引数：
	 *	データベース情報,$i(インデックス番号)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/03
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function insertByNormal($db,$i){


				$sql = "INSERT INTO resttimeinfo VALUE
						(null,'{$this->dayofweek[$i]}','{$this->startHour[$i]}:{$this->startMinuts[$i]}',
						'{$this->endHour[$i]}:{$this->endMinuts[$i]}','1','1',NOW(),NOW())";

				$result = mysql_query($sql,$db);

		}

	/*====================================================================================
	 *概要：
	 *	insertBySeminar()
	 *機能説明：
	 *	インデックス番号とタイプを引数にセミナーの休憩時間を
	 *	登録する。
	 *引数：
	 *	データベース情報,$i(インデックス番号)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function insertBySeminar($db,$i){

				$sql = "INSERT INTO resttimeinfo VALUE
						(null,'{$this->dayofweek[$i]}','{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
						'{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}','1','2',NOW(),NOW())";

				$result = mysql_query($sql,$db);

		}

	/*====================================================================================
	 *概要：
	 *	update()
	 *機能説明：
	 *
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/8/28
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
//
//		public function update($db){
//			for($i=0; $i<count($this->dayofweek); $i++){
//				$sql = "UPDATE resttimeinfo SET
//						reststarttime = '{$this->startHour[$i]}:{$this->startMinuts[$i]}',
//						restendtime = '{$this->endHour[$i]}:{$this->endMinuts[$i]}',
//						updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='1'";
//
//				$result = mysql_query($sql,$db);
//
//				$sql = "UPDATE resttimeinfo SET
//						reststarttime = '{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
//						restendtime = '{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}',
//						updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='2'";
//
//				$result = mysql_query($sql,$db);
//			}
//		}

	/*====================================================================================
	 *概要：
	 *	updateByNormal()
	 *機能説明：
	 *	インデックス番号とタイプを引数に一般の休憩時間を
	 *	更新する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/03
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function updateByNormal($db,$i){

				$sql = "UPDATE resttimeinfo SET
						reststarttime = '{$this->startHour[$i]}:{$this->startMinuts[$i]}',
						restendtime = '{$this->endHour[$i]}:{$this->endMinuts[$i]}',
						updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='1'";

				$result = mysql_query($sql,$db);

		}

	/*====================================================================================
	 *概要：
	 *	updateBySeminar()
	 *機能説明：
	 *	インデックス番号とタイプを引数にセミナーの休憩時間を
	 *	更新する。
	 *引数：
	 *	データベース情報,$i(インデックス番号)
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/03
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function updateBySeminar($db,$i){
			$sql = "UPDATE resttimeinfo SET
						reststarttime = '{$this->seminarStartHour[$i]}:{$this->seminarStartMinuts[$i]}',
						restendtime = '{$this->seminarEndHour[$i]}:{$this->seminarEndMinuts[$i]}',
						updateday = NOW() WHERE dayofweek = '{$this->dayofweek[$i]}' AND type='2'";

				$result = mysql_query($sql,$db);
		}

	}
?>