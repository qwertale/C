#include <stdio.h>
//                  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5 
char abcArray[] = {"abcdefghijklmnopqrstuvwxyz"};
int gradeArray[] ={ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}; // sayaç dizisi
int grade;
int totalLetter = 0;
int wowelNumb = 0;
int consonantNumb = 0;
char charArray[] ={ "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical"
"operations automatically via computer programming.Modern computers have the ability to follow generalized sets"
"of operations, called programs.These programs enable computers to perform an extremely wide range of tasks.A"
"complete computer including the hardware, the operating system (main software), and peripheral equipment"
"required and used for full operation can be referred to as a computer system.This term may as well be used for a"
"group of computers that are connected and work together, in particular a computer network or computer cluster."
"Computers are used as control systems for a wide variety of industrial and consumer devices.This includes simple"
"special purpose devices like microwave ovens and remote controls, factory devices such as industrial robots and"
"computer-aided design, and also general purpose devices like personal computers and mobile devices such as"
"smartphones.The Internet is run on computers and it connects hundreds of millions of other computers and their"
"users.Early computers were only conceived as calculating devices.Since ancient times, simple manual devices like"
"the abacus aided people in doing calculations.Early in the Industrial Revolution, some mechanical devices were built"
"to automate long tedious tasks, such as guiding patterns for looms.More sophisticated electrical machines did"
"specialized analog calculations in the early 20th century." };

int letterCounter(char charArray[]);
int howMany(int gradeArray[]);
int wowelCounter(int gradeArray[]);
int consonantCounter(int gradeArray[]);
int gradeFinder(int gradeArray[], char abcArray[]);

int main( void ){
    letterCounter(charArray);
    howMany(gradeArray);
    wowelCounter(gradeArray);
    consonantCounter(gradeArray);
    gradeFinder(gradeArray, abcArray);
    for(int i = 0;i <= 25;i++){
        printf("\ndizi elemanlari: %d = %d", i, gradeArray[i]);
    }
}


int letterCounter(char charArray[]){
for(int i = 0; charArray[i] != '\0'; i++){ 
    grade =charArray[i];
    switch(grade){
        case'A':
        case'a':
        gradeArray[0]++;
        break;

        case'B':
        case'b':
        gradeArray[1]++;
        break;

        case'C':
        case'c':
        gradeArray[2]++;
        break;

        case'D':
        case'd':
        gradeArray[3]++;
        break;

        case'E':
        case'e':
        gradeArray[4]++;
        break;
        
        case'F':
        case'f':
        gradeArray[5]++;
        break;

        case'G':
        case'g':
        gradeArray[6]++;
        break;

        case'H':
        case'h':
        gradeArray[7]++;
        break;

        case'I':
        case'i':
        gradeArray[8]++;
        break;

        case'J':
        case'j':
        gradeArray[9]++;
        break;

        case'K':
        case'k':
        gradeArray[10]++;
        break;

        case'L':
        case'l':
        gradeArray[11]++;
        break;

        case'M':
        case'm':
        gradeArray[12]++;
        break;

        case'N':
        case'n':
        gradeArray[13]++;
        break;

        case'O':
        case'o':
        gradeArray[14]++;
        break;

        case'P':
        case'p':
        gradeArray[15]++;
        break;

        case'Q':
        case'q':
        gradeArray[16]++;
        break;

        case'R':
        case'r':
        gradeArray[17]++;
        break;

        case'S':
        case's':
        gradeArray[18]++;
        break;

        case'T':
        case't':
        gradeArray[19]++;
        break;

        case'U':
        case'u':
        gradeArray[20]++;
        break;

        case'V':
        case'v':
        gradeArray[21]++;
        break;

        case'W':
        case'w':
        gradeArray[22]++;
        break;
    
        case'X':
        case'x':
        gradeArray[23]++;
        break;

        case'Y':
        case'y':
        gradeArray[24]++;
        break;

        case'Z':
        case'z':
        gradeArray[25]++;
        break;
        
        case'\n':
        case'\t':
        case' ':
        case'.':
        break;
    }
}
return 0;
}

int howMany(int gradeArray[]){
    for(int i = 0; i <= 25; i++){
        totalLetter += gradeArray[i];
    }
    printf("Letter number in the text is:%d\n",totalLetter);
    return 0;
}

int wowelCounter(int gradeArray[]){
    wowelNumb = gradeArray[0] +gradeArray[4] + gradeArray[8] + gradeArray[14] + gradeArray[20];
    printf("Total wowel letter number in the text is :%d\n",wowelNumb);
    return 0;
}

int consonantCounter(int gradeArray[]){
    consonantNumb =  totalLetter - wowelNumb;
    printf("Total consonant letter number in the text is :%d\n",consonantNumb);
    return 0;
}

int gradeFinder(int gradeArray[], char abcArray[]){
    int temp;
    printf("Enter a letter.\n");
    scanf("%s",temp);
    for(int i = 0;i <= 25; i++){         
        if(temp == abcArray[i]){ 
            printf("%s letter is %d times used.", temp, gradeArray[i]);
        }
    }
return 0;
}