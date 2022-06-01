SELECT COUNT(unvan_calisan), unvan_calisan 
FROM unvan 
group by unvan_calisan 
having COUNT(unvan_calisan) > 1