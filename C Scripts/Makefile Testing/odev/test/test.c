#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>


#include "bitonicSort.h"
#include "ELFHash.h"
#include "insertionSort.h"
#include "skipList.h"
#include "BPlusTree.h"


#define SKIPLIST_MAX_LEVEL 6    //kullanıcıdan alınacak dizinin maksimum boyutu

  int data[8];      // max = 8
  int up1 = 1;         // bitonic için gerekli olan data, up ve down değerleri deklere ediliyor.
  // int down = 0;

int main() {

  // ------------------------------------>>>> B+plus  başlangıcı

  printf(" \n ------------------------------------>>>> B+plus  başlangıcı \n");
  node *root;
  // char instruction;

  root = NULL;

  root = insert(root, 5, 33);
  root = insert(root, 15, 21);
  root = insert(root, 25, 31);
  root = insert(root, 35, 41);
  root = insert(root, 45, 10);

  printTree(root);

  findAndPrint(root, 15, true );   //instruction = 'a'
  // B+ plus test sonu

  // Bitonic başlangıç
  printf("\n------------------------------------>>>> Bitonic başlangıç \n");



     
 
    printf("\nEnter the data");
    for (int i = 0;i < 8 ;i++)
    {
        scanf("%d", &data[i]);
    }

    recbitonic(0, 8, up1);

    for (int i = 0;i < 8;i++)
    {
        printf("%d ", data[i]);
    }

    // bitonic bitiş

    //ELF hash başlangıç

    printf("\n------------------------------------>>>> ELF hash başlangıç \n");

    char* data = "jdfgsdhfsdfsd6445dsfsd7fg/*/+bfjsdgf%$^";  

    printf(" %s \n", data);                                                    

    unsigned int value = ELFHash(data, 40);   

    printf("%d",  value);

    // ELF Hash bitiş

    // insertion başlangıç

    printf("\n------------------------------------>>>> insertion başlangıç \n");

        int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);

    // insertion bitiş

    //skip list başlangıç

    printf("\n------------------------------------>>>> skiplist başlangıç \n");

    int arr2[] = {3, 6, 9, 2, 11, 1, 4};
    skiplist list;
    skiplist_init(&list);

    printf("\n Insert:--------------------\n");
    for (int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++) {
        skiplist_insert(&list, arr2[i], arr2[i]);
    }
    
    skiplist_dump(&list);
    
    printf("\n After Delete:------3--------9------\n");

    skiplist_delete(&list, 3);
    skiplist_delete(&list, 9);
    skiplist_dump(&list);

    // skip list bitiş

}
