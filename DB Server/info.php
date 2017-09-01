<?php
/**
 * 유저의 플레이 내역을 조회
 * gameinfo의 totalDist, totalCarl 조회
 * 출력되는 처음 값은 totalDist
 * 출력되는 두번째 값은 totalCarl
**/
mysql_connect('localhost', 'root', 'tmakxmtkdlzmf');
mysql_select_db('smartcycle');

$userID = @$_POST['userID'];

if(!$userID)
	die("No data");

$infoQuery = mysql_query("SELECT totalDist, totalCarl FROM gameinfo WHERE userid='$userID'");

while(($infoRow = mysql_fetch_array($infoQuery)))
	echo $infoRow['totalDist']."/".$infoRow['totalCarl']."\n";

/*
$infoQuery = mysql_query('SELECT totalDist, totalCarl FROM gameinfo WHERE userid="user1"');

while(($infoRow = mysql_fetch_array($infoQuery)))
	echo $infoRow['totalDist'].", ".$infoRow['totalCarl']."\n";
*/
?>