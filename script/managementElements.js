/*
 *概要：
 *	managementElements.js
 *機能説明：
 *	クリックで内部を表示するアコーディオン機能を提供する。
 *	#acMenu内のdtをクリックするとアコーディオンメニューの表示,非表示
 *	を切り替えることができる。
 *備考：
 *	作成日)	2015/9/01
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){

	$(".update").click(function(){

		$('.execute').val($(this).data('execute'));

		if (!confirm('この内容で情報を変更します。\nよろしいですか？')) {
			return false;
		}

	});

	$(".delete").click(function(){

		$('.execute').val($(this).data('execute'));

			if (!confirm('この情報を削除します。\nよろしいですか？')) {
				return false;
			}
		});

	$(".insert").click(function(){

		if (!confirm('この情報を登録します。\nよろしいですか？')) {
			return false;
		}

	});

});