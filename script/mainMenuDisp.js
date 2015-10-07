$( function() {
	$( ".event" ).tooltip( {
		track: true
	} );

	//イベント情報の非表示
	$('.event-space').hide();

	//欠席者の非表示
	$('.absence-calendar').hide();

	//チェックボックスがクリックされた時動作する
	$("#worksheet,#seminar,#absence").click(function(){

		setDisplayCalendar();

	});

	//関数の作成
	function setDisplayCalendar()
	{
		//両方
		if($('#worksheet').prop('checked') && $('#seminar').prop('checked'))
		{
			//イベントスペースの非表示
			$('.eventarea').hide();

			//勤務データの表示
			$('.work-calendar').show();

			//イベント情報の表示
			$('.event-space').show();

		}else if($('#worksheet').prop('checked')){//業務のチェックボックスのみ

			//イベントスペースの表示
			$('.eventarea').show();

			//勤務データの表示
			$('.work-calendar').show();

			//イベント情報の非表示
			$('.event-space').hide();

		}else if($('#seminar').prop('checked')){//セミナーのチェックボックスのみ

			//イベントスペースの非表示
			$('.eventarea').hide();

			//勤務データの非表示
			$('.work-calendar').hide();

			//イベント情報の表示
			$('.event-space').show();

		}else{//どちらでもない

			//イベントスペースの非表示
			$('.eventarea').hide();

			//勤務データの非表示
			$('.work-calendar').hide();

			//イベント情報の非表示
			$('.event-space').hide();

		}

		//欠席者の表示判定
		if($('#absence').prop('checked') ){
			$('.absence-calendar').show();
		}else{
			$('.absence-calendar').hide();
		}

	}
} );