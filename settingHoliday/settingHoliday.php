<?php
header('Content-type: text/html; charset=UTF-8');

//セッション使用準備
session_start();

//インクルード
require_once('../lib/mysql.inc');
require_once('../lib/db.inc');
require_once('settingHoliday_model.inc');

//データベース接続
if(!connectDatabase($db)){
	$errmsg = "DB接続エラーが発生しました。";
	//エラー画面へ遷移
	callErrorPaga($errMsg);
	exit;
}

//セッションチェック
if(!isset($_SESSION['userinfo']))
{
	//セッション切れの場合、エラー画面に遷移
	callErrorPage("セッション切れのためメインメニュー画面を表示できませんでした。再度ログインしてください。","logout");
}

//クラスをインスタンス化
$model = new settingHoliday_model();

//画面項目取得
$model->getForm();

//処理
$model->prosessing($db);

//画面呼び出し
require_once('settingHoliday.phtml');

//データベース切断
closeDatabase($db)

?>