#include <stdio.h>
#include <stdlib.h>                         // Kamil Fatih Pehlivan 17060291
#include <pthread.h>
#include <time.h>

int m, n, p, q;   //rows and columns of first matrix
int c; // number of threads
#define MATRIX_DIMENSIONS 10
#define MATRIX_SIZE 100 // size must be bigger then rows*columns
#define THREAD_NUM 5
char first[MATRIX_SIZE], second[MATRIX_SIZE]; // total items in the matrises must be lower then 100
int matris1[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS], matris2[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS], multiply[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS]; // matrises rows and columns must be lower than 10 
char* filename1 = "matris1.txt";
char* filename2 = "matris2.txt";
pthread_t tid[THREAD_NUM];
clock_t begin[THREAD_NUM];
clock_t end[THREAD_NUM];

int reader(int matris[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS], char firstandsecond[MATRIX_SIZE],char* filename ); // declaration of the function who is reading the texts
void* calculator2(void* satirPtr); // declaration of the function who is calculate the matrises
int printer(); // declaration of the function who print the calculate matrises 

int main(int argc, char *argv[]){
    
    // printf(" karakter 1: %s 2: %s 3: %s 4: %s 5: %s \n ", argv[1], argv[2], argv[3], argv[4], argv[5]);
    m = atoi(argv[1]); // first matris's row
    n = atoi(argv[2]); // first matris's column
    p = atoi(argv[3]); // second matris's row
    q = atoi(argv[4]); // second matris's column
    c = atoi(argv[5]); // number of threads
    // printf("tamsayı %d + %d + %d + %d + %d", m, n, p, q, c);
    if(m < 1 || m > MATRIX_DIMENSIONS || n < 1 || n > MATRIX_DIMENSIONS || p < 1 || p > MATRIX_DIMENSIONS || q < 1 || q > MATRIX_DIMENSIONS ){
        printf(" Colum and rows must be bigger then 0 and lower than %d.\n", MATRIX_DIMENSIONS + 1);
        return -1;
    }else if( m != n){
        printf("First matrises column lenght and second matrise row lenght must be same for calculation.\n");
        return -1;
    }else if( c != m ){
        printf("The thread number must be same with first matrises column lenght and second matrises row lenght for calculation.\n");
        return -1;
    }

    reader(matris1, first, filename1); // fucntion who read matris1.txt 
    reader(matris2, second, filename2); // fucntion who read matris2.txt

    for(int i = 0; i < c; i++){          // c =  number of threads 
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        begin[i] = clock();
        pthread_create((&tid[ 0 ]), NULL, *calculator2, arg ); // creating thread
    }

    for(int j = 0; j < c; j++ ){ 
        pthread_join((tid[j]), NULL); // waiting the terminations of threads
        end[j] = clock();
    }
    for(int i = 0; i < c; i++){

        double time_spent = (double)(end[i] - begin[i]) *1000.0 / CLOCKS_PER_SEC;
        printf("proses %d's time: %f\n", i, time_spent);
    }

    printer();

    return 0;
}

int reader(int matris[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS], char firstandsecond[MATRIX_SIZE], char* filename ){
    FILE *fs;
    fs = fopen(filename, "r"); // opening the txt files as "only read"
    if (fs == NULL){
        printf("Dosya 1 açılamadı. %s");
        return -1;
    }       

        fgets(firstandsecond, (n*m), fs);
        int k = 0;
        for (int i  = 0; i < n; i++){ // firstandsecond[i] != '\0' 
            for (int j = 0; j < m; j++){ // firstandsecond[j] != '\0'
                char temp[0];
                temp[0] = firstandsecond[k];
                matris[i][j] =  atoi(temp);
                k++;
                //printf("%d ", matris[i][j]);
            }
        }
        //puts("");
    fclose(fs);
    return 0;
}

void* calculator2(void* satirPtr){
    int sum = 0;
    int satir = *(int *)satirPtr;
    for (int j = 0; j < n; j++) { // matris1[satir][j] != '\0' 
        for (int k = 0; k < m; k++) { // matris2[k][j] != '\0'  
          sum = sum + matris1[satir][k] * matris2[k][j];
        }
        multiply[satir][j] = sum;
        sum = 0;
      }
    satir = 0;
    return NULL;
}

int printer(){
    printf("Product of the matrices:\n");
    for(int i = 0; i< n; i++){ // multiply[i][0] != '\0'
        for(int j = 0; j < m; j++){ //  multiply[i][j] != '\0'
            printf("%d\t", multiply[i][j]);
        }
        printf("\n");
    }
}