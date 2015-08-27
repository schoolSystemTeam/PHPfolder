$(function(){
	$('a[href="../login/login.php"]').click(function() {
		if (!confirm('ログアウト。\nよろしいですか？')) {
			return false;
		}
	});
});