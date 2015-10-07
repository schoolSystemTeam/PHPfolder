/*
 *概要：
 *	logout.js
 *機能説明：
 *	ログアウトするかどうかの確認ダイアログを表示する
 *備考：
 *	作成日)	2015/9/30
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){
	$('#logoutLink').click(function() {
		if (!confirm('ログアウトします。\nよろしいですか？')) {
			return false;
		}
	});
});