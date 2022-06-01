#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ORDER 3

typedef struct record { //kayıt değerinin tanımlanması.  
  int value;
} record;

typedef struct node {  //node'ların anahtar,pointer ve değerlerinin typedef sayesinde tanımlanması.
  void **pointers;
  int *keys;
  struct node *parent;
  bool is_leaf;
  int num_keys;
  struct node *next;
} node;

node *root;

int order = ORDER; 
node *queue = NULL;
bool verbose_output = false;


void enqueue(node *new_node); // sıralama için gerekli fonksiyon tanımı.


node *dequeue(void); // kuyruk için gerekli fonksiyonların tanımı 
int height(node *const root);
int pathToLeaves(node *const root, node *child);
void printLeaves(node *const root);
void printTree(node *const root);
void findAndPrint(node *const root, int key, bool verbose);
void findAndPrintRange(node *const root, int range1, int range2, bool verbose);
int findRange(node *const root, int key_start, int key_end, bool verbose,
        int returned_keys[], void *returned_pointers[]);
node *findLeaf(node *const root, int key, bool verbose);
record *find(node *root, int key, bool verbose, node **leaf_out);
int cut(int length);

record *makeRecord(int value);
node *makeNode(void);
node *makeLeaf(void);
int getLeftIndex(node *parent, node *left);
node *insertIntoLeaf(node *leaf, int key, record *pointer);
node *insertIntoLeafAfterSplitting(node *root, node *leaf, int key,
                   record *pointer);
node *insertIntoNode(node *root, node *parent,
           int left_index, int key, node *right);
node *insertIntoNodeAfterSplitting(node *root, node *parent,
                   int left_index,
                   int key, node *right);
node *insertIntoParent(node *root, node *left, int key, node *right);
node *insertIntoNewRoot(node *left, int key, node *right);
node *startNewTree(int key, record *pointer);
node *insert(node *root, int key, int value);


void enqueue(node *new_node) {            //Node oluşturma fonksiyonu.Eğer agaç boşsa yeni bir node eklenir ve sonraki gelen node null olarak gösterilir.
  node *c;                                
  if (queue == NULL) {
    queue = new_node;
    queue->next = NULL;
  } else {
    c = queue;
    while (c->next != NULL) {
      c = c->next;
    }
    c->next = new_node;
    new_node->next = NULL;
  }
}


node *dequeue(void) {    // Ağaçtan eleman silen fonksiyon
  node *n = queue;
  queue = queue->next;
  n->next = NULL;
  return n;
}


void printLeaves(node *const root) {  // yaprakları(elemanları) bastırma fonksiyonu.
  if (root == NULL) { // İlk önce root kontrol edilir eğer ağaçta root yoksa boştur.
    printf("Empty tree.\n");
    return;
  }
  int i;
  node *c = root;
  while (!c->is_leaf) // Yaprak olup olmadığı sorgulanır.
    c = c->pointers[0];
  while (true) {
    for (i = 0; i < c->num_keys; i++) {
      if (verbose_output)
        printf("%p ", c->pointers[i]);
      printf("%d ", c->keys[i]);
    }
    if (verbose_output)
      printf("%p ", c->pointers[order - 1]);
    if (c->pointers[order - 1] != NULL) {
      printf(" | ");
      c = c->pointers[order - 1];
    } else
      break;
  }
  printf("\n");
}

int height(node *const root) { // Ağacın yüksekliğini hesaplayan fonksiyon.
  int h = 0;
  node *c = root;
  while (!c->is_leaf) {
    c = c->pointers[0];
    h++;
  }
  return h;
}


int pathToLeaves(node *const root, node *child) { // Köke giden yolu bulan fonksiyon.
  int length = 0;
  node *c = child;
  while (c != root) {
    c = c->parent;
    length++;
  }
  return length;
}


