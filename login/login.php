<?php
header('Content-type: text/html; charset=UTF-8');

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

//インクルード
require_once('../lib/mysql.inc');
require_once('../lib/db.inc');
require_once('login_model.inc');

//データベース接続
if(!connectDatabase($db)){
	$errmsg = "DB接続エラーが発生しました。";
	//エラー画面へ遷移
	callErrorPage($errMsg);
	exit;
}

//クラスをインスタンス化
$model = new login_model();

//画面項目取得
$model->getForm();

//処理
$model->prosessing($db);

//画面呼び出し
require_once('login.phtml');

//データベース切断
closeDatabase($db)

?>
