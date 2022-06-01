import os
import hashlib
import requests

url='http://docker.hackthebox.eu:37707'
source_code = requests.get(url)

# siteden source_code u çeken
session = requests.Session()
B = session.get(url)

#dosyaya yazan
dosya = open("myfile.txt","w+")
dosya.write( B.text )
dosya.close()

#dosyadan şifreyi çeken
Gunter = os.popen(' cat myfile.txt | grep string |  cut -d ">" -f 4 | cut -d "<" -f 1 ' ).read()
Algos = Gunter[0:20]

#şifreyi md5 ile encrypt eden
D = hashlib.md5(Algos.encode()).hexdigest()
Mert = D[0:32]

#encrypti siteye post eden
payload = {'hash': '{}'.format(Mert)}
r = session.post(url , data={"hash":Mert})

#flag alan
print (r.text)