void printTree(node *const root) { // Ağacı ekrana bastıran fonksiyon.
  node *n = NULL;
  int i = 0;
  int rank = 0;
  int new_rank = 0;

  if (root == NULL) { // Ağacın null olup olmadığı kontrolü.
    printf("Empty tree.\n");
    return;
  }
  queue = NULL;  // Eğer ağaç boşsa enqueue fonksiyonu ile oluşturur.
  enqueue(root);
  while (queue != NULL) {  // Ağaç boş değilse dequeue fonksiyonu ile eleman silinir.
    n = dequeue();
    if (n->parent != NULL && n == n->parent->pointers[0]) {
      new_rank = pathToLeaves(root, n);
      if (new_rank != rank) {
        rank = new_rank;
        printf("\n");
      }
    }
    if (verbose_output)
      printf("(%p)", n);
    for (i = 0; i < n->num_keys; i++) {
      if (verbose_output)
        printf("%p ", n->pointers[i]);
      printf("%d ", n->keys[i]);
    }
    if (!n->is_leaf) // Yaprak kontrolu yapılır.
      for (i = 0; i <= n->num_keys; i++)
        enqueue(n->pointers[i]);
    if (verbose_output) {
      if (n->is_leaf)
        printf("%p ", n->pointers[order - 1]);
      else
        printf("%p ", n->pointers[n->num_keys]);
    }
    printf("| ");
  }
  printf("\n");
}


void findAndPrint(node *const root, int key, bool verbose) { // Ağaçta node arama ve aranan node ekrana yazdırma fonksiyonu.
  // node *leaf = NULL; 
  record *r = find(root, key, verbose, NULL);  // find ile node aranır.
  if (r == NULL) // Eğer node null ise bulunamadı yazdırılır.
    printf("Record not found under key %d.\n", key);
  else // Node null değilse kayıt, anahtar ve değerler yazdırılır.
    printf("Record at %p -- key %d, value %d.\n",
         r, key, r->value);
}


void findAndPrintRange(node *const root, int key_start, int key_end,
             bool verbose) {   // Aralık bulma ve yazdırma fonksiyonu
  int i;
  int array_size = key_end - key_start + 1; // Dizinin boyutu bulunur.
  int returned_keys[array_size];
  void *returned_pointers[array_size];
  int num_found = findRange(root, key_start, key_end, verbose,
                returned_keys, returned_pointers);
  if (!num_found) 
    printf("None found.\n");
  else {
    for (i = 0; i < num_found; i++)
      printf("Key: %d   Location: %p  Value: %d\n",
           returned_keys[i],
           returned_pointers[i],
           ((record *)
            returned_pointers[i])
             ->value);
  }
}


int findRange(node *const root, int key_start, int key_end, bool verbose,
        int returned_keys[], void *returned_pointers[]) {  // Ağacın aralığını bulan fonksiyon. 
  int i, num_found; 
  num_found = 0;
  node *n = findLeaf(root, key_start, verbose); // findLeaf fonksiyonu çağrılır.
  if (n == NULL)
    return 0;
  for (i = 0; i < n->num_keys && n->keys[i] < key_start; i++)
    ;
  if (i == n->num_keys)
    return 0;
  while (n != NULL) { 
    for (; i < n->num_keys && n->keys[i] <= key_end; i++) {
      returned_keys[num_found] = n->keys[i];
      returned_pointers[num_found] = n->pointers[i];
      num_found++;
    }
    n = n->pointers[order - 1];
    i = 0;
  }
  return num_found;
}

