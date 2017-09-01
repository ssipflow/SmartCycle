<?php
/**
 * 게임이 종료됐을 때 데이터를 업데이트
 * gameinfo 테이블 업데이트
**/
mysql_connect('localhost', 'root', 'tmakxmtkdlzmf');
mysql_select_db('smartCycle');

$userID = @$_POST['userID'];
$dist = @$_POST['dist'];
$carl = @$_POST['carl'];

if(!$dist || !$carl || !$userID)
	die("No data");

mysql_query("UPDATE gameinfo SET totalCarl = totalCarl + '$dist', totalDist = totalDist + '$carl' WHERE userid = '$userID';");

//mysql_query('UPDATE gameinfo SET totalCarl = totalCarl + 1, totalDist = totalDist + 1 WHERE userid= "user1";');
?>