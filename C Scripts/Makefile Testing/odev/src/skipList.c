
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SKIPLIST_MAX_LEVEL 6    //kullanıcıdan alınacak dizinin maksimum boyutu 

typedef struct snode {          //node'ların anahtar ve değerlerinin tanımlaması 
    int key;
    int value;
    struct snode **forward;
} snode;

typedef struct skiplist {       //skiplist'in hangi katmanda olduğunu anlamak için level'in, büyüklüğü için size'ın, header pointer değişkeni olarak tanımlanması
    int level;
    int size;
    struct snode *header;
} skiplist;

skiplist *skiplist_init(skiplist *list)
{
    int i;
    snode *header = (snode *)malloc(sizeof(struct snode));  //header pointer'ını kullanabilmek için malloc ile bellekten yer ayırdı
    list->header = header;                                  //list header'a header değerini atadı
    header->key = INT_MAX;                                  //key'e INT_MAX değerini atadı
    header->forward = (snode **)malloc(sizeof(snode*) * (SKIPLIST_MAX_LEVEL+1));    //
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {             //SKIPLIST_MAX_LEVEL+1 kadar döngüye girdi 
        header->forward[i] = list->header;                  //forward[i]'yi header' eşitliyor
    }

    list->level = 1;        //list level'e 1 değerini atadı
    list->size = 0;         //list size'a 0 değerini atadı

    return list;
}

int rand_level()
{
    int level = 1;
    while (rand() < RAND_MAX/2 && level < SKIPLIST_MAX_LEVEL)   //0 ve RAND_MAX arasında bir sayı üretilir ve level ile VE'lenir, bu değer
        level++;                                                //üretilen random sayı ve SKIPLIST_MAX_LEVEL arasındaysa döngüden cıkılır, level return edilir
    return level;
}

int skiplist_insert(skiplist *list, int key, int value)
{
    snode *update[SKIPLIST_MAX_LEVEL+1];                        //update adında -bir sonraki elemanı tutmak için- pointer oluşturulur
    snode *x = list->header;                                    //x pointer'ını header pointer'ıyla eşitlenir
    int i, level;
    for (i = list->level; i >= 1; i--) {                        //i level seviyesini tutar, 
        while (x->forward[i]->key < key)                        //x'in forward düğüm key'ine göre x'e update ataması yapılır
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[1];

    if (key == x->key) {
        x->value = value;
        return 0;
    } else {
        level = rand_level();       //random level üretilir ve levele eşitlenir
        if (level > list->level) {
            for (i = list->level+1; i <= level; i++) {  //i'ye list level'in 1 fazlası atanır,
                update[i] = list->header;
            }
            list->level = level;
        }

        x = (snode *)malloc(sizeof(snode));     //x pointer'ına malloc ile bellekten yer ayrılır
        x->key = key;
        x->value = value;
        x->forward = (snode **)malloc(sizeof(snode*) * (level + 1));    //bir sonraki tutulacak değer için yer ayrılır
        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];      //next level güncellenir ve değeri de x'e atanır
            update[i]->forward[i] = x;                  //bu sayede bir sonraki level'i belirlemiş olur
        }
    }
    return 0;
}

void skiplist_node_free(snode *x)        //bir sonraki node'a tahsis edilen belleği boşaltma işlemini gerçekleştirir ki 
{                                               //bu sayede gereksiz bellek harcanmaz
    if (x) {
        free(x->forward);
        free(x);
    }
}

int skiplist_delete(skiplist *list, int key)
{
    int i;
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;
    for (i = list->level; i >= 1; i--) {        
        while (x->forward[i]->key < key)        //keyleri kontrol edilir ve ona göre de silme işlemi yapılır
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)     //eğer sonraki düğüm update'i x den farklıysa 
                break;
            update[i]->forward[1] = x->forward[i];  //forward[1]'i forward[i] ye eşitler böylelikle
        }
        skiplist_node_free(x);  //x'te ayrılna belleği boşaltır

        while (list->level > 1 && list->header->forward[list->level] == list->header)
            list->level--;
        return 0;
    }
    return 1;
}

void skiplist_dump(skiplist *list)
{
    snode *x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}



/*
int main()
{
    int arr[] = {3, 6, 9, 2, 11, 1, 4}, i;
    skiplist list;
    skiplist_init(&list);

    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        skiplist_insert(&list, arr[i], arr[i]);
    }
    skiplist_dump(&list);

    printf("After Delete:------3--------9------\n");

    skiplist_delete(&list, 3);
    skiplist_delete(&list, 9);
    skiplist_dump(&list);

    return 0;
}

*/
