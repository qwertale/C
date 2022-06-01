select  calisanlar.ad, calisanlar.soyad, birimler.birim_ad, unvan.unvan_calisan, ikramiye.ikramiye_ucret
from birimler 
inner join calisanlar on birimler.birim_id = calisanlar.calisan_birim_id 
inner join unvan on calisanlar.calisan_id = unvan.unvan_calisan_id
inner join ikramiye on calisanlar.calisan_id = ikramiye.ikramiye_calisan_id