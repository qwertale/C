#include <stdio.h>
#include <stdlib.h>

#define MAX 8   // Kullanıcıdan alınıp sonra da sort'lanacak olan dizinin maksimum boyutu
#define SWAP(x,y) t = x; x = y; y = t;  // Değerleri değiştirmek için gerekli kısım
int data[MAX];      //
int up = 1;         // recbitonic için gerekli olan data, up ve down değerleri deklere ediliyor.
int down = 0;       //


 
void compare(int i, int j, int dir)  // yöne göre kıyaslama yapmayı sağlayan fonksiyon
{
    int t;  // Tanımlanan SWAP işlemi için gerekli t değeri oluşturuluyor.

    if (dir == (data[i] > data[j]))     // dir'e yani yöne bağlı olarak (azalan - artan) koşul sağlandığında
    {
        SWAP(data[i], data[j]);         // SWAP işlemi gerçekleştirilr.
    }
}
                                                     
void bitonicmerge(int low, int c, int dir) // bitonik diziyi sıralayan fonksiyon
{
    int k, i;  // ilerde kullanılacak i ve k değişkenleri oluşturuluyor.
 
    if (c > 1)  // c, 1'den büyükse
    {
        k = c / 2;  // k değişkenine dizi boyunun yarısı atanıyor böylelikle k dizinin ortasına işaret etmeyi sağlayan bir değişken oluyor.

        for (i = low;i < low+k ;i++)        // belirlenen alt sınır ile bu alt sınıra eklenen k değleri arasında dönüyor.
            compare(i, i+k, dir);           // dir'e yani yöne bağlı olarak i ve i+k değerleri kıyaslanıyor gerekirse swap gerçekleşiyor.

        bitonicmerge(low, k, dir);          // Rekürsif bir çağrı yapılıp dizi ikiye bölünüp burada alt 
        bitonicmerge(low+k, k, dir);        // buradaysa üst kısmı yine compare edilip gerekirse swaplanıyor.                              
    }
}

void recbitonic(int low, int c, int dir)     // bitonic dizileri rekürsif olarak çağırıp sıralamayı sağlayan fonksiyon       
{
    int k;   // ilerde kullanılacak değişken oluşturuluyor
 
    if (c > 1)      // c, 1'den büyükse
    {
        k = c / 2;      // k değişkenine dizi boyunun yarısı atanıyor böylelikle k dizinin ortasına işaret etmeyi sağlayan bir değişken oluyor.
        recbitonic(low, k, 1);         // artan bir şekilde dizinin alt kısmını sıralar
        recbitonic(low + k, k, 0);   // azalan bir şekilde dizinin üst kısmını sıralar
        bitonicmerge(low, c, dir);      // bu alt dizileri birleştirir.
    }
}
/*

int data[MAX];      //
int up = 1;         // recbitonic için gerekli olan data, up ve down değerleri deklere ediliyor.
int down = 0;       //
 
int main()
{
    int i;
 
    printf("\nEnter the data");
    for (i = 0;i < MAX ;i++)
    {
        scanf("%d", &data[i]);
    }

    recbitonic(0, MAX, up);

    for (i = 0;i < MAX;i++)
    {
        printf("%d ", data[i]);
    }
}

*/