node *findLeaf(node *const root, int key, bool verbose) { // Ağaçta sorgulanan yaprağın bulunması.
  if (root == NULL) { // Null sorgusu yapılır. 
    if (verbose)
      printf("Empty tree.\n");
    return root;
  }
  int i = 0;
  node *c = root;
  while (!c->is_leaf) {
    if (verbose) {
      printf("[");
      for (i = 0; i < c->num_keys - 1; i++)
        printf("%d ", c->keys[i]);
      printf("%d] ", c->keys[i]);
    }
    i = 0;
    while (i < c->num_keys) {
      if (key >= c->keys[i])
        i++;
      else
        break;
    }
    if (verbose)
      printf("%d ->\n", i);
    c = (node *)c->pointers[i];
  }
  if (verbose) {
    printf("Leaf [");
    for (i = 0; i < c->num_keys - 1; i++)
      printf("%d ", c->keys[i]);
    printf("%d] ->\n", c->keys[i]);
  }
  return c;
}

record *find(node *root, int key, bool verbose, node **leaf_out) { // Arama fonksiyonu.
  if (root == NULL) { // Null kontrolü yapılır.
    if (leaf_out != NULL) {
      *leaf_out = NULL;
    }
    return NULL;
  }

  int i = 0;
  node *leaf = NULL;

  leaf = findLeaf(root, key, verbose);

  for (i = 0; i < leaf->num_keys; i++)
    if (leaf->keys[i] == key)
      break;
  if (leaf_out != NULL) {
    *leaf_out = leaf;
  }
  if (i == leaf->num_keys)
    return NULL;
  else
    return (record *)leaf->pointers[i];
}

int cut(int length) { // Bölme fonksiyonu. 
  if (length % 2 == 0)
    return length / 2;
  else
    return length / 2 + 1;
}

record *makeRecord(int value) { //Yeni kayıt oluşturma.
  record *new_record = (record *)malloc(sizeof(record)); // Yeni kayıt için malloc ile bellekten yer ayırdı.
  if (new_record == NULL) { // Null kontrolü yapılır.
    perror("Record creation.");
    exit(EXIT_FAILURE);
  } else {
    new_record->value = value;
  }
  return new_record;
}

node *makeNode(void) { //Yeni düğüm oluşturma
  node *new_node;
  new_node = malloc(sizeof(node)); //  Düğüm için bellekten yer ayırdı.
  if (new_node == NULL) { // Null ise düğüm oluşturuldu
    perror("Node creation.");
    exit(EXIT_FAILURE);
  }
  new_node->keys = malloc((order - 1) * sizeof(int)); // Yeni düğümün anahtarı için malloc ile bellekten yer ayırdı.
  if (new_node->keys == NULL) { // Null kontrolü yapılır.
    perror("New node keys array."); // 
    exit(EXIT_FAILURE);
  }
  new_node->pointers = malloc(order * sizeof(void *)); // Düğüm için malloc ile bellekten yer ayırdı.
  if (new_node->pointers == NULL) { // Null kontrolü yapılır.
    perror("New node pointers array.");
    exit(EXIT_FAILURE);
  }
  new_node->is_leaf = false;
  new_node->num_keys = 0;
  new_node->parent = NULL;
  new_node->next = NULL;
  return new_node;
}

node *makeLeaf(void) { // Yaprak oluşturma fonksiyonu.
  node *leaf = makeNode(); 
  leaf->is_leaf = true; // is_leaf ile sorgu yapıyor.
  return leaf;
}

int getLeftIndex(node *parent, node *left) { // Sol index fonksiyonu.
  int left_index = 0; 
  while (left_index <= parent->num_keys &&
       parent->pointers[left_index] != left)
    left_index++; // while ile sol index varlığı tespit edilir ve yoksa left_index bir artırılır.
  return left_index;
}

