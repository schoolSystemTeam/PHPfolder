/*
 *概要：
 *	tabMenu.js
 *機能説明：
 *	id="tabMenu"に登録されたタブ切り替え機能を行う。
 *	#tabMenu内のliの<a>タグリンクをクリックするとタブボックスを切り替える処理を
 *	行う。
 *備考：
 *	作成日)	2015/9/01
 *	作成者)	水島創太
 *	説明）
 *	更新日)
 *	更新者)
 *	変更)
 */

$(function(){
	$("#tabMenu li a").on("click", function() {
		$("#tabBoxes div").hide();
		$($(this).attr("href")).fadeToggle();
	});
	 return false;
 });