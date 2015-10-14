<?php
// ライブラリを読み込む
require_once('tcpdf.php');

// PDF オブジェクトを作成
/*
PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT は /tcpdf/config/tcpdf_config.php ファイルで定義されています。
PDF_PAGE_ORIENTATION はページの向き ( P = 縦, L = 横 )
PDF_UNIT は単位 ( pt = point, mm = millimeter, cm = centimeter, in = inch )
PDF_PAGE_FORMAT はページフォーマット ( デフォルトは A4 )
*/
$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8');

// ヘッダーフッターの設定
// デフォルトでヘッダーに余計な線が出るので削除
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);

// 1ページ目を準備
$pdf->AddPage();

// フォントを指定 ( 小塚ゴシックPro M を指定 )
// 日本語を使う場合は、日本語に対応しているフォントを使う
$pdf->SetFont('kozgopromedium', '', 10);

// h1 で見出しを出力 ( HTML )
$pdf->writeHTML('<h1>勤務時間表</h1>', false, false, false, false, 'C');

$pdf->writeHTML("<br><h4>表示期間:{$this->infomation}</h4>", false, false, false, false, 'L');

// HTML と CSS でテーブルを作ります
$style = <<< EOF
<style>

.record{
	background-color:#ddd;
}

.background{
	background-color:#afeeee;
}

td{
	vertical-align:middle;
	text-align: center;
}

th{
    font-weight: bold;
    border: 1px solid #333;
    text-align: center;
}
</style>
<br />
<br />
EOF;

$html = $style;

$html .= '<table cellspacing="2">
			<tr class="record">
				<td>氏名</td>
				<td>出勤日<br>合計</td>
				<td>週平均<br>出勤日数</td>
				<td>欠席日数</td>
				<td>営業日数</td>
				<td>休憩時間</td>
				<td>労働時間<br>合計</td>
				<td>月平均<br>労働時間</td>
				<td>週平均<br>労働時間</td>
			</tr>';

$a=0;

foreach($this->displayData as $key => $value){

	if($a%2 == 1){
		$html .= "<tr>";
	}else{
		$html .= '<tr class="background">';
	}

	$html .= "<td>{$value['name']}</td>
			<td>{$value['workday']}</td>
			<td>{$value['aveWorkday']}</td>
			<td>{$value['absence']}</td>
			<td>{$value['business']}</td>
			<td>{$value['resttime']}</td>
			<td>{$value['worktime']}</td>
			<td>{$value['aveWorktimeMonth']}</td>
			<td>{$value['aveWorktimeWeek']}</td>
    	</tr>";

	$a++;
}

if($a%2 == 1){
	$html .= "<tr>";
}else{
	$html .= '<tr class="background">';
}

$html .= "	<th>合計</th>
			<th>{$this->sumArray['workday']}</th>
			<th>{$this->sumArray['aveWorkday']}</th>
			<th>{$this->sumArray['absence']}</th>
			<th>{$this->sumArray['business']}</th>
			<th>{$this->sumArray['resttime']}</th>
			<th>{$this->sumArray['worktime']}</th>
			<th>{$this->sumArray['aveWorktimeMonth']}</th>
			<th>{$this->sumArray['aveWorktimeWeek']}</th>
		</tr>";

$a++;

if($a%2 == 1){
	$html .= "<tr>";
}else{
	$html .= '<tr class="background">';
}

$html .= "	<th>平均</th>
			<th>{$this->aveArray['workday']}</th>
			<th>{$this->aveArray['aveWorkday']}</th>
			<th>{$this->aveArray['absence']}</th>
			<th>{$this->aveArray['business']}</th>
			<th>{$this->aveArray['resttime']}</th>
			<th>{$this->aveArray['worktime']}</th>
			<th>{$this->aveArray['aveWorktimeMonth']}</th>
			<th>{$this->aveArray['aveWorktimeWeek']}</th>
		</tr>
		</table>";

// 作った HTML を書きだす
$pdf->writeHTML($html, true, false, false, false, 'L');


if(is_array($this->monthDispData)){

	$infomation = substr($this->infomation,0,4);

	$pdf->writeHTML("<h4>{$infomation}年度月別個人データ</h4>", false, false, false, false, 'L');

	$html2 = $style;
	$html2 .= '<table cellspacing="2" cellpadding="2" class="border">
				<tr class="record">
					<td>月</td>
					<td>出勤日<br>合計</td>
					<td>週平均<br>出勤日数</td>
					<td>欠席日数</td>
					<td>営業日数</td>
					<td>休憩時間</td>
					<td>労働時間<br>合計</td>
					<td>月平均<br>労働時間</td>
					<td>週平均<br>労働時間</td>
				</tr>';

	$a = 0;

	foreach($this->monthDispData as $key => $value){

		if($a%2 == 1){
			$html2 .= "<tr>";
		}else{
			$html2 .= '<tr class="background">';
		}

		$html2 .= "
					<td>{$value['name']}</td>
					<td>{$value['workday']}</td>
					<td>{$value['aveWorkday']}</td>
					<td>{$value['absence']}</td>
					<td>{$value['business']}</td>
					<td>{$value['resttime']}</td>
					<td>{$value['worktime']}</td>
					<td>{$value['aveWorktimeMonth']}</td>
					<td>{$value['aveWorktimeWeek']}</td>
				</tr>";

		$a++;
	}

	$html2 .= <<< EOF
			<tr class="background border">
				<th>合計</th>
				<th>{$this->monthSumArray['workday']}</th>
				<th>{$this->monthSumArray['aveWorkday']}</th>
				<th>{$this->monthSumArray['absence']}</th>
				<th>{$this->monthSumArray['business']}</th>
				<th>{$this->monthSumArray['resttime']}</th>
				<th>{$this->monthSumArray['worktime']}</th>
				<th>{$this->monthSumArray['aveWorktimeMonth']}</th>
				<th>{$this->monthSumArray['aveWorktimeWeek']}</th>
			</tr>

			<tr class="border">
				<th>平均</th>
				<th>{$this->monthAveArray['workday']}</th>
				<th>{$this->monthAveArray['aveWorkday']}</th>
				<th>{$this->monthAveArray['absence']}</th>
				<th>{$this->monthAveArray['business']}</th>
				<th>{$this->monthAveArray['resttime']}</th>
				<th>{$this->monthAveArray['worktime']}</th>
				<th>{$this->monthAveArray['aveWorktimeMonth']}</th>
				<th>{$this->monthAveArray['aveWorktimeWeek']}</th>
			</tr>
		</table>
EOF;
}
// 作った HTML を書きだす
$pdf->writeHTML($html2, false, false, false, false, 'L');

// PDF を出力 ( I = ブラウザ出力, D = ダウンロード, F = ローカルファイルとして保存, S = 文字列として出力 )
$pdf->Output("overallWorkTime.pdf", "D");

?>