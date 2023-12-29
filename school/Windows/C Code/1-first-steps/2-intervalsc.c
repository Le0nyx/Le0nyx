#include<stdio.h>

int main(){ //Interval Uebung
    int number = 0;
    printf("\n Choose a number and see if its in an interval or not \n : ");
    scanf("%d", &number);

    if(number<=6 && number>=4){
        printf("\n Inside Intervall one");
    }
    if((number>=0&&number<=2) || (number>=4 && number<=10)){
        printf("\n Inside Intervall two");
    }
    if(number<=(-1) || number>=1){
        printf("\n Inside Intervall three");
    }
    if((number<=(-4)) || (number>=0 && number<=2) || number>=4){
        printf("\n Inside Intervall four");
    }

    return 0;
}