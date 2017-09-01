-- phpMyAdmin SQL Dump
-- version 4.4.13.1
-- http://www.phpmyadmin.net
--
-- Host: localhost:3306
-- 생성 시간: 15-12-22 00:56
-- 서버 버전: 5.6.26
-- PHP 버전: 5.5.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 데이터베이스: `smartcycle`
--

-- --------------------------------------------------------

--
-- 테이블 구조 `gameinfo`
--

CREATE TABLE IF NOT EXISTS `gameinfo` (
  `userID` varchar(64) NOT NULL,
  `totalDist` float NOT NULL DEFAULT '0',
  `totalCarl` float NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Game information';

--
-- 테이블의 덤프 데이터 `gameinfo`
--

INSERT INTO `gameinfo` (`userID`, `totalDist`, `totalCarl`) VALUES
('102523649613385934855', 0, 0),
('107793149660082792308', 61.84, 2.08),
('115184875995794652680', 4265.19, 49.88);

-- --------------------------------------------------------

--
-- 테이블 구조 `userinfo`
--

CREATE TABLE IF NOT EXISTS `userinfo` (
  `userID` varchar(64) NOT NULL,
  `nickName` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='User information';

--
-- 테이블의 덤프 데이터 `userinfo`
--

INSERT INTO `userinfo` (`userID`, `nickName`) VALUES
('102523649613385934855', '김태현'),
('107793149660082792308', '신호섭'),
('115184875995794652680', 'KANGWON LEE');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `gameinfo`
--
ALTER TABLE `gameinfo`
  ADD PRIMARY KEY (`userID`);

--
-- 테이블의 인덱스 `userinfo`
--
ALTER TABLE `userinfo`
  ADD PRIMARY KEY (`userID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
