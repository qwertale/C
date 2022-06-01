select   sum(ikramiye.ikramiye_ucret) as max_ikramiye,calisanlar.ad, calisanlar.soyad, ikramiye_tarih
from birimler 
inner join calisanlar on birimler.birim_id = calisanlar.calisan_birim_id 
inner join ikramiye on calisanlar.calisan_id = ikramiye.ikramiye_calisan_id
group by  calisanlar.ad, calisanlar.soyad, ikramiye_tarih
