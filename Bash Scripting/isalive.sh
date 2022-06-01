#!/bin/bash
for (( i = 1; i <= 255; i++ )) # for döngüsü ile i yi 255 kez döndürdük.
 do								      # 
   birmi=$(ping -c 1 192.168.1.$i | grep received | cut -d " " -f 4 ) # ping -c 1 ile IP ye ping attık,grep ile received in bılunduğu satırı aldık,cut -d ile boşluklarına ayırdık,   
   if [ $birmi -eq 1 ] # birmi değerinin -eq ile 1 e eşit olma durumunu sorguladık.   #devamı//-f 4 ile 3. ve 4. boşlık arasında ki 4. elemanı aldık ve bu değeri =$ ile birmi ye eşitledik.  
    then echo 192.168.1.$i # if doğru ise echo ile ip adresini bastırdık.
   fi # if kapatma operatörü.
 done



