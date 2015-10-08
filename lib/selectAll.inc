<?php
/**
 * =====================================================================================
 プログラム名  ：	勤怠管理システム（Web版）
 プログラム説明：社員の勤怠情報を管理するシステムです。
 管理者はカレンダーを使用して視覚的に勤怠の登録、削除、変更
 を行えるほか各社員の勤怠情報の閲覧、休日、休憩時間の設定
 機能を使用することができます。

 勤怠情報とカレンダー部分はPDF,EXCEL出力することが可能です。
 作成者        ：	水島創
 作成日        ：	2015/9/11
 =====================================================================================
 */

// ====================================================================================
//selectAll.inc
//
//全てのDB情報を取得し、返却するクラス
//=====================================================================================

/*====================================================================================
 *概要：
 *	selectAllAccount()
 *機能説明：
 *	全アカウント情報をテーブルから全て取得し配列に格納、作成した配列を戻り値として返却する。
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

function selectAllAccount($db){

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
	$accountList[] = $row;

	endwhile;

	endif;

	//検索結果の開放
	mysql_free_result($result);

	//取得したアカウント情報を戻り値として返す
	return $accountList;
}


/*====================================================================================
 *概要：
 *	selectAllPosition()
 *機能説明：
 *	全役割情報をテーブルから全て取得し、取得した配列を戻り値として返却する。
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

function selectAllPosition($db){

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
	$positionList[] = $row;

	endwhile;

	endif;

	//検索結果の開放
	mysql_free_result($result);

	//取得した役割情報を戻り値として返却する
	return $positionList;

}

/*====================================================================================
 *概要：
 *	selectAllEvent
 *機能説明：
 *	全イベント情報を取得し戻り値として返す。
 *	データが無かった場合はfalseを返す。
 *引数：
 *	DB情報
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/9/11
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function selectAllEvent($db){
	//SQL文の準備
	$sql = "SELECT * FROM eventinfo";

	//SQL文の発行
	$result = mysql_query($sql,$db);

	//検索結果の件数を取得
	$rows = mysql_num_rows($result);

	//検索結果の確認
	if($rows > 0){

		//繰り返し処理を使用して全取得データをeventInfoに格納
		while($row = mysql_fetch_assoc($result)):

		//格納した1行データをeventInfoに配列で格納
		$eventInfo[] = $row;

		endwhile;

	}else{

		$eventInfo = false;

	}

	//検索結果の開放
	mysql_free_result($result);

	//検索結果を戻り値として返す
	return $eventInfo;

}

/*====================================================================================
 *概要：
 *	selectAllHoliday()
 *機能説明：
 *	全役割情報をテーブルから全て取得し、配列に格納。
 *	戻り値として返す。
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

function selectAllHoliday($db){

	//MySQL文の用意
	//設定した休日を検索するSQL文の設定
	$sql = "SELECT h.holidayid,h.day,h.holidayName,t.typeid,t.code
				FROM holidayinfo h
				INNER JOIN typeinfo t ON h.typeid=t.typeid
				ORDER BY day";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	while($assoc = mysql_fetch_assoc($result)){

		$holidayInfo[] = $assoc;

	}

	//結果保持用メモリを開放する
	mysql_free_result($result);

	//取得した休日情報を戻り値として返す
	return $holidayInfo;

}

/*====================================================================================
 *概要：
 *	selectAllColor()
 *機能説明：
 *	全色情報をテーブルから全て取得し、配列に格納。
 *	取得した配列を戻り値として返却する。
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

function selectAllColor($db){

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
	$colorList[] = $row;

	endwhile;

	endif;

	//検索結果の開放
	mysql_free_result($result);

	//戻り値として$colorListを返却する
	return $colorList;

}

/*====================================================================================
 *概要：
 *	selectAllStatus()
 *機能説明：
 *	全ステータス情報をテーブルから全て取得し、格納した配列を戻り値として返す
 *引数：
 *	データベース情報
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/06
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function selectAllStatus($db)
{
	//MySQL文の用意
	$sql = "SELECT * FROM statusinfo";

	//SQL文の発行
	$result = mysql_query($sql,$db);

	//検索結果の件数を取得
	$rows = mysql_num_rows($result);

	//検索結果の確認
	if($rows > 0){

		//繰り返し処理を使用して全取得データをbookListに格納
		while($row = mysql_fetch_assoc($result)):

		//格納した1行データをbookListに配列で格納
		$statusList[] = $row;

		endwhile;

	}else{

		$statusList = false;

	}

	//検索結果の開放
	mysql_free_result($result);

	//戻り値として配列が取得できた場合は配列をなければfalseを返す
	return $statusList;
}

/*====================================================================================
 *概要：
 *	selectAllType()
 *機能説明：
 *	DBに登録した休日種別情報を全て配列で取得して
 *	戻り値として返却する
 *引数：
 *	データベース情報
 *戻り値：
 *	種別情報
 *備考：
 *	作成日)	2015/9/4
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function selectAllType($db){

	//全てのtypeinfo情報を獲得するSQL文をセット
	$sql = "SELECT * FROM typeinfo";

	//SQLを発行する
	$result = mysql_query($sql,$db);

	//結果セットの行数を取得する
	while($assoc = mysql_fetch_assoc($result)){
		$typeList[] = $assoc;
	}

	//結果保持用メモリを開放する
	mysql_free_result($result);

	//格納した配列を返却する
	return $typeList;

}

?>
