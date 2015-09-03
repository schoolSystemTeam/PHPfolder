$(function(){
	$('#logoutLink').click(function() {
		if (!confirm('ログアウト。\nよろしいですか？')) {
			return false;
		}
	});
});