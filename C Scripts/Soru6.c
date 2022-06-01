#include <stdio.h>
#include <stdlib.h>

unsigned long long int fibonacciNumber( unsigned int number );
int K = 0; //numberOfCalls

int main( void ){
    unsigned long long int result;
    int X;  // girilen değer
    printf("Kaçıncı elemanın hesaplanacağını giriniz:");
    scanf("%d",&X);
    for( unsigned int number = 1; number <= X; number ++ ){
        result = fibonacciNumber( number );
        printf( "\nValue of the %u. fibonacci number:%llu\n", number, result );
        printf( "Number of calls:%d\n", K );
    }
    return 0; 
}

unsigned long long int fibonacciNumber( unsigned int number ){
    K += 1;
    if( number == 0 || number == 1 )
    {
    return number;
    }else{
        return fibonacciNumber( number - 1 ) + fibonacciNumber( number - 2 );
    }
}