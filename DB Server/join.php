<?php
/**
 * 회원가입 시 회원정보 저장
 * Google ID -> userID, 게임 닉네임 -> nickName
 * userinfo 테이블 : id 와 닉네임
 * gameinfo 테이블 : id 와 주행 거리, 소모 칼로리
**/
mysql_connect('localhost', 'root', 'tmakxmtkdlzmf');
mysql_select_db('smartCycle');

$userID = @$_POST['userID'];
$nickName = @$_POST['nickName'];

if(!$userID || !$nickName)
	die("No data");
$userQuery = mysql_query("SELECT userID FROM userinfo WHERE userid='$userID'");

if(0 == mysql_num_rows($userQuery)){
	mysql_query("INSERT INTO userInfo (userID, nickName) VALUES('$userID', '$nickName');");
	mysql_query("INSERT INTO gameInfo (userID, totalCarl, totalDist) VALUES ('$userID', 0, 0);");
}
/*
mysql_query('INSERT INTO userinfo (userid, nickname) VALUES("user2", "username1");');
mysql_query('INSERT INTO gameinfo (userid, totalCarl, totalDist) VALUES("user2", 0, 0);');
*/
?>