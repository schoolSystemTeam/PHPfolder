<?php
// ライブラリを読み込む
require_once('tcpdf.php');

// PDF オブジェクトを作成
/*
PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT は /tcpdf/config/tcpdf_config.php ファイルで定義。
PDF_PAGE_ORIENTATION はページの向き ( P = 縦, L = 横 )
PDF_UNIT は単位 ( pt = point, mm = millimeter, cm = centimeter, in = inch )
PDF_PAGE_FORMAT はページフォーマット ( デフォルトは A4 )
*/
$pdf = new TCPDF('P', PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8');

// ヘッダーフッターの設定
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);

// 1ページ目を準備
$pdf->AddPage();

$style = <<<EOF
<style>

.subWork{
	background-color: #FAD1D5;
}

.subAbsence{
	background-color: #B9FDF7;
}

.kesseki{
	background-color: #cccccc;
}

.size{
	font-size:6px;
}

.calendar {
	width:25%;
	font-size:13px;
    text-align: center;
}

.holiday{
	color:red;
}

.saturday{
	color:blue;
}

.holidayName{
	width:27.5px;
	color:red;
	text-align:right;
	font-size:5px;
}

</style>

EOF;

// フォントを指定(小塚ゴシックPro M を指定)
$pdf->SetFont('kozgopromedium', '',11);

$round = count($this->year) - $this->dispMonth;

for($i=0; $i < $round; $i++){

	$pdf->writeHTML('<h2>勤務予定カレンダー</h2>',true,false,false,false,'C');

	$pdf->Cell(0,0,"{$this->year[$i]}年{$this->month[$i]}月", 1, 1, 'C');
	$pdf->Cell(27.1,0,"月", 1, 0, 'C');
	$pdf->Cell(27.2,0,"火", 1, 0, 'C');
	$pdf->Cell(27.1,0,"水", 1, 0, 'C');
	$pdf->Cell(27.2,0,"木", 1, 0, 'C');
	$pdf->Cell(27.1,0,"金", 1, 0, 'C');
	$pdf->writeHTMLCell(27.2,0, '', '', '<span style="color:blue;">土</span>', 1, 0, 0, true, 'C');
	$pdf->writeHTMLCell(27.1,0, '', '', '<span style="color:red;">日</span>', 1, 1, 0, true, 'C');

	$cnt = 0;
	$html = $style;
	$html .= '<table border="1" cellpadding="2">
				<tr>';

	foreach ($this->calendar[$i] as $key => $value){

		$cnt++;

		$html .=<<< EOF
					<td>
						<table>
							<tr>
							<td class="holidayName"></td>
							<td class="calendar {$value['class']}">{$value['day']}</td>
							<td class="holidayName">{$this->holidayCalendar[$i][$key]['holidayName']}</td>
							</tr>
						</table>
EOF;

		if($this->work == "true"){

			$html .= '<table cellpadding="1">';

			if($this->seminar == "false"){

				$html .= '<tr>
							<td class="size">';

				if($value['day'] != ""){
					foreach($this->eventList["{$this->year[$i]}-{$this->month[$i]}-{$value['day']}"] as $idx => $eventInfo){
						if($eventInfo["shortName"] != ""){
							$html .= <<< EOF
							<span style="background-color:{$eventInfo['color']};">&nbsp;{$eventInfo['shortName']}</span>
EOF;
						}
					}
				}
				$html .= "</td>
						</tr>";
			}

			foreach($this->workerList[$i][$key] as $index => $info){

				if($info["statusid"] != 3){

					$start = createTimeFormat($info['workstarttime']);
					$end = createTimeFormat($info['workendtime']);
					$name = getFirstStr($info['p-name']);

					if($info['statusid'] == 1){
						$html .= '<tr class="subWork">';
					}elseif($info['statusid'] == 2){
						$html .= '<tr class="subAbsence">';
					}else{
						$html .= '<tr>';
					}

					$html .= <<<EOF
							<td class="size">
							<span style="color:{$info['code']};">{$info['name']}</span>
EOF;

					$html .= "&nbsp;{$start}";
					if($info['workstarttime'] != ""){
							$html .= "&nbsp;～";
					}
					$html .= <<< eof
							{$end}
							 　<span style="color:{$info['color']};">{$name}</span>
eof;

					if($info["statusid"] != 6){
						$html .= "　{$info['statusName']}";
					}

					$html .= "</td>
							  </tr>";
				}
			}

			if($this->absence == "true"){

				foreach($this->workerList[$i][$key] as $index2 => $info2){
					if($info2["statusid"] == 3 && $info2["worktype"] == 1){

						$html .= <<<EOF
								<tr class="kesseki">
								<td class="size">
								<span style="color:{$info2['code']};">{$info2['name']}</span>
								{$info2['statusName']}
								</td>
								</tr>
EOF;
					}
				}
			}

			if($this->seminar == "true"){

					if($value['day'] != ""){
						foreach($this->eventList["{$this->year[$i]}-{$this->month[$i]}-{$value['day']}"] as $idx => $eventInfo){
							if($eventInfo["shortName"] != ""){
								$html .= <<< EOF
								<tr>
									<td class="size">
									<span style="background-color:{$eventInfo['color']};">&nbsp;{$eventInfo['shortName']}</span>
									<span style="color:{$eventInfo['code']};">&nbsp;{$eventInfo['name']}</span>
									</td>
								</tr>
EOF;
							}
						}
					}
				}
				$html .= "</table>";
			}

		$html .="</td>";

		if ($cnt == 7){
				$html .='</tr>
						 <tr>';
				$cnt = 0;
		}
	}

	$html .= "</tr></table>";
	$pdf->writeHTML($html,true,false,false,false,'L');

	if($i < $round-1){
		$pdf->AddPage();
	}
}

// PDF を出力 ( I = ブラウザ出力, D = ダウンロード, F = ローカルファイルとして保存, S = 文字列として出力 )
$filename = "勤務予定カレンダー{$this->year[0]}年{$this->month[0]}月({$i}ヵ月分)";
$pdf->Output($filename.".pdf", "D");

?>