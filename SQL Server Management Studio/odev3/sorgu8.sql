select  max(calisanlar.maas) as max_maas, birimler.birim_ad, calisanlar.ad, calisanlar.soyad
from calisanlar  
join birimler on calisanlar.calisan_birim_id = birimler.birim_id
group by birimler.birim_ad, birimler.birim_ad, calisanlar.ad, calisanlar.soyad