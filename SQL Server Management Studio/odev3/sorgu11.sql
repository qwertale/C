select  count(birimler.birim_ad), birim_ad
from birimler 
inner join calisanlar on birimler.birim_id = calisanlar.calisan_birim_id 
inner join unvan on calisanlar.calisan_id = unvan.unvan_calisan_id
group by birim_ad
having count(birimler.birim_ad) > 2
