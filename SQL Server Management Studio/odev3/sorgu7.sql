select  calisanlar.ad, calisanlar.soyad,  unvan.unvan_calisan
from calisanlar  
inner join unvan on calisanlar.calisan_id = unvan.unvan_calisan_id
where unvan_calisan in ('Yönetici','Müdür')