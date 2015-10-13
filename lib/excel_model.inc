<?php
//excelライブラリの読み込み
require_once '../Classes/PHPExcel.php';

/*====================================================================================
 *概要：
 *	excelTest
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

function calendarOutPrintForExcel($calendar,$eventList,$workerList,$year,$month,$dispMonth)
{

	// PHPExcelオブジェクトの作成
	$book = new PHPExcel();

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//シート名指定
	$sheet->setTitle("勤務時間表");

	$fileName = mb_convert_encoding("勤務予定カレンダー.xls","SJIS","UTF-8");

	//入力するデフォルトフォントを設定
	$sheet->getDefaultStyle()->getFont()->setName( 'ＭＳ ゴシック' )->setSize( 11 );

	//カラムの幅を自動設定
	$sheet->getColumnDimension( 'A:G' )->setAutoSize( true );

	//表示期間を選択
	switch ($dispMonth)
	{
		case 0:
			$roop = 3;
		case 1:
			$roop = 2;
		case 2:
			$roop = 1;
		default:
			$roop = 3;
	}

	//セルの番号を定義
	$cellNum = 1;

	//表示されているヶ月分のカレンダーをループ
	for($i=0;$i>$roop;$i++)
	{
		//表示期間をセルに入力
		$sheet->setCellValue("A{$cellNum}", $year[$i]."年".$month[$i]."月");

		//1週間分のセルを結合
		$sheet->mergeCells("A{$cellNum}:G{$cellNum}");

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
		$sheet->setCellValue("A2", "月");
		$sheet->setCellValue("B2", "火");
		$sheet->setCellValue("C2", "水");
		$sheet->setCellValue("D2", "木");
		$sheet->setCellValue("E2", "金");
		$sheet->setCellValue("F2", "土");
		$sheet->setCellValue("G2", "日");

		$sheet->
		getStyle( "A2:G2" )->
		getFill()->
		setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
		getStartColor()->
		setARGB( 'FFC0C0C0');

		//各セルを格子で囲む
		$sheet->getStyle( "A1:G2" )->
		getBorders()->
		getAllBorders()->
		setBorderStyle( PHPExcel_Style_Border::BORDER_THIN );

		//セル内の文字を中央でそろえる
		$sheet->getStyle("A1:G2")->
		getAlignment()->
		setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);//文字の横位置揃え
	}

	//ファイル名文字化け対策
	rawurlencode($fileName);

	// Excel2003形式で出力する
	header('Content-Type: application/vnd.ms-excel');
	header("Content-Disposition: attachment;filename='{$fileName}'");
	header('Cache-Control: max-age=0');
	ob_end_clean(); // ファイル破損防止
	$writer = PHPExcel_IOFactory::createWriter($book, 'Excel5');
	$writer->save("php://output");


}

/*====================================================================================
 *概要：
 *	excelTest
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

	$objReader = PHPExcel_IOFactory::createReader('Excel5');
	$book = $objReader->load("../excel/overallWorktimeTemp.xls");

	// テンプレートのシートを選択
	$book->setActiveSheetIndex(0);

	//$sheetにアクティブシートをコピーする
	$sheet = $book->getActiveSheet();

	//シート名指定
	$sheet->setTitle("勤務時間表");

	//表示期間をセルに入力
	$sheet->setCellValue("B1", "{$date}");

	//セルの値を管理する変数を宣言
	$cellNum = 4;

	$fileName = mb_convert_encoding("勤務時間表（全体）".date('_Ymd').".xls","SJIS","UTF-8");

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

				$sheet->setCellValue("A".$cellNum, "月");
				$sheet->setCellValue("B".$cellNum, "出勤日\n合計");//出勤日合計
				$sheet->setCellValue("C".$cellNum, "週平均\n出勤日数");//週平均出勤日数
				$sheet->setCellValue("D".$cellNum, "欠席日数");//欠席日数
				$sheet->setCellValue("E".$cellNum, "営業日数");//営業日数
				$sheet->setCellValue("F".$cellNum, "休憩時間");//休憩時間
				$sheet->setCellValue("G".$cellNum, "労働時間\n合計");//労働時間合計
				$sheet->setCellValue("H".$cellNum, "月平均\n労働時間");//月平均労働時間
				$sheet->setCellValue("I".$cellNum, "週平均\n労働時間");//週平均労働時間

				//セルをタイトル用のカラー、グレーで色をつける
				$sheet->
				getStyle( "A{$cellNum}:I{$cellNum}" )->
				getFill()->
				setFillType( PHPExcel_Style_Fill::FILL_SOLID )->
				getStartColor()->
				setARGB( 'FFa9a9a9');


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

	// Excel2003形式で出力する
	header('Content-Type: application/vnd.ms-excel');
	header('Content-Disposition: attachment;filename="'.$fileName.'"');
	header('Cache-Control: max-age=0');
	$writer = PHPExcel_IOFactory::createWriter($book, 'Excel5');
	$writer->save("php://output");


}
?>
