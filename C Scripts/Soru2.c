#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double doubleArray [] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7, 88.8, 99.9 };
double array2[18] ;
int arraySize = 0;
double sumOfArray = 0.0f;
double avarageOfArray = 0.0f;
double varianceOfArray = 0.0f;
double deviationOfArray = 0.0f;

double calcMedian( double doubleArray[] );
double calcAverage( double doubleArray[] );
double calcVariance( double doubleArray[] );
double calcStdDeviation( double doubleArray[] ); 

int main(void){
    arraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    printf("Dizinin boyutu: %d\n", arraySize );
    calcMedian( doubleArray );
    calcAverage( doubleArray );
    calcVariance( doubleArray );
    calcStdDeviation( doubleArray );
    return 0;
}

double calcMedian( double doubleArray[] ){
    double medianOfArray =( doubleArray[8] +doubleArray[9]) / 2;
    printf("Median of array is: %f \n", medianOfArray );
}

double calcAverage( double doubleArray [] ){
    for(int i=0; i <= 17; i++){
        sumOfArray += doubleArray[i];
    }
    avarageOfArray = sumOfArray / arraySize;
    printf("Avarage of array is: %f \n", avarageOfArray );
    return 0.0f;
}

double calcVariance( double doubleArray[] ){
      double temp = 0.0f;
    for(int i= 0; i<= 17; i++){
        array2[i] = avarageOfArray - doubleArray[i];
    }

    for(int i= 0; i<= 17; i++){
        temp += array2[i] * array2[i];
    }
    varianceOfArray = temp / arraySize;
    printf("Variance of the array is: %f",varianceOfArray);
}

double calcStdDeviation( double doubleArray[] ){
  
    deviationOfArray = sqrt( varianceOfArray);
    printf("\nStandart deviation of the array is: %f",deviationOfArray);
}


