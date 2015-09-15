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
 	作成日        ：	2015/9/1
	=====================================================================================
 */

class settingHoliday_model{

	private $holiday;				//年月日
	private $type;					//休日の種類
	private $holidayName;			//祝日名
	private $dayOfWeek;				//曜日
	private $startHoliday;			//休日開始日付
	private $endHoliday;			//休日終了日付
	private $holidayid;				//休日ID
	private $execute;				//処理種別
	private $textarea;				//CSV一括登録用テキストエリア
	private $holidaydata;			//休日データ
	private $typeData;				//休日種別データ
	private $errMsg;				//エラーメッセージ
	private $page;					//ページ
	private $oldDay;

	/*====================================================================================
	 *概要：
	 *	constract
	 *機能説明：
	 *	コンストラクタ
	 *引数：
	 *	なし
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function init(){
		$this->holiday = '';			//年月日
		$this->type = '';				//休日の種類
		$this->holidayName = '';		//祝日名
		$this->dayOfWeek = array();		//曜日
		$this->startHoliday = '';		//休日開始日付
		$this->endHoliday = '';			//休日終了日付
		$this->holidayid = '';			//休日ID
		$this->execute = '';			//処理種別
		$this->textarea = '';			//CSV
		$this->holidaydata = array();	//休日データ
		$this->typeData = "";			//休日種別データ
		$this->errMsg = array();				//エラーメッセージ
		$this->page = 0;				//ページ
		$this->oldDay = "";
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//年月日
	public function setHoliday($param){
		$this->holidya = $param;
	}

	//休日の種類
	public function setType($param){
		$this->type = $param;
	}

	//祝日名
	public function setHolidayName($param){
		$this->dayOfWeek = $param;
	}

	//曜日
	public function setDayOfWeek($param){
		$this->dayOfWeek = $param;
	}

	//休日開始日付
	public function setStartHoliday($param){
		$this->startHoliday = $param;
	}

	//休日終了日付
	public function setEndHoliday($param){
		$this->endHoliday = $param;
	}

	//休日ID
	public function setHolidayId($param){
		$this->holidayid = $param;
	}

	//処理種別
	public function setExecute($param){
		$this->execute = $param;
	}

	//CSV
	public function setTextarea($param){
		$this->textarea = $param;
	}

	//休日データ（表示用）
	public function setHolidayData($param){
		$this->holidaydata = $param;
	}

	//休日種別データ
	public function setTypeData($param)
	{
		$this->typeData = $param;
	}

	//エラーメッセージ
	public function setErrMsg($param){
		$this->errMsg = $param;
	}

	//ページ(表示用)
	public function setPage($param){
		$this->page = $param;
	}

	//
	public function setOldDay($param){
		$this->oldDay = $param;
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	*/

	//年月日
	public function getHoliday(){
		return $this->resttimedata;
	}

	//休日の種類
	public function getType(){
		return $this->type;
	}

	//祝日名
	public function getHolidayName(){
		return $this->holidayName;
	}

	//曜日
	public function getDayOfWeek(){
		return $this->dayOfWeek;
	}

	//休日開始日付
	public function getStartHoliday(){
		return $this->startHoliday;
	}

	//休日終了日付
	public function getEndHoliday(){
		return $this->endHoliday;
	}

	//休日ID
	public function getHolidayId(){
		return $this->holidayid;
	}

	//処理種別
	public function getExecute(){
		return $this->execute;
	}

	//CSV
	public function getTextarea(){
		return $this->textarea;
	}

	//休日データ（表示用）
	public function getHolidayData(){
		return $this->holidaydata;
	}

	//休日種別データ
	public function getTypeData()
	{
		return $this->typeData;
	}

	//エラーメッセージ
	public function getErrMsg(){
		return $this->errMsg;
	}

	//ページ(表示用)
	public function getPage(){
		return $this->page;
	}

