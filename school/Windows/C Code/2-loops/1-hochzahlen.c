#include<stdio.h>

int main(){
    printf("\n Enter two numbers. The result is number1^number2. \n");
    int number1 = 0; //variables
    int number2 = 0;

    //input
    do{
    printf("\n Enter base number: ");
    scanf("%d", &number1);
    }while(number1<0);
    int original = number1; //to have the original for later

    do{
    printf("\n Enter ^number: ");
    scanf("%d", &number2);
    }while(number2<0);

    //calculations and exeptions
    if(number1==0&&number2==0){
        printf("\n Error. Both numbers can't be 0");
    }else if(number1==0&&number2>0){
        printf("\n Solution is 0");
    }else if(number1>0&&number2==0){
        printf("\n Solution is 1");
    }else{
        for(int i = 1;i<number2;i++){
            number1 = number1*original;
        }
        printf("\n The solution is %d", number1);
    }

    return 0;
}