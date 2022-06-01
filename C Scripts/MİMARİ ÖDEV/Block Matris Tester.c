#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "sys/time.h"
#include <time.h>

struct timeval time_start;
struct timeval time_end;

#define TRIALS 4 // Deneme sayısı
#define MATRIX_SIZE 2048 // Matris boyutu

// A, B, C0 ve C1 adında matrisleri oluşturuyoruz
short A[MATRIX_SIZE][MATRIX_SIZE], B[MATRIX_SIZE][MATRIX_SIZE], C0[MATRIX_SIZE][MATRIX_SIZE], C1[MATRIX_SIZE][MATRIX_SIZE];

int matmul_sb(short C[MATRIX_SIZE][MATRIX_SIZE], short A[MATRIX_SIZE][MATRIX_SIZE], short B[MATRIX_SIZE][MATRIX_SIZE])
{ 
  int i, j, k;
  short Ctemp;
  // blok matris carpimi
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      Ctemp=0;
      for (k = 0; k < MATRIX_SIZE; k++) {
        Ctemp += A[i][k] * B[k][j];
      }
      C[i][j]=Ctemp;
    }
  }
  return 0;
}

int matrix_mul(short C1[MATRIX_SIZE][MATRIX_SIZE], short A[MATRIX_SIZE][MATRIX_SIZE], short B[MATRIX_SIZE][MATRIX_SIZE])
{
    int bi=0, bj=0, bk=0, i=0, j=0, k=0;

    int blokSize=(MATRIX_SIZE/1); // 2048'lik matris 256 için 8'e, 512 için 4'e, 1024 için 2'ye bölünür.
    
    for(bi=0; bi<MATRIX_SIZE; bi+=blokSize){
        for(bj=0; bj<MATRIX_SIZE; bj+=blokSize){
            for(bk=0; bk<MATRIX_SIZE; bk+=blokSize){
                for(i=0; i<blokSize; i++){
                    for(j=0; j<blokSize; j++){
                        for(k=0; k<blokSize; k++){
                            C1[bi+i][bj+j] += A[bi+i][bk+k]*B[bk+k][bj+j];
                        }
                    }
                }
            }
        }
    }
}

int randMat( short A[MATRIX_SIZE][MATRIX_SIZE] ) 
{
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      A[i][j] = rand() % 6;
    }
  }
  return 0;
}

int main(void){
  randMat(A);         
  randMat(B);

  // denisken tanimlamalari
  int trial, block_size;
  double execution_time2 = 0, ortalama_zaman1 = 0, ortalama_zaman2 = 0;

  //Her blok boyutu icin TRIALS sayıda deneme calistirilir
  for (trial = 0; trial < TRIALS; ++trial)
  {
    // Sonucun yazılacağı matrisleri sıfır ile dolduruyoruz.
    memset(C0, 0, sizeof(short) * MATRIX_SIZE * MATRIX_SIZE);
    memset(C1, 0, sizeof(short) * MATRIX_SIZE * MATRIX_SIZE);

    // Test için standart matris çarpım kodunu çalıştırıyoruz
    
    gettimeofday(&time_start, NULL);    //ise ne zaman baslaniyor?
    matmul_sb(C0, A, B);
    
    gettimeofday(&time_end, NULL);     // is ne zaman bitiyor
    // zaman hesabi
    long long execution_time = 1000000LL
    * (time_end.tv_sec - time_start.tv_sec)
    + (time_end.tv_usec - time_start.tv_usec);
    execution_time2 = (double) (time_end.tv_sec-time_start.tv_sec) + (double) (time_end.tv_usec-time_start.tv_usec) * 1.e-6;
    ortalama_zaman1 += execution_time2;

    // ekrana yazdir
    printf("Duz matris hesabi zamani = %lld,\n", execution_time);
    printf("Duz matris hesabi zamani = %lf \n",execution_time2);
    // stdout ta bekleyen bir yazma işlemi varsa
    // hemen gerçekleştir.
    fflush(stdout);


    /********************************************************************
    * Sizin kodunuz
    * *******************************************************************/
    
    //ise ne zaman baslaniyor?
    gettimeofday(&time_start, NULL);
    matrix_mul(C1, A, B);
    // is ne zaman bitiyor
    gettimeofday(&time_end, NULL);
    // zaman hesabi
        execution_time = 1000000LL
    * (time_end.tv_sec - time_start.tv_sec)
    + (time_end.tv_usec - time_start.tv_usec);

    execution_time2 = (double) (time_end.tv_sec-time_start.tv_sec) + (double) (time_end.tv_usec-time_start.tv_usec) * 1.e-6;
    ortalama_zaman2 += execution_time2;
    // Ekrana yazdır
    printf("Blok matris hesabi zamani = %lld,\n", execution_time);
    printf("Blok matris hesabi zamani = %lf \n",execution_time2);
    fflush(stdout);
    // Eğer sonuç standart çarpmanın sonucundan farklı ise 
    // Ekrana Hata!!! yazdır.
    if (memcmp(C0,C1,sizeof(short)*MATRIX_SIZE*MATRIX_SIZE))
      printf("\nHata!!!\n");

    puts("");
  }
  printf("Duz matris hesabi zaman ortalamasi = %lf,\n", ortalama_zaman1 / TRIALS);
  printf("Blok matris hesabi zaman ortalamasi = %lf,\n", ortalama_zaman2 / TRIALS);

  return 0;
}
