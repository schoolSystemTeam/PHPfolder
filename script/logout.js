$(function(){
	$('#logoutLink').click(function() {
		if (!confirm('ログアウトします。\nよろしいですか？')) {
			return false;
		}
	});
});