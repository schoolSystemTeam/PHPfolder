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
 	作成日        ：	2015/8/26
	=====================================================================================
 */
		//セッションの使用準備
		session_start();

		//関連ファイルの読み込み
		require_once "../lib/db.inc";				//データベース情報用ファイル
		require_once "../lib/mysql.inc";			//データベース接続用ファイル
		require_once '../lib/util.inc';				//一般用クラスファイル
		require_once "overallWorkTime_model.inc";	//クラスファイル

		//データベース接続
		if(!connectDatabase($db)){
		$errMsg = "DB接続エラーが発生しました。";
		//エラー画面へ遷移する
		callErrorPage($errMsg,"menu");
		exit;
	}

		//クラスをインスタンス化
		$model = new overallWorkTime_model();

		//画面項目の取得
		$model->getForm();

		//メイン処理呼び出し
		$model->processing($db);

		//画面呼出し
		require_once ("personalWorkTime.phtml");

		//データベース切断
		closeDatabase($db);
?>