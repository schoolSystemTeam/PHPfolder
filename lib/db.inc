<?php
include_once dirname(__FILE__).'/mysql.inc';

//DB定数
define('MYSQL_HOST',$db_host);
define('MYSQL_ID',$db_user);
define('MYSQL_PASS',$db_passwd);
define('MYSQL_DB',$db_name);


//データベースに接続する。
//戻り値 True：処理成功  False：処理失敗
function connectDatabase(&$db) {
	$db = @mysql_connect(MYSQL_HOST,MYSQL_ID,MYSQL_PASS) or die("MySQLの接続に失敗しました。".mysql_errno().": ".mysql_error());
	if (! $db ) {
		return false;
	}else{
		//DB選択

		@mysql_select_db(MYSQL_DB,$db) or die("データベースの接続に失敗しました。" . mysql_errno($db) . ": " . mysql_error($db));
		return true;
	}
}

//データベースを切断する。
//戻り値 True：処理成功  False：処理失敗
function closeDatabase($db) {
	if (!$db){
		return true;
	}else{
		$return = @mysql_close($db)or die("MySQL切断に失敗しました。" . mysql_errno($db).": " . mysql_error($db));
		if ($return == false) {
			return false;
		}
	}
	return true;
}