node *insertIntoLeaf(node *leaf, int key, record *pointer) {
  int i, insertion_point;

  insertion_point = 0;
  while (insertion_point < leaf->num_keys && leaf->keys[insertion_point] < key)
    insertion_point++;

  for (i = leaf->num_keys; i > insertion_point; i--) {
    leaf->keys[i] = leaf->keys[i - 1];
    leaf->pointers[i] = leaf->pointers[i - 1];
  }
  leaf->keys[insertion_point] = key;
  leaf->pointers[insertion_point] = pointer;
  leaf->num_keys++;
  return leaf;
}

  node *insertIntoLeafAfterSplitting(node *root, node *leaf, int key, record *pointer) { // Bölmeden sonra yaprağa yerleştirme fonksiyonu.
  node *new_leaf;
  int *temp_keys;
  void **temp_pointers;
  int insertion_index, split, new_key, i, j;

  new_leaf = makeLeaf(); // makeLeaf fonksiyonu ile yaprak oluşturulur.

  temp_keys = malloc(order * sizeof(int)); // temp_keys için malloc ile bellekten yer ayrılır.
  if (temp_keys == NULL) { // Null kontrolü yapılır.
    perror("Temporary keys array.");
    exit(EXIT_FAILURE);
  }

  temp_pointers = malloc(order * sizeof(void *)); // Pointer için bellekten yer ayrılır.
  if (temp_pointers == NULL) {
    perror("Temporary pointers array.");
    exit(EXIT_FAILURE);
  }

  insertion_index = 0; 
  while (insertion_index < order - 1 && leaf->keys[insertion_index] < key)
    insertion_index++;

  for (i = 0, j = 0; i < leaf->num_keys; i++, j++) {
    if (j == insertion_index)
      j++;
    temp_keys[j] = leaf->keys[i];
    temp_pointers[j] = leaf->pointers[i];
  }

  temp_keys[insertion_index] = key;
  temp_pointers[insertion_index] = pointer;

  leaf->num_keys = 0;

  split = cut(order - 1); // cut fonksiyonu ile bölme yapılır.

  for (i = 0; i < split; i++) { // Bölüm kadar yapraklar ayrılır.
    leaf->pointers[i] = temp_pointers[i];
    leaf->keys[i] = temp_keys[i];
    leaf->num_keys++;
  }

  for (i = split, j = 0; i < order; i++, j++) {
    new_leaf->pointers[j] = temp_pointers[i];
    new_leaf->keys[j] = temp_keys[i];
    new_leaf->num_keys++;
  }

  free(temp_pointers);
  free(temp_keys);

  new_leaf->pointers[order - 1] = leaf->pointers[order - 1];
  leaf->pointers[order - 1] = new_leaf;

  for (i = leaf->num_keys; i < order - 1; i++)
    leaf->pointers[i] = NULL;
  for (i = new_leaf->num_keys; i < order - 1; i++)
    new_leaf->pointers[i] = NULL;

  new_leaf->parent = leaf->parent;
  new_key = new_leaf->keys[0];

  return insertIntoParent(root, leaf, new_key, new_leaf);
}

node *insertIntoNode(node *root, node *n,
           int left_index, int key, node *right) { // Düğüm ekleme yapan fonksiyon.
  int i;

  for (i = n->num_keys; i > left_index; i--) {
    n->pointers[i + 1] = n->pointers[i];
    n->keys[i] = n->keys[i - 1];
  }
  n->pointers[left_index + 1] = right;
  n->keys[left_index] = key;
  n->num_keys++;
  return root;
}

