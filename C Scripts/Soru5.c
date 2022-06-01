#include <stdio.h>
int z = 1;
int x = 0;
int y = 0;
int calculator(int x, int y, int z );

int main(void){
    printf("Enter x variable\n");
    scanf("%d", &x);
    printf("Enter y variable\n");
    scanf("%d", &y);
    calculator(x, y, z);
}

int calculator(int x, int y, int z){
    z = z * x;
    y -= 1;
    if( y != 0 ){
        calculator(x, y, z);
    }else{
        printf("x^y = %d ", z);
        return 0;
    }

}