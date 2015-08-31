<?php
header('Content-type: text/html; charset=UTF-8');

//インクルード
require_once('../lib/mysql.inc');
require_once('../lib/db.inc');
require_once('login_model.inc');

//データベース接続
if(!connectDatabase($db)){
	$errmsg = "DB接続エラーが発生しました。";
	//エラー画面へ遷移
	callErrorPaga($errMsg);
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