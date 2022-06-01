SELECT (select COUNT(ad) FROM calisanlar ) - (SELECT COUNT(DISTINCT ad) from calisanlar
join ikramiye on calisanlar.calisan_id = ikramiye.ikramiye_calisan_id )