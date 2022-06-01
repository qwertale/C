create database odev4 on primary
(
	NAME = vtys_data,
	FILENAME = 'D:\odev4\vtysdata.mdf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)
log on
(
	NAME = vtys_log,
	FILENAME = 'D:\odev4\vtyslog.ldf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)