	//
	public function getOldDay(){
		return $this->oldDay;
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
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	//フォーム入力からの数値受け取り関数
	public function getForm(){

		//年月日
		if(isset($_POST['holiday'])){
			$this->holiday = $_POST['holiday'];
		}

		//休日の種類
		if(isset($_POST['type'])){
			$this->type = $_POST['type'];
		}

		//祝日名
		if(isset($_POST['holidayName'])){
			$this->holidayName = $_POST['holidayName'];
		}

		//休日開始日付
		if(isset($_POST['startHoliday'])){
			$this->startHoliday = $_POST['startHoliday'];
		}

		//休日終了日付
		if(isset($_POST['endHoliday'])){
			$this->endHoliday = $_POST['endHoliday'];
		}

		//曜日
		if(isset($_POST['dayOfWeek'])){
			$this->dayOfWeek = $_POST['dayOfWeek'];
		}

		//休日ID
		if(isset($_REQUEST['holidayid'])){
			$this->holidayid = $_REQUEST['holidayid'];
		}

		//処理種別
		if(isset($_REQUEST['execute'])){
			$this->execute = $_REQUEST['execute'];
		}

		//CSV
		if(isset($_POST['textarea'])){
			$this->textarea = $_POST['textarea'];
		}

		//ページ(表示用)
		if(isset($_GET['page'])){
			$this->page = $_GET['page'];
		}

		//
		if(isset($_POST['oldDay'])){
			$this->oldDay = $_POST['oldDay'];
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
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function prosessing($db){

		//処理種別の判断(休日設定削除)
		if($this->execute == 'delete'){
			$this->delete($db);
		}

		//処理種別の判断(休日設定変更)
		if($this->execute == 'update'){
			$this->update($db,$this->holiday,$this->type);
			echo json_encode($this->errMsg);
			exit;
		}

		//処理種別の判断(個別登録)
		if($this->execute == "single"){
			$this->insert($db,$this->holiday,$this->type,$this->holidayName);
		}

		//処理種別の判断(曜日一括登録)
		if($this->execute == "StuSun"){
			$this->insertStuSun($db);
		}

		//処理種別の判断(CSV一括登録)
		if($this->execute == "bulk"){
			$this->insertTextArea($db);
		}

		$this->select($db);
	}

	/*====================================================================================
	 *概要：
	 *	select()
	 *機能説明：
	 *	DBに登録した休日情報を全て取得してholidaydata変数に配列として
	 *	格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function select($db){
		//設定した休日を検索するSQL文の設定
		$sql = "SELECT h.holidayid,h.day,t.typeid,t.name,h.holidayName
				FROM holidayinfo h INNER JOIN typeinfo t ON h.typeid=t.typeid ORDER BY day";

		//SQLを発行する
		$result = mysql_query($sql,$db);

		//結果セットの行数を取得する
		while($assoc = mysql_fetch_assoc($result)){
			$this->holidaydata[] = $assoc;
		}

		//結果保持用メモリを開放する
		mysql_free_result($result);

	}

	/*====================================================================================
	 *概要：
	 *	selectAllType()
	 *機能説明：
	 *	DBに登録した休日種別情報を全て取得してプロパティ変数の
	 *	typeDataに格納する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/4
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function selectAllType($db){
			//全てのtypeinfo情報を獲得するSQL文をセット
			$sql = "SELECT * FROM typeinfo";

			//SQLを発行する
			$result = mysql_query($sql,$db);

			//結果セットの行数を取得する
			while($assoc = mysql_fetch_assoc($result)){
				$this->typeData[] = $assoc;
			}

			//結果保持用メモリを開放する
			mysql_free_result($result);

		}

	/*====================================================================================
	 *概要：
	 *	getElementAssociativeArray()
	 *機能説明：
	 *	2重配列になっている連想配列から特定の要素のみを
	 *	抜き出し,配列に格納して返却する
	 *引数：
	 *	$array：配列,$key：連想配列キー
	 *戻り値：
	 *	$rtnArray:配列
	 *備考：
	 *	作成日)	2015/9/4
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

		public function getElementAssociativeArray($array,$key){

			//配列に格納されてる要素分をループ
			foreach($array as $val){

				//指定したインデックスの値を配列として返す。
				$rtnArray[] = $val["{$key}"];

			}

			//取得した配列を返却
			return $rtnArray;

		}

	/*====================================================================================
	 *概要：
	 *	insert()
	 *機能説明：
	 *	設定した休日をDBに登録する。
	 *引数：
	 *	データベース情報、休日情報、種類
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insert($db,$holiday,$type,$holidayName){

		//既に日付が登録されていないかをチェック
		if(@$this->searchHoliday($db,$holiday)){
			callErrorPage("既に登録されている日付の為,登録処理は行えませんでした。","settingHoliday");
			exit;
		}

		if(strlen($holidayName) >= 10){
			callErrorPage("休日名が長すぎます。10文字以内に設定してください。","settingHoliday");
			exit;
		}

		//設定した休日を登録するSQL文の設定
		$sql = "INSERT INTO holidayinfo VALUES
				(null,'{$holiday}',{$type},'{$holidayName}','1',NOW(),NOW())";

		//SQLを発行する
		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	insertTextArea()
	 *機能説明：
	 *	テキストエリア内の記述をCSV方式で休日を一括で登録する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertTextArea($db){

		//改行を区切りに指定して、配列に格納する
		$data = explode("\r\n",$this->textarea);

		//関数を使用し,種別の配列を取得
		$this->selectAllType($db);

		//種別名をいれる配列を作成
		$typeNameList = $this->getElementAssociativeArray($this->typeData,"name");

		//種別管理用IDをいれる配列を作成
		$typeidList = $this->getElementAssociativeArray($this->typeData,"typeid");

		//休日の種類を判別する
		for($i=0;$i<count($data); $i++){

			//行数を管理する変数
			$line = $i + 1;

			//改行ごとに取得した配列をカンマ区切りで変換
			$data2 = explode(',',$data[$i]);

			//配列数の正規チェック
			if(count($data2) != 5){

				$this->errMsg .= "コンマ数が不正のため、{$line}行目の処理はスキップします。<br><br>\n\n";
				continue;

			}

			//各要素の妥当性チェック
			for($j=0;$j<4;$j++){

				switch($j){
					case 0:
						//年のエラーチェック
						if(empty($data2[$j]) && strlen($data2[$j]) == 0)
						{	//空白チェック
							$this->errMsg .= "年数のデータが空白のため、{$line}行目の処理はスキップします。<br><br>\n\n";
							continue 2;
						}

						//不正ではなければ、年,月,日の行頭から0を取り除く

						$year	= excludeZero($data2[$j]);	//年

						if(!is_numeric($year))
						{//数値入力チェック
							$this->errMsg .= "年数のデータに数値以外の文字が含まれていたため,{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						break;

					case 1:
						//月のエラーチェック
						if(empty($data2[$j]) && strlen($data2[$j]) == 0)
						{	//空白チェック
							$this->errMsg .= "月数のデータが空白のため、{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						//不正ではなければ、年,月,日の行頭から0を取り除く

						$month  = excludeZero($data2[$j]);	//月

						if($month < 1 && $month > 12 && !is_int($month))
						{	//正しい月情報かをチェック
							$this->errMsg .= "月数が存在しない月なので,{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						break;

					case 2:
						//日数のエラーチェック
						if(empty($data2[$j]) && strlen($data2[$j]) == 0)
						{	//空白チェック
							$this->errMsg .= "日数のデータが空白のため、{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						//不正ではなければ、年,月,日の行頭から0を取り除く

						$day	= excludeZero($data2[$j]);	//日

						//日数の妥当性のチェック
						if($day < 1 && $day > 31 && !is_int($day))
						{	//正しい日情報かをチェック
							$this->errMsg .= "日数の値が不正な為,{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						//日付情報の妥当性のチェック
						if(!checkdate( $month,$day,$month ))
						{	//年数が正しい年数かをチェック
							$this->errMsg .= "指定された日付は存在していないため,{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						break;

					case 3:

						//種別のエラーチェック
						if(empty($data2[$j]) && strlen($data2[$j]) == 0)
						{	//空白チェック
							$this->errMsg .= "種別のデータが空白のため、{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						if(!@in_array($data2[$j],$typeNameList))
						{	//種別の名前チェック
							$this->errMsg .= "種別のデータが存在しない休日種別のため、{$line}行目の処理はスキップしました。<br><br>\n\n";
							continue 2;
						}

						break;

					default:

						break;
				}

			}

			//種別のデータから検索し,それぞれに対応するインデックス番号を格納する
			$key = array_search($data2[3],$typeNameList);

			//対応するidを情報として格納
			$data2[3] = $typeidList[$key];

			//DB登録用に日付を修正
			$date = "{$year}-{$month}-{$day}";

			//既に登録してあるデータではないかをチェック
			if(@$this->searchHoliday($db,"{$date}")){

				$this->errMsg .= "既に登録してある日付のため,{$line}行目の処理はスキップしました。<br><br>\n\n";
				continue;

			}

			//insert()関数を呼び出し
			$this->insert($db,$date,$data2[3],$data2[4]);
		}

			//エラーが発生した場合,エラーページに遷移
			if($this->errMsg != "")
			{
				callErrorPage($this->errMsg,"settingHoliday");
				exit;

			}

	}

	/*====================================================================================
	 *概要：
	 *	insertStuSun()
	 *機能説明：
	 *	ある期間内の曜日を休日として登録する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function insertStuSun($db){
		$i=0;

		//不正な期日が選択されていないかをエラーチェック
		if(strtotime("{$this->startHoliday}") >= strtotime("{$this->endHoliday}")){
			callErrorPage("不正な期間が選択されたため、一括曜日登録は行えませんでした。","settingHoliday");
			exit;
		}

		//終了日付をオブジェクト化
		$dateEndtime = new DateTime("{$this->endHoliday}");

		//期間内の日付をループする
		while(true){

			//開始日付からインクリメントする
			$holiday = date('Y-m-d',strtotime("{$this->startHoliday} + {$i}day"));

			//日付をオブジェクト化
			$dateStartTime = new DateTime("$holiday");

			//ある日付の曜日を数値として返す
			$w = (string)$dateStartTime->format('w');

			//終了日付より後になった場合ループを抜ける
			if($dateStartTime > $dateEndtime){
				break;
			}


			//指定した曜日に該当する日付のみ登録する
			if(($this->dayOfWeek[0] == $w || $this->dayOfWeek[1] === $w) && !@$this->searchHoliday($db,$holiday)){
				$this->insert($db,$holiday,$this->type,null);
			}

			$i++;
		}
	}

	/*====================================================================================
	 *概要：
	 *	delete()
	 *機能説明：
	 *	休日設定を一つ削除する。
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

	public function delete($db){
		$sql = "DELETE FROM holidayinfo WHERE holidayid={$this->holidayid}";

		$result = mysql_query($sql,$db);
	}

	/*====================================================================================
	 *概要：
	 *	update()
	 *機能説明：
	 *	休日設定を一つ変更する。
	 *引数：
	 *	データベース情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/1
	 *	作成者)	鈴木一紘
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */

	public function update($db,$holiday,$type){

		//既に日付が登録されていないかをチェック
		if($this->oldDay != $holiday){
			if(@$this->searchHoliday($db,$holiday,$this->accountid)){
				//callErrorPage("既に登録されている日付の為,変更処理は行えませんでした。","settingHoliday");
				$this->errMsg[] =  "既にこの日付には休日が登録されています！";
				return false;

			}
		}

		$sql = "UPDATE holidayinfo SET day = '{$holiday}', typeid = {$type},
				holidayName = '{$this->holidayName}',updateday = NOW()
				WHERE holidayid = {$this->holidayid}";

		$result = mysql_query($sql,$db);

	}

/*====================================================================================
	 *概要：
	 *	searchHoliday()
	 *機能説明：
	 *	日付情報からholidayinfoを検索しデータがあった場合はtrueを
	 *	なかった場合にはfalseを返却する。
	 *引数：
	 *	データベース情報,$date:日付情報
	 *戻り値：
	 *	なし
	 *備考：
	 *	作成日)	2015/9/4
	 *	作成者)	水島創太
	 *	説明）
	 *	更新日)
	 *	更新者)
	 *	変更)
	  ====================================================================================
	 */
	private function searchHoliday($db,$date,$id = null){
		//SQL文をセット
		if ($id != null) {
			$sql = "SELECT * FROM holidayinfo WHERE day = '{$date}' AND id != {$id}";
		} else {
			$sql = "SELECT * FROM holidayinfo WHERE day = '{$date}'";
		}

		//検索結果を格納
		$result = @mysql_query($sql,$db);

		//検索結果の件数を取得
		$rows = @mysql_num_rows($result);

		//検索結果がある場合、trueを無かった場合はfalseを返す
		if($rows>0){

			return true;

		}else{

			return false;

		}

	}
}
?>