create database odev5 on primary
(
	NAME = vtys_data,
	FILENAME = 'D:\odev5\vtysdata.mdf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)
log on
(
	NAME = vtys_log,
	FILENAME = 'D:\odev5\vtyslog.ldf',
	SIZE = 8MB,
	MAXSIZE = unlimited,
	FILEGROWTH = 10%
)