node *insertIntoNodeAfterSplitting(node *root, node *old_node, int left_index,
                   int key, node *right) { // bölmeden sonra düğümleri ekleme.
  int i, j, split, k_prime;
  node *new_node, *child;
  int *temp_keys;
  node **temp_pointers;

  temp_pointers = malloc((order + 1) * sizeof(node *)); // temp_pointers için malloc ile bellekten yer ayırdı.
  if (temp_pointers == NULL) {
    exit(EXIT_FAILURE);
  }
  temp_keys = malloc(order * sizeof(int)); // Bellekten yer ayırdı.
  if (temp_keys == NULL) {
    exit(EXIT_FAILURE);
  }

  for (i = 0, j = 0; i < old_node->num_keys + 1; i++, j++) {
    if (j == left_index + 1)
      j++;
    temp_pointers[j] = old_node->pointers[i];
  }

  for (i = 0, j = 0; i < old_node->num_keys; i++, j++) {
    if (j == left_index)
      j++;
    temp_keys[j] = old_node->keys[i];
  }

  temp_pointers[left_index + 1] = right;
  temp_keys[left_index] = key;

  split = cut(order); // cut fonksiyonu ile ağacı ikiye böldü
  new_node = makeNode(); // makeNode fonksiyonu ile yeni node oluşturdu.
  old_node->num_keys = 0;
  for (i = 0; i < split - 1; i++) { // eski node'ları geçiçi pointer ve anahtarlara atadı.
    old_node->pointers[i] = temp_pointers[i];
    old_node->keys[i] = temp_keys[i];
    old_node->num_keys++;
  }
  old_node->pointers[i] = temp_pointers[i];
  k_prime = temp_keys[split - 1];
  for (++i, j = 0; i < order; i++, j++) { // yeni node'ları geçiçi olarak atadı.
    new_node->pointers[j] = temp_pointers[i];
    new_node->keys[j] = temp_keys[i];
    new_node->num_keys++;
  }
  new_node->pointers[j] = temp_pointers[i];
  free(temp_pointers);
  free(temp_keys);
  new_node->parent = old_node->parent; // eski node'ları yeni node'lara atadı.
  for (i = 0; i <= new_node->num_keys; i++) {
    child = new_node->pointers[i];
    child->parent = new_node;
  }

  return insertIntoParent(root, old_node, k_prime, new_node);
}

node *insertIntoParent(node *root, node *left, int key, node *right) { 
  int left_index;
  node *parent;

  parent = left->parent;

  if (parent == NULL) // Null sorgusu yapıldı.
    return insertIntoNewRoot(left, key, right); // Yeni root ekleme fonksiyonu döndürüldü.

  left_index = getLeftIndex(parent, left); // sol indexleri atadı.

  if (parent->num_keys < order - 1)
    return insertIntoNode(root, parent, left_index, key, right);

  return insertIntoNodeAfterSplitting(root, parent, left_index, key, right);
}

node *insertIntoNewRoot(node *left, int key, node *right) { // Yeni root'ları ekleyen fonksiyon.
  node *root = makeNode(); // Node oluşturma fonksiyonu çağrıldı.
  root->keys[0] = key; 
  root->pointers[0] = left;
  root->pointers[1] = right;
  root->num_keys++;
  root->parent = NULL;
  left->parent = root;
  right->parent = root;
  return root;
}

node *startNewTree(int key, record *pointer) { // Yeni ağaç oluşturan fonksiyon.
  node *root = makeLeaf(); // yaprak oluşturma fonksiyonu çağrıldı.
  root->keys[0] = key; // anahtarları, pointerlar, parentları sorgulandı.
  root->pointers[0] = pointer;
  root->pointers[order - 1] = NULL;
  root->parent = NULL;
  root->num_keys++;
  return root;
}

node *insert(node *root, int key, int value) { // ekleme fonksiyonu oluşturuldu.
  record *record_pointer = NULL;
  node *leaf = NULL;

  record_pointer = find(root, key, false, NULL); // Null sorgusu yapıldı.
  if (record_pointer != NULL) {
    record_pointer->value = value;
    return root;
  }

  record_pointer = makeRecord(value);

  if (root == NULL)
    return startNewTree(key, record_pointer);

  leaf = findLeaf(root, key, false);

  if (leaf->num_keys < order - 1) {
    leaf = insertIntoLeaf(leaf, key, record_pointer);
    return root;
  }

  return insertIntoLeafAfterSplitting(root, leaf, key, record_pointer);
}



/*
int main() {
  node *root;
  char instruction;

  root = NULL;

  root = insert(root, 5, 33);
  root = insert(root, 15, 21);
  root = insert(root, 25, 31);
  root = insert(root, 35, 41);
  root = insert(root, 45, 10);

  printTree(root);

  findAndPrint(root, 15, instruction = 'a');
}

*/
