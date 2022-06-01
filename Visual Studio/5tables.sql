CREATE TABLE tFakulte(
fakulteID int PRIMARY KEY NOT NULL,
fakulteAd varchar(25)
);

CREATE TABLE tBolum(
bolumID int PRIMARY KEY NOT NULL,
bolumAd varchar(25), 
fakulteID int FOREIGN KEY REFERENCES tFakulte(fakulteID));

CREATE TABLE tOgrenci(
ogrenciID int PRIMARY KEY NOT NULL,
ogrenciAd varchar(25),
ogrenciSoyad varchar(25),
bolumID int FOREIGN KEY REFERENCES tBolum(bolumID));

CREATE TABLE tDers(
dersID int PRIMARY KEY NOT NULL,
dersAD varchar(25),
bolumID int FOREIGN KEY REFERENCES tBolum(bolumID)
);

CREATE TABLE tOgrenciDers(
ogrenciDersID int PRIMARY KEY NOT NULL,
ogrenciID int FOREIGN KEY REFERENCES tOgrenci(ogrenciID),
dersID int FOREIGN KEY REFERENCES tDers(dersID), 
yil varchar(20),
yariyil varchar(25),
vize int,
final int,
);