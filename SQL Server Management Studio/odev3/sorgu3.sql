select count(*), calisanlar.calisan_birim_id, birimler.birim_id, birimler.birim_ad 
from birimler inner join calisanlar on birimler.birim_id = calisanlar.calisan_birim_id 
group by calisanlar.calisan_birim_id, birimler.birim_id, birimler.birim_ad