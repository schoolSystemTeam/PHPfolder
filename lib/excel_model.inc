<?php
//excelライブラリの読み込み
require_once '../Classes/PHPExcel.php';
require_once '../Classes/PHPExcel/IOFactory.php';

/*====================================================================================
 *概要：
 *	calendarOutPrintForExcel
 *機能説明：
 *	メインメニューのカレンダーを引数を元に、Excel出力するクラス。
 *引数：
 *	日付格納配列,イベント格納配列,勤務者情報格納配列,休日格納配列
 *	年,月,表示処理
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/09
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */


/*====================================================================================
 *概要：
 *	calendarOutPrintForExcel
 *機能説明：
 *	メインメニューのカレンダーを受け取った引数を元にExcel出力を行う。
 *引数：
 *	なし
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/13
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function calendarOutPrintForExcel($calendar,$eventList,$workerList,
$holidayList,$year,$month,$dispMonth,$work,$seminar,$absence)
{

	// PHPExcelオブジェクトの作成
	$book = new PHPExcel();

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//シート名指定
	$sheet->setTitle("勤務予定カレンダー");

	//入力するデフォルトフォントを設定
	$sheet->getDefaultStyle()->getFont()->setName( 'ＭＳ ゴシック' )->setSize( 8 );

	// 行高さ設定（setRowHeightにパラメタ指定しないことで自動調整）
	//	$sheet->getRowDimension()->setRowHeight();

	//各シートの幅を設定する
	$sheet->getColumnDimension( 'A' )->setWidth(9);
	$sheet->getColumnDimension( 'B' )->setWidth(9);
	$sheet->getColumnDimension( 'C' )->setWidth(9);

	$sheet->getColumnDimension( 'D' )->setWidth(9);
	$sheet->getColumnDimension( 'E' )->setWidth(9);
	$sheet->getColumnDimension( 'F' )->setWidth(9);

	$sheet->getColumnDimension( 'G' )->setWidth(9);
	$sheet->getColumnDimension( 'H' )->setWidth(9);
	$sheet->getColumnDimension( 'I' )->setWidth(9);

	$sheet->getColumnDimension( 'J' )->setWidth(9);
	$sheet->getColumnDimension( 'K' )->setWidth(9);
	$sheet->getColumnDimension( 'L' )->setWidth(9);

	$sheet->getColumnDimension( 'M' )->setWidth(9);
	$sheet->getColumnDimension( 'N' )->setWidth(9);
	$sheet->getColumnDimension( 'O' )->setWidth(9);

	$sheet->getColumnDimension( 'P' )->setWidth(8);
	$sheet->getColumnDimension( 'Q' )->setWidth(8);
	$sheet->getColumnDimension( 'R' )->setWidth(8);

	$sheet->getColumnDimension( 'S' )->setWidth(8);
	$sheet->getColumnDimension( 'T' )->setWidth(8);
	$sheet->getColumnDimension( 'U' )->setWidth(8);

	//タイトルシートを改行
	$sheet->getStyle("A3:U112")->
	getAlignment()->setWrapText(true);


	//表示期間を選択
	switch ($dispMonth)
	{
		case 0:
			$roop = 3;
			break;
		case 1:
			$roop = 2;
			break;
		case 2:
			$roop = 1;
			break;
		default:
			$roop = 3;
			break;
	}

	//ファイル名入力
	$fileName = "勤務予定カレンダー".$year[0]."年".$month[0]."月(".$roop."ヶ月分).xls";

	//セルの番号を定義
	$cellNum = 1;

	//表示されているヶ月分のカレンダーをループ
	for($i=0;$i<$roop;$i++)
	{

		//一週間を管理する変数$cnt
		$cnt = 0;

		//表示期間をセルに入力
		$sheet->setCellValue("A{$cellNum}", $year[$i]."年".$month[$i]."月");

		//1週間分のセルを結合
		$sheet->mergeCells("A{$cellNum}:U{$cellNum}");

		//タイトルを色づけする
		$sheet->
		getStyle( "A{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FF99FFFF');

		//セルを一つずらす
		$cellNum++;

		//月~日までの週をセルに入力
		$sheet->setCellValue("A{$cellNum}", "月");
		$sheet->setCellValue("D{$cellNum}", "火");
		$sheet->setCellValue("G{$cellNum}", "水");
		$sheet->setCellValue("J{$cellNum}", "木");
		$sheet->setCellValue("M{$cellNum}", "金");
		$sheet->setCellValue("P{$cellNum}", "土");
		$sheet->setCellValue("S{$cellNum}", "日");

		//一日ごとに3つずつセルを連結
		$sheet->mergeCells("A{$cellNum}:C{$cellNum}");
		$sheet->mergeCells("D{$cellNum}:F{$cellNum}");
		$sheet->mergeCells("G{$cellNum}:I{$cellNum}");
		$sheet->mergeCells("J{$cellNum}:L{$cellNum}");
		$sheet->mergeCells("M{$cellNum}:O{$cellNum}");
		$sheet->mergeCells("P{$cellNum}:R{$cellNum}");
		$sheet->mergeCells("S{$cellNum}:U{$cellNum}");

		//曜日を色づけする
		$sheet->
		getStyle( "A{$cellNum}:S{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FFC0C0C0');

		//各セルを格子で囲む
		$sheet->getStyle( "A".($cellNum-1).":U{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セル内の文字を中央でそろえる
		$sheet->getStyle("A".($cellNum-1).":S{$cellNum}" )->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//セルをひとつ進める
		$cellNum++;


		//カレンダーの日付分を繰り返して出力
		foreach($calendar[$i] as $num => $value):

		//各種に対応したセル番号を生成

		$cellNum2 = $cellNum + 1;	//セミナー情報
		$cellNum3 = $cellNum + 2;	//セミナー情報
		$cellNum4 = $cellNum + 3;	//欠席者情報
		$cellNum5 = $cellNum + 4;	//セミナー担当者情報
		$cellNum6 = $cellNum + 6;	//枠線用

		//関数を使用してそれぞれのセルに対応するアルファベットの配列を取得
		$cell = setCellAlphabet($cnt);

		//その日の日付をセルに入力
		$sheet->setCellValue($cell[1].$cellNum, $value['day']);

		//セル内の文字を中央でそろえる
		$sheet->getStyle($cell[1].$cellNum)->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);

		//日付を太文字にする
		$sheet->getStyle($cell[1].$cellNum)->getFont()->setBold(true);

		//その日が祝日かどうかをセルに入力
		$sheet->setCellValue($cell[2].$cellNum,
		$holidayList[$i][$num]['holidayName']);

		$sheet->getStyle( $cell[2].$cellNum )->getFont()->setSize( 6 );

		//その日が当日かどうかをチェックし、当日ならば当日用の色で日付を塗る
		if(date("Y-n-j") == "{$year[$i]}-{$month[$i]}-{$value['day']}"){

			$sheet->
			getStyle($cell[0].$cellNum.':'.$cell[2].$cellNum6)->
			getFill()->
			setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
			getStartColor()->
			setARGB( 'FFFFFF00');

		}

		//勤務者名
		$workerName = '';

		//勤務時間
		$worktime = '';

		//勤務者情報
		$workerInfo2 = '';

		//欠席者情報
		$absenceName = '';
		$absenceStatus = '';

		//==================================セミナー情報をセルに入力=============================//

		if($value["day"] != "")
		{
			if(!($seminar == "true")):

			//繰り返し処理を使用してセルに情報を入力
			foreach($eventList["{$year[$i]}-{$month[$i]}-{$value['day']}"]as $idx => $eventInfo)
			{

				//そのイベントをセルに入力
				$sheet->setCellValue($cell[$idx].$cellNum2, $eventInfo["shortName"]);

				if($eventInfo["shortName"] != ""){

					//イベントのセルを格子で囲む
					$sheet->getStyle($cell[$idx].$cellNum2)->
					getBorders()->
					getAllBorders()->
					setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

					//セルをイベントの色で色づけする
					$sheet->
					getStyle($cell[$idx].$cellNum2)->
					getFill()->
					setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
					getStartColor()->
					setARGB( 'FF'.$eventInfo["color"]);

				}

			}

			endif;
		}

		//==================================================================================//
		//==================================勤務者情報をセルに入力=============================//

		//繰り返し処理を利用して勤務者情報をセルに出力する
		if($value["day"] != "")
		{

			foreach($workerList[$i][$num] as $index => $info)
			{
				if($work == "true"):

				if($info["statusid"] != 3)
				{

					$workerName .= $info["name"].''.PHP_EOL.'';

					//該当セルに勤務時間を入力する
					if($info["workstarttime"] != "")
					{

						$worktime     .=     createTimeFormat($info["workstarttime"])
						.'～'.
						createTimeFormat($info["workendtime"]).''.PHP_EOL.'';

					}
				}



				//該当セルに役割と勤務ステータスを入力する

				//役割とステータスを条件ごとに記入するかどうかを変化させる
				if($info["statusid"] != 6 && $info["statusid"] != 3){

					$workerInfo = getFirstStr($info["p-name"]).' '.$info["statusName"].''.PHP_EOL.'';

				}
				if($info["statusid"] != 3){

					$workerInfo = getFirstStr($info["p-name"]).''.PHP_EOL.'';

				}

				//日付情報が入力されているかどうかをチェックし、日付情報がある場合のみ勤務者情報を登録
				if($value["day"] != ""){
					$workerInfo2 .= $workerInfo;
				}

				endif;

				//=================================欠席者情報をセルに入力==============================//
				//欠席者情報を条件が一致した場合、出力を行う

				if($absence == "true"):

				if($info["statusid"] == 3 && $info["worktype"] == 1)
				{
					if($index == 0)
					{
						$absenceName .= $info["name"];
						$absenceStatus .= $info["statusName"];

					}else{

						$absenceName .= ''.PHP_EOL.''.$info["name"];
						$absenceStatus .= ''.PHP_EOL.''.$info["statusName"];

					}

					//欠席者情報のセルに色をつける
					$sheet->
					getStyle( $cell[0].$cellNum4.':'.$cell[2].$cellNum4 )->
					getFill()->
					setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
					getStartColor()->
					setARGB( 'FFC0C0C0');

				}else{

				}

				endif;

				//==================================================================================//

			}

		}

		//勤務者情報を書き出し
		$sheet->setCellValue($cell[0].$cellNum3, $workerName);

		//勤怠時間情報を書き出し
		$sheet->setCellValue($cell[1].$cellNum3,$worktime);

		//勤務者の役割とステータスを書き出し
		$sheet->setCellValue($cell[2].$cellNum3, $workerInfo2);

		//該当セルに欠席者情報を書き出し
		$sheet->setCellValue($cell[0].$cellNum4, $absenceName);	  //名前
		$sheet->setCellValue($cell[1].$cellNum4, $absenceStatus);//ステータス


		//==================================================================================//
		//==============================セミナー担当者情報をセルに入力===========================//

		if($value["day"] != "")
		{
			//セミナーのチェックボックスがチェックされていた場合、セミナー担当者情報をExcelに出力
			if($seminar == "true"):

				//繰り返し処理を使用してセルに情報を入力
				foreach($eventList["{$year[$i]}-{$month[$i]}-{$value['day']}"]as $idx => $eventInfo)
				{

					//そのイベントを該当セルに入力
					$sheet->setCellValue($cell[0].$cellNum5, $eventInfo["shortName"]);

					//イベント担当者を該当セルに入力
					$sheet->setCellValue($cell[1].$cellNum5, $eventInfo["name"]);

					if($eventInfo["shortName"] != "")
					{

						//イベントのセルをイベントの色で色づけする
						$sheet->
						getStyle($cell[0].$cellNum5)->
						getFill()->
						setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
						getStartColor()->
						setARGB( 'FF'.$eventInfo["color"]);

						//イベントのセルを格子で囲む
						$sheet->getStyle($cell[0].$cellNum5)->
						getBorders()->
						getAllBorders()->
						setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

						//イベントのセル内の文字を中央でそろえる
						$sheet->getStyle($cell[0].$cellNum5)->
						getAlignment()->
						setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);

						//イベント担当者のセル内の文字を色づけする
						$sheet->
						getStyle($cell[1].$cellNum5)->
						getFont()->
						getColor()->
						setARGB('FF'.$eventInfo["code"]);

					}

					//一度情報を書き込むごとにセルを一つ進める
					$cellNum5++;

				}

			endif;
		}
		//==================================================================================//

		//日付のセルを枠線で囲う
		$sheet->getStyle( $cell[0].$cellNum.':'.$cell[2].$cellNum6 )->
		getBorders()->
		getOutline()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//一日進むごとに管理変数をインクリメント
		$cnt++;

		//1週間が経過するごとに変数をリセットする
		if($cnt == 7){
			$cnt = 0;		//カウント変数を月曜日にリセット
			$cellNum+= 7;	//一週間ごとにセルの番号を7つ進める
		}

		//ループの最後の場合、セルの行番号をカレンダー一列分進める
		if(count($calendar[$i]) - 1 == $num )
		{
			$cellNum += 7;
		}

		endforeach;


	}

	outputExcel($fileName,$book);

}

/*====================================================================================
 *概要：
 *	excelOverAllWorkTime
 *機能説明：
 *	エクセルのファイルをセルに出力して表示するテスト用クラス。
 *引数：
 *	なし
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/09
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function excelOverAllWorkTime($date,$workArray,$sumArray,$aveArray,$monthWorkArray=null,
$monthSumArray = null,$monthAveArray=null,$monthDate=null)
{

	// PHPExcelオブジェクトの作成
	$book = new PHPExcel();

	//	$objReader = PHPExcel_IOFactory::createReader('Excel5');
	//	$book = $objReader->load("../excel/overallWorktimeTemp.xls");

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//シート名指定
	$sheet->setTitle("勤務時間表");

	//表示期間をセルに入力
	$sheet->setCellValue("A1", "表示期間：");
	$sheet->setCellValue("B1", "{$date}");

	//各種タイトルをexcel出力する
	$sheet->setCellValue("A3", '名前'.PHP_EOL.'');
	$sheet->setCellValue("B3", '出勤日'.PHP_EOL.'合計');//出勤日合計
	$sheet->setCellValue("C3", '週平均'.PHP_EOL.'出勤日数');//週平均出勤日数
	$sheet->setCellValue("D3", '欠席日数'.PHP_EOL.'');//欠席日数
	$sheet->setCellValue("E3", '営業日数'.PHP_EOL.'');//営業日数
	$sheet->setCellValue("F3", '休憩時間'.PHP_EOL.'');//休憩時間
	$sheet->setCellValue("G3", '労働時間'.PHP_EOL.'合計');//労働時間合計
	$sheet->setCellValue("H3", '月平均'.PHP_EOL.'労働時間');//月平均労働時間
	$sheet->setCellValue("I3", '週平均'.PHP_EOL.'労働時間');//週平均労働時間

	//タイトルシートを改行
	$sheet->getStyle("A3:I3")->
	getAlignment()->setWrapText(true);

	// 行高さ設定（setRowHeightにパラメタ指定しないことで自動調整）
	$sheet->getRowDimension(3)->setRowHeight("28.5");

	//セルをタイトル用のカラー、グレーで色をつける
	$sheet->
	getStyle( "A3:I3" )->
	getFill()->
	setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
	getStartColor()->
	setARGB( 'FFc0c0c0');

	//各セルを格子で囲む
	$sheet->getStyle( "A3:I3" )->
	getBorders()->
	getAllBorders()->
	setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

	//セル内の文字を中央でそろえる
	$sheet->getStyle("A3:I3")->
	getAlignment()->
	setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

	//セルの値を管理する変数を宣言
	$cellNum = 4;

	//ファイル名を入力
	$fileName = "勤務時間表(全体)".date('_Ymd').".xls";

	//入力するデフォルトフォントを設定
	$sheet->getDefaultStyle()->getFont()->setName( 'ＭＳ ゴシック' )->setSize( 11 );

	//受け取った配列からシートに勤務情報を入力
	foreach($workArray as $num => $value){

		//セルに値を入れる

		$sheet->setCellValue("A".$cellNum, $value['name']);				//氏名
		$sheet->setCellValue("B".$cellNum, encodeUTF($value['workday']));			//出勤日数
		$sheet->setCellValue("C".$cellNum, encodeUTF($value['aveWorkday']));		//出勤日合計
		$sheet->setCellValue("D".$cellNum, encodeUTF($value['absence']));			//欠席日数
		$sheet->setCellValue("E".$cellNum, encodeUTF($value['business']));  		//営業日数
		$sheet->setCellValue("F".$cellNum, encodeUTF($value['resttime']));			//休憩時間
		$sheet->setCellValue("G".$cellNum, encodeUTF($value['worktime']));			//労働時間合計
		$sheet->setCellValue("H".$cellNum, encodeUTF($value['aveWorktimeMonth']));	//月平均労働時間
		$sheet->setCellValue("I".$cellNum, encodeUTF($value['aveWorktimeWeek']));	//週平均労働時間

		//各セルを格子で囲む
		$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セル内の文字を中央でそろえる
		$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//偶数番号のセルを別の色で塗り分ける

		if($cellNum % 2 == 0){

			$sheet->
			getStyle( "A{$cellNum}:I{$cellNum}" )->
			getFill()->
			setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
			getStartColor()->
			setARGB( 'FF99FFFF');

		}

		//セルの値の初期値をインクリメントする
		$cellNum++;

	}

	//受け取った配列から合計値を入力
	$sheet->setCellValue("A".$cellNum, "合計");	//タイトル（合計）
	$sheet->setCellValue("B".$cellNum, encodeUTF($sumArray['workday']));			//氏名
	$sheet->setCellValue("C".$cellNum, encodeUTF($sumArray['aveWorkday']));			//出勤日合計
	$sheet->setCellValue("D".$cellNum, encodeUTF($sumArray['absence']));			//欠席日数
	$sheet->setCellValue("E".$cellNum, encodeUTF($sumArray['business']));			//営業日数
	$sheet->setCellValue("F".$cellNum, encodeUTF($sumArray['resttime']));			//休憩時間
	$sheet->setCellValue("G".$cellNum, encodeUTF($sumArray['worktime']));			//労働時間合計
	$sheet->setCellValue("H".$cellNum, encodeUTF($sumArray['aveWorktimeMonth']));	//月平均労働時間
	$sheet->setCellValue("I".$cellNum, encodeUTF($sumArray['aveWorktimeWeek']));	//週平均労働時間

	//合計を太文字にする
	$sheet->getStyle("A{$cellNum}:I{$cellNum}")->getFont()->setBold(true);

	//各セルを格子で囲む
	$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
	getBorders()->
	getAllBorders()->
	setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

	//セル内の文字を中央でそろえる
	$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
	getAlignment()->
	setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

	//偶数番号のセルを別の色で塗り分ける

	if($cellNum % 2 == 0){

		$sheet->
		getStyle( "A{$cellNum}:I{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FF99FFFF');

	}

	//セルの列番号を先に進める
	$cellNum++;

	//受け取った配列から平均値を入力
	$sheet->setCellValue("A".$cellNum, "平均");	//タイトル（平均）
	$sheet->setCellValue("B".$cellNum, encodeUTF($aveArray['workday']));		//氏名
	$sheet->setCellValue("C".$cellNum, encodeUTF($aveArray['aveWorkday']));		//出勤日合計
	$sheet->setCellValue("D".$cellNum, encodeUTF($aveArray['absence']));		//欠席日数
	$sheet->setCellValue("E".$cellNum, encodeUTF($aveArray['business']));		//営業日数
	$sheet->setCellValue("F".$cellNum, encodeUTF($aveArray['resttime']));		//休憩時間
	$sheet->setCellValue("G".$cellNum, encodeUTF($aveArray['worktime']));		//労働時間合計
	$sheet->setCellValue("H".$cellNum, encodeUTF($aveArray['aveWorktimeMonth']));//月平均労働時間
	$sheet->setCellValue("I".$cellNum, encodeUTF($aveArray['aveWorktimeWeek']));//週平均労働時間

	//平均を太文字にする
	$sheet->getStyle("A{$cellNum}:I{$cellNum}")->getFont()->setBold(true);

	//各セルを格子で囲む
	$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
	getBorders()->
	getAllBorders()->
	setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

	//セル内の文字を中央でそろえる
	$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
	getAlignment()->
	setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

	//偶数番号のセルを別の色で塗り分ける

	if($cellNum % 2 == 0){

		$sheet->
		getStyle( "A{$cellNum}:I{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FF99FFFF');

	}

	//月別の情報が引数として入力されているかどうかを確認
	if($monthWorkArray != null){

		//セル番号を2つ先に進める
		$cellNum += 2;

		//表示期間をセルに入力
		$sheet->setCellValue("B".$cellNum, $monthDate);

		//セルの値を2つずらす
		$cellNum+= 2;

		//受け取った月別情報からセルに値を入力
		foreach ($monthWorkArray as $idx => $data)
		{
			//初期値の場合、セルにタイトルを入力
			if($idx == 0){

				$sheet->setCellValue("A".$cellNum, '月'.PHP_EOL.'');
				$sheet->setCellValue("B".$cellNum, '出勤日'.PHP_EOL.'合計');//出勤日合計
				$sheet->setCellValue("C".$cellNum, '週平均'.PHP_EOL.'出勤日数');//週平均出勤日数
				$sheet->setCellValue("D".$cellNum, '欠席日数'.PHP_EOL.'');//欠席日数
				$sheet->setCellValue("E".$cellNum, '営業日数'.PHP_EOL.'');//営業日数
				$sheet->setCellValue("F".$cellNum, '休憩時間'.PHP_EOL.'');//休憩時間
				$sheet->setCellValue("G".$cellNum, '労働時間'.PHP_EOL.'合計');//労働時間合計
				$sheet->setCellValue("H".$cellNum, '月平均'.PHP_EOL.'労働時間');//月平均労働時間
				$sheet->setCellValue("I".$cellNum, '週平均'.PHP_EOL.'労働時間');//週平均労働時間

				//タイトルシートを改行
				$sheet->getStyle("A{$cellNum}:I{$cellNum}")->
				getAlignment()->setWrapText(true);

				// 行高さ設定（setRowHeightにパラメタ指定しないことで自動調整）
				$sheet->getRowDimension(3)->setRowHeight("28.5");

				//セル内の文字を中央でそろえる
				$sheet->getStyle("A{$cellNum}:I{$cellNum}")->
				getAlignment()->
				setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

				//セルをタイトル用のカラー、グレーで色をつける
				$sheet->
				getStyle( "A{$cellNum}:I{$cellNum}" )->
				getFill()->
				setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
				getStartColor()->
				setARGB( 'FFc0c0c0');

				//各セルを格子で囲む
				$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
				getBorders()->
				getAllBorders()->
				setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );


			}else{

				$sheet->setCellValue("A".$cellNum, $data['name']);				//氏名
				$sheet->setCellValue("B".$cellNum, encodeUTF($data['workday']));			//出勤日数
				$sheet->setCellValue("C".$cellNum, encodeUTF($data['aveWorkday']));		//出勤日合計
				$sheet->setCellValue("D".$cellNum, encodeUTF($data['absence']));			//欠席日数
				$sheet->setCellValue("E".$cellNum, encodeUTF($data['business']));  		//営業日数
				$sheet->setCellValue("F".$cellNum, encodeUTF($data['resttime']));			//休憩時間
				$sheet->setCellValue("G".$cellNum, encodeUTF($data['worktime']));			//労働時間合計
				$sheet->setCellValue("H".$cellNum, encodeUTF($data['aveWorktimeMonth']));	//月平均労働時間
				$sheet->setCellValue("I".$cellNum, encodeUTF($data['aveWorktimeWeek']));	//週平均労働時間

				//偶数番号のセルを別の色で塗り分ける

				if($cellNum % 2 == 0){

					$sheet->
					getStyle( "A{$cellNum}:I{$cellNum}" )->
					getFill()->
					setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
					getStartColor()->
					setARGB( 'FF99FFFF');

				}


			}

			//各セルを格子で囲む
			$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
			getBorders()->
			getAllBorders()->
			setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

			//セル内の文字を中央でそろえる
			$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
			getAlignment()->
			setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

			//セルの番号をインクリメント
			$cellNum++;

		}

		//受け取った配列から合計値を入力
		$sheet->setCellValue("A".$cellNum, "合計");	//タイトル（合計）
		$sheet->setCellValue("B".$cellNum, encodeUTF($monthSumArray['workday']));			//氏名
		$sheet->setCellValue("C".$cellNum, encodeUTF($monthSumArray['aveWorkday']));			//出勤日合計
		$sheet->setCellValue("D".$cellNum, encodeUTF($monthSumArray['absence']));			//欠席日数
		$sheet->setCellValue("E".$cellNum, encodeUTF($monthSumArray['business']));			//営業日数
		$sheet->setCellValue("F".$cellNum, encodeUTF($monthSumArray['resttime']));			//休憩時間
		$sheet->setCellValue("G".$cellNum, encodeUTF($monthSumArray['worktime']));			//労働時間合計
		$sheet->setCellValue("H".$cellNum, encodeUTF($monthSumArray['aveWorktimeMonth']));	//月平均労働時間
		$sheet->setCellValue("I".$cellNum, encodeUTF($monthSumArray['aveWorktimeWeek']));	//週平均労働時間

		//合計を太文字にする
		$sheet->getStyle("A{$cellNum}:I{$cellNum}")->getFont()->setBold(true);

		//各セルを格子で囲む
		$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セル内の文字を中央でそろえる
		$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//偶数番号のセルを別の色で塗り分ける

		if($cellNum % 2 == 0){

			$sheet->
			getStyle( "A{$cellNum}:I{$cellNum}" )->
			getFill()->
			setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
			getStartColor()->
			setARGB( 'FF99FFFF');

		}

		//セルの列番号を先に進める
		$cellNum++;

		//受け取った配列から平均値を入力
		$sheet->setCellValue("A".$cellNum, "平均");	//タイトル（平均）
		$sheet->setCellValue("B".$cellNum, encodeUTF($monthAveArray['workday']));		//氏名
		$sheet->setCellValue("C".$cellNum, encodeUTF($monthAveArray['aveWorkday']));		//出勤日合計
		$sheet->setCellValue("D".$cellNum, encodeUTF($monthAveArray['absence']));		//欠席日数
		$sheet->setCellValue("E".$cellNum, encodeUTF($monthAveArray['business']));		//営業日数
		$sheet->setCellValue("F".$cellNum, encodeUTF($monthAveArray['resttime']));		//休憩時間
		$sheet->setCellValue("G".$cellNum, encodeUTF($monthAveArray['worktime']));		//労働時間合計
		$sheet->setCellValue("H".$cellNum, encodeUTF($monthAveArray['aveWorktimeMonth']));//月平均労働時間
		$sheet->setCellValue("I".$cellNum, encodeUTF($monthAveArray['aveWorktimeWeek']));//週平均労働時間

		//平均を太文字にする
		$sheet->getStyle("A{$cellNum}:I{$cellNum}")->getFont()->setBold(true);

		//各セルを格子で囲む
		$sheet->getStyle( "A{$cellNum}:I{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セル内の文字を中央でそろえる
		$sheet->getStyle("B{$cellNum}:I{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//偶数番号のセルを別の色で塗り分ける

		if($cellNum % 2 == 0){

			$sheet->
			getStyle( "A{$cellNum}:I{$cellNum}" )->
			getFill()->
			setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
			getStartColor()->
			setARGB( 'FF99FFFF');

		}

	}

	outputExcel($fileName,$book);


}

/*====================================================================================
 *概要：
 *	excelPersonalWorkTime
 *機能説明：
 *	勤務時間表の個人をExcelに出力して表示するクラス
 *引数：
 *	なし
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/09
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */
function excelPersonalWorktime($workData,$holidayData,$infomation,$sum,$name)
{
	// PHPExcelオブジェクトの作成
	$book = new PHPExcel();

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//ファイル名を入力
	$fileName = "勤務時間表({$name})".date('_Ymd').".xls";

	//入力するデフォルトフォントを設定
	$sheet->getDefaultStyle()->getFont()->setName( 'ＭＳ ゴシック' )->setSize( 11 );


	//シート名指定
	$sheet->setTitle("勤務時間表(個人)");

	//各シートの幅を設定する
	$sheet->getColumnDimension( 'A' )->setWidth(16);
	$sheet->getColumnDimension( 'B' )->setWidth(10);
	$sheet->getColumnDimension( 'C' )->setWidth(8);
	$sheet->getColumnDimension( 'D' )->setWidth(8);
	$sheet->getColumnDimension( 'E' )->setWidth(10);
	$sheet->getColumnDimension( 'F' )->setWidth(10);
	$sheet->getColumnDimension( 'G' )->setWidth(10);
	$sheet->getColumnDimension( 'H' )->setWidth(10);

	//表示期間をセルに入力
	$sheet->setCellValue("A1", "表示期間 ：") ;
	$sheet->setCellValue("B1", "{$infomation}");

	//セル番号を管理する変数を宣言
	$cellNum = 3;

	//取得できている勤務表の数だけ繰り返し処理を行う
	for($v=0;$v<count($workData);$v++)
	{
		//出勤表のタイトルを入力
		$sheet->setCellValue("D{$cellNum}", "{$name}出勤表");

		//セルの行をひとつ進める
		$cellNum++;

		//タイトルを各セルに入力する
		$sheet->setCellValue("A{$cellNum}", "日付");		//日付
		$sheet->setCellValue("B{$cellNum}", "曜日");		//曜日
		$sheet->setCellValue("C{$cellNum}", "出勤");		//出勤
		$sheet->setCellValue("D{$cellNum}", "退勤");		//退勤
		$sheet->setCellValue("E{$cellNum}", "休憩時間");	//休憩時間
		$sheet->setCellValue("F{$cellNum}", "実働時間");	//実働時間
		$sheet->setCellValue("G{$cellNum}", "ステータス");	//ステータス
		$sheet->setCellValue("H{$cellNum}", "備考欄");	//備考欄

		//セルをタイトル用のカラー、グレーで色をつける
		$sheet->
		getStyle( "A{$cellNum}:H{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FFc0c0c0');

		//セル内の文字を中央でそろえる
		$sheet->getStyle("A{$cellNum}:H{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//各セルを格子で囲む
		$sheet->getStyle(  "A{$cellNum}:H{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セルの行を一つ進める
		$cellNum++;

		//その月分のデータを繰り返し処理でセルに書き込む
		for($i=0;$i<count($workData[$v]); $i++)
		{

			//日付を該当セルに入力
			$sheet->setCellValue("A{$cellNum}", "{$workData[$v][$i]['day']}");

			//曜日を該当セルに入力
			$sheet->setCellValue("B{$cellNum}", "{$workData[$v][$i]['week']}");

			//土日、もしくは祝日の種類によって文字色を変化させる
			if(setDateClass($workData[$v][$i]['day'],$holidayData) == "holiday"){

				$code = "FFFF0000";

			}else if(setDateClass($workData[$v][$i]['day'],$holidayData) == "saturday"){

				$code = "FF0000FF";

			}else{

				$code = "FF000000";

			}

			$sheet->getStyle("A{$cellNum}:B{$cellNum}")->getFont()->getColor()->setARGB("{$code}");

			//ステータスが休みの場合は出勤時間と退勤時間に空白を入力する
			if($workData[$v][$i]['statusid'] == 3){

				//出勤時間と退勤時間のセルに空白を入力
				$sheet->setCellValue("C{$cellNum}", "");
				$sheet->setCellValue("D{$cellNum}", "");

			}else{

				//出勤時間と退勤時間をセルに入力
				$sheet->setCellValue("C{$cellNum}", "{$workData[$v][$i]['starttime']}");
				$sheet->setCellValue("D{$cellNum}", "{$workData[$v][$i]['endtime']}");

			}

			//休憩時間を該当セルに入力
			$sheet->setCellValue("E{$cellNum}", "{$workData[$v][$i]['resttime']}");

			//実働時間を該当セルに入力
			$sheet->setCellValue("F{$cellNum}", "{$workData[$v][$i]['worktime']}");

			//ステータスを該当セルに入力
			$sheet->setCellValue("G{$cellNum}", "{$workData[$v][$i]['statusname']}");

			//備考欄を該当セルに入力
			$sheet->setCellValue("H{$cellNum}", "{$workData[$v][$i]['memo']}");

			//セル内の文字を中央でそろえる
			$sheet->getStyle("A{$cellNum}:H{$cellNum}")->
			getAlignment()->
			setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

			//各セルを格子で囲む
			$sheet->getStyle(  "A{$cellNum}:H{$cellNum}" )->
			getBorders()->
			getAllBorders()->
			setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

			//偶数番号のセルを別の色で塗り分ける
			if($cellNum % 2 == 0)
			{

				$sheet->
				getStyle( "A{$cellNum}:H{$cellNum}" )->
				getFill()->
				setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
				getStartColor()->
				setARGB( 'FF99FFFF');

			}

			//当日だった場合、セルを別の色で塗り分ける
			if($workData[$v][$i]['day'] == date('Y-m-d'))
			{
				$sheet->
				getStyle( "A{$cellNum}:H{$cellNum}" )->
				getFill()->
				setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
				getStartColor()->
				setARGB( 'FFFFFF00');
			}

			//セルの番号を一つ進める
			$cellNum++;
		}

		//その月の合計値をセルに入力する
		$sheet->setCellValue("A{$cellNum}", "勤務日数");				//勤務日数タイトル
		$sheet->setCellValue("B{$cellNum}", $sum[$v]['sumDay']);	//勤務日数

		//セルをタイトル用のカラー、グレーで色をつける
		$sheet->
		getStyle( "A{$cellNum}:C{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FFc0c0c0');

		//セル内の文字を太字に変更する
		$sheet->getStyle("A{$cellNum}:C{$cellNum}")->getFont()->setBold(true);

		//セル内の文字を中央でそろえる
		$sheet->getStyle("A{$cellNum}:C{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//各セルを格子で囲む
		$sheet->getStyle(  "A{$cellNum}:C{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//勤務日数のセルをCと結合する。
		$sheet->mergeCells("B{$cellNum}:C{$cellNum}");

		//セル番号を次に進める
		$cellNum++;

		$sheet->setCellValue("A{$cellNum}", "合計勤務時間");				//合計勤務時間タイトル
		$sheet->setCellValue("B{$cellNum}", $sum[$v]['sumWorkTime']);	//合計勤務時間

		//セルをタイトル用のカラー、グレーで色をつける
		$sheet->
		getStyle( "A{$cellNum}:C{$cellNum}" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FFc0c0c0');

		//セル内の文字を太字に変更する
		$sheet->getStyle("A{$cellNum}:C{$cellNum}")->getFont()->setBold(true);

		//セル内の文字を中央でそろえる
		$sheet->getStyle("A{$cellNum}:C{$cellNum}")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え

		//各セルを格子で囲む
		$sheet->getStyle(  "A{$cellNum}:C{$cellNum}" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//合計勤務時間のセルをCと結合する。
		$sheet->mergeCells("B{$cellNum}:C{$cellNum}");

		//セル番号を2つ先に進める
		$cellNum += 2;
	}

	outputExcel($fileName,$book);
}

/*====================================================================================
 *概要：
 *	setCellAlphabet
 *機能説明：
 *	セルを週間を管理する変数cntを元に3つのセルを選択する
 *	配列を返す。
 *引数：
 *	$cnt(数値)
 *戻り値：
 *	$cell(アルファベットを格納する配列)
 *備考：
 *	作成日)	2015/10/12
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */

function setCellAlphabet($cnt)
{
	//週間に合わせて曜日と合致する変数をセットする
	switch($cnt){

		case 0:
			$cell = array("A","B","C");
			break;
		case 1:
			$cell = array("D","E","F");
			break;
		case 2:
			$cell = array("G","H","I");
			break;
		case 3:
			$cell = array("J","K","L");
			break;
		case 4:
			$cell = array("M","N","O");
			break;
		case 5:
			$cell = array("P","Q","R");
			break;
		case 6:
			$cell = array("S","T","U");
			break;

	}

	return $cell;
}

/*====================================================================================
 *概要：
 *	startExcel
 *機能説明：
 *	PHPExcelの使用を開始し、セル名をセットする。
 *引数：
 *	$sheetName(シート名)
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/19
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */


function startExcel($sheetName)
{
	// PHPExcelオブジェクトの作成
	$book = new PHPExcel();

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//シート名指定
	$sheet->setTitle($sheetName);

}

/*====================================================================================
 *概要：
 *	outputExcel
 *機能説明：
 *	ファイル名を引数にそのファイル名でExcelファイルを出力する。
 *	またIEでは文字化けが発生する為使用ブラウザを判別し、処理を行う。
 *引数：
 *	$fileName(ファイル名)
 *戻り値：
 *	なし
 *備考：
 *	作成日)	2015/10/19
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 ====================================================================================
 */
 function outputExcel($fileName,$book){

 	//IE11を含むIE判定
	$ua = $_SERVER['HTTP_USER_AGENT'];

	if (strstr($ua, 'Trident') || strstr($ua, 'MSIE')) {
	    /* ～IEの場合の処理～ */

		$fileName = urlencode($fileName);

		// Excel2003形式で出力する
		header('Content-Type: application/vnd.ms-excel');

		header('Content-Disposition: attachment; filename="' .
		$fileName . '"');

		$this->getResponse()
             ->setHeader('Cache-Control', 'no-cache')// IE
             ->setHeader('Pragma', 'no-cache');        // IE


		header('Cache-Control: max-age=0');
		$writer = PHPExcel_IOFactory::createWriter($book, 'Excel5');
		$writer->save("php://output");

	}else{
		/* ～他ブラウザの処理～ */

		$fileName = rawurlencode($fileName);

		// Excel2003形式で出力する
		header('Content-Type: application/vnd.ms-excel');

		header('Content-Disposition: attachment; filename="' .
		rawurldecode(mb_convert_encoding($fileName, 'Shift_JIS', 'UTF-8')) . '"');


		header('Cache-Control: max-age=0');
		$writer = PHPExcel_IOFactory::createWriter($book, 'Excel5');
		$writer->save("php://output");
	}

 }
?>
