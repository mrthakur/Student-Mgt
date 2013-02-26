-- phpMyAdmin SQL Dump
-- version 3.4.5deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 26, 2013 at 01:42 PM
-- Server version: 5.1.67
-- PHP Version: 5.3.6-13ubuntu3.9

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `vivek`
--

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE IF NOT EXISTS `student` (
  `s_name` varchar(512) NOT NULL,
  `s_name2` varchar(512) NOT NULL,
  `f_name` varchar(512) NOT NULL,
  `f_name2` varchar(512) NOT NULL,
  `m_name` varchar(512) NOT NULL,
  `m_name2` varchar(512) NOT NULL,
  `trade_sem` varchar(512) NOT NULL,
  `rollno` varchar(20) NOT NULL,
  `reg_no` varchar(20) NOT NULL,
  `address` varchar(512) NOT NULL,
  `phne_no` varchar(20) NOT NULL,
  `e_mail` varchar(512) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`s_name`, `s_name2`, `f_name`, `f_name2`, `m_name`, `m_name2`, `trade_sem`, `rollno`, `reg_no`, `address`, `phne_no`, `e_mail`) VALUES
('kzjshd', 'khaksdh', 'kjhasdh', 'kjhasdjh', 'kjhasdkjh', 'kjshdfkjh', '8', '56', '65', 'adasd', '564', 'aadasd');

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE IF NOT EXISTS `teacher` (
  `t_name` varchar(512) NOT NULL,
  `t_name2` varchar(512) NOT NULL,
  `dept` varchar(512) NOT NULL,
  `id` varchar(20) NOT NULL,
  `quali` varchar(512) NOT NULL,
  `sub_name` varchar(512) NOT NULL,
  `addr` varchar(512) NOT NULL,
  `phno` varchar(20) NOT NULL,
  `e_mail` varchar(512) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`t_name`, `t_name2`, `dept`, `id`, `quali`, `sub_name`, `addr`, `phno`, `e_mail`) VALUES
('sahil', 'rana', 'lecturer', '12', 'b.tech', 'computer prog', 'dasbdbaks', '123456789', 'sahildahs@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `User` varchar(512) NOT NULL,
  `Pass` varchar(512) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `User`
--

INSERT INTO `User` (`User`, `Pass`) VALUES
('vivek', 'pass');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
