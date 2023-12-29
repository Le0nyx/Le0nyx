#include<stdio.h>

int main(){

    //input and output
    char x = ' ';
    printf("\n \nEnter a symbol and the code looks if its in the alphabet or not: ");
    scanf("%c", &x);
    if((x >=65 && x<=90) || (x>=97 && x<= 122)){
        printf("\n In the Alphabet.");
    }else{
        printf("\n Not in the Alphabet");
    }
    printf("\n You entered: %c \n In ASCII it's at %d \n\n", x, x);

    return 0;
}