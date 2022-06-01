create database odev3 on primary
(
	NAME = vtys_data,
	FILENAME = 'D:\odev3\vtysdata.mdf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)
log on
(
	NAME = vtys_log,
	FILENAME = 'D:\odev3\vtyslog.ldf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)