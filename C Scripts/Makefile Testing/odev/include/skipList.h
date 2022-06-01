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

skiplist *skiplist_init(skiplist *list);
int rand_level();
int skiplist_insert(skiplist *list, int key, int value);
void skiplist_node_free(snode *x);
int skiplist_delete(skiplist *list, int key);
void skiplist_dump(skiplist *list);

