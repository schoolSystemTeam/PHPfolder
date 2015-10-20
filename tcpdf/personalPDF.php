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
$pdf->SetFont('kozgopromedium', '', 10);

// h1 で見出しを出力
$pdf->writeHTML('<h1>勤務時間表</h1>', false, false, false, false, 'C');

$pdf->writeHTML("<br><h3>表示期間:{$this->infomation}</h3>", false, false, false, false, 'L');

// HTML と CSS でテーブル作り
$style = <<< EOF
<style>

.record{
	background-color:#ddd;
}

.background{
	background-color:#afeeee;
}

td{
	text-align: center;
}

th{
    font-weight: bold;
    border: 1px solid #333;
    background-color:#ddd;
    text-align: center;
    width:80px;
}

.holiday{
	color:#FF0000;
}

.saturday{
	color:#0000FF;
}
</style>
EOF;

for($i=0; $i<count($this->workdata); $i++){

	$pdf->writeHTML("{$this->name}勤務表", true, false, false, false, 'C');

	$html = $style;

	$html .= '<table cellspacing="2" cellpadding="2">
				<tr class="record">
					<td>日付</td>
					<td width="35">曜日</td>
					<td width="50">出勤</td>
					<td width="50">退勤</td>
					<td>休憩時間</td>
					<td>実働時間</td>
					<td>ステータス</td>
					<td width="110">備考欄</td>
				</tr>';

	$a=0;

	for($j=0; $j<count($this->workdata[$i]); $j++){

		$class = setDateClass($this->workdata[$i][$j]['day'],$this->holidayData);

		if($a%2 == 1){
			$html .= "<tr>";
		}else{
			$html .= '<tr class="background">';
		}

		$html .= <<<EOF

					<td class="{$class}">{$this->workdata[$i][$j]['day']}</td>
					<td class="{$class}">{$this->workdata[$i][$j]['week']}</td>
					<td>{$this->workdata[$i][$j]['starttime']}</td>
					<td>{$this->workdata[$i][$j]['endtime']}</td>
					<td>{$this->workdata[$i][$j]['resttime']}</td>
					<td>{$this->workdata[$i][$j]['worktime']}</td>
					<td>{$this->workdata[$i][$j]['statusname']}</td>
					<td>{$this->workdata[$i][$j]['memo']}</td>
		    	</tr>
EOF;
		$a++;
	}
	$html .= '</table>
			  <table cellpadding="2">';

	$html .= "	<tr>
					<th>勤務日数</th>
					<th>{$this->sum[$i]['sumDay']}</th>
				</tr>
				<tr>
					<th>合計勤務時間</th>
					<th>{$this->sum[$i]['sumWorkTime']}</th>
				</tr>
			</table>";

	// 作った HTML を書きだす
	$pdf->writeHTML($html, true, false, false, false, 'L');

	if($i != count($this->workdata)-1){
		$pdf->AddPage();
	}
}

// PDF を出力 ( I = ブラウザ出力, D = ダウンロード, F = ローカルファイルとして保存, S = 文字列として出力 )
$filename = "勤務時間表({$this->name})_". date('Ymd');
$pdf->Output($filename.".pdf", "D");

?>