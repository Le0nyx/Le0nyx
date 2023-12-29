/*
File: 5-siebDesErsto.c
Date: 2023-10-19 08:10
Author: Leon A.
File Description: ---

*/
#include<stdio.h>

int main(){
    int max = 0;
    //input
    printf("This Programm makes primenumbers till a certain point via the \"Sieb des Eratostones\"\n Enter a maximum number (Integer): ");
    do{ //number cant be negative
        if(max<0){
            printf("\n Number can't be negative.\n Enter a new value: ");
        }
        scanf("%d", &max);
    }while(max<0);

    printf("\n\t2, \t3, \t5, \t7\n \t11, \t13"); //first numbers since it wouldnt include them on their own
    //calculations and output
    int array[max][10];
    for(int i = 0;i*10<max;i++){
        for(int j = 0;j<10;j++){
            if(i==0&&j==0){ //gets rid of the 1 it prints out at first (edge case)
                j=2;
            }
            array[i*10][j] = j+(i*10);
            if((array[i*10][j]%2==0) || (array[i*10][j]%3==0) || (array[i*10][j]%5==0) || (array[i*10][j]%7==0) || (array[i*10][j]%11==0) || (array[i*10][j]%13==0)){ //put flag option here if the requirements arent met (2,3,5,7) (goes till 200)
                array[i*10][j] = -1;
            }else{
                printf("\t%d, ", array[i*10][j]); 
            }
        }
        printf("\n");
    }

    return 0;
}