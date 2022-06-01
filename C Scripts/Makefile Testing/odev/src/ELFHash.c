#include <stdio.h>
#include <inttypes.h>



unsigned int ELFHash(char* str, unsigned int length) {    // fonksiyon tanımlaması: str olarak karakter dizisi, lenght olarak str dizisinin uzunluğu
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;                                    // değişken tanımlamaları

	for (i = 0; i < length; str++, i++)                    // for fdöngüsü: dizi uzunluğu kadar döndür
	{
		hash = (hash << 4) + (*str);                        // str dizisinin başından 4 bit sola kaydırıp hash a ata

		if ((x = hash & 0xF0000000L) != 0)                  // eğer: x hash a eşit ise ve verilen adres boş değilse 
		{
			hash ^= (x >> 24);                               // ya da(XOR) operatörü ile hash ve x in 24 birim sağdaki elemanını işlemden geçir
		}

		hash &= ~x;                                         // ve(AND) operatörü ile hash ve x in değil(NOT) den geçirilmiş halini işlemeden geçir
	}

	return hash;                                           // hash i dön
}


/*
int main(){                                                ana işlem 

char* data = "jdfgsdhfsdfsd 6445dsfsd7fg/+bfjsdgf%$^";   girilen datanın tanımlanması

printf(" %s \n", data);                                    data yı ekrana bas                     

unsigned int value = ELFHash(data, 40);                   

printf("%d",  value);

return 0;
}

*/
