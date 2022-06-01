#include <math.h>
#include <stdio.h>
 
void insertionSort(int arr[], int n)    // dizinin sıralanmasını sağlayan fonksiyon
{
    int i, key, j;   // ileride kullanılacak değişkenler oluşturuluyor.
    for (i = 1; i < n; i++) {   // i'den n'e kadar dönüyor  
        key = arr[i];  // key değişkeni dizinin i. elemanı olarak atanıyor.  
        j = i - 1;  // j'yi i'nin 1 eksiğine eşitliyor
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) { // j, 0'dan küçük eşitken ve dizinin j. elemanı key değişkeninden büyükken(dizinin o anki elamanıyla ondan bir önceki elemanını kıyaslamayı sağlıyor)
            arr[j + 1] = arr[j];    // dizinin j+1. elemanını dizinin j. elemanına eşitliyor
            j = j - 1;      // j, 1 azaltılıyor.
        }
        arr[j + 1] = key;   //dizinin j+1. değeri key değişkenine eşitleniyor
    }
}
 
void printArray(int arr[], int n)  // diziyi basmayı sağlayan fonksiyon
{
    int i; 
    for (i = 0; i < n; i++)  // i'den n'e kadar dönüyor
        printf("%d ", arr[i]);  // dizinin i. değerini ekrana bastırıyor
    printf("\n"); // işlemini tamamladıktan sonra alt satıra geçiriyor
}
 
 /*
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}
*/
