#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY 100
int main( void ){
    char charArray [ SIZEOFARRAY ] = { '\0' };
    printf( "Enter a word(no longer than 100 characters):" );
    scanf( "%s", charArray );
 
    int sizer = 0;
    for( size_t counter = 0; counter < SIZEOFARRAY; counter ++ ){
        if( charArray[ counter ] != '\0' ){
            sizer += 1;
        }
    }
    printf( "\nYour word's size is: %d",sizer );
    int wowel = 0 ;
    for( size_t counter = 0; counter < SIZEOFARRAY; counter ++ ){
        char temp = charArray[ counter ];
        if( temp == 'a' || temp == 'A' || temp == 'e' || temp == 'E' || temp == 'o' || temp == 'O' || temp == 'u' || temp == 'U' || temp == 'i' ){
            wowel += 1;
        }
    }
    printf( "\nYour word has %d wowel character.", wowel );
    printf( "\nYour word has %d consonant character.", ( sizer - wowel ) );

 return 0;
}