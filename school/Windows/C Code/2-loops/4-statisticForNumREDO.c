/*
File: 4.1-statisticForNumREDO.c
Date: 2023-10-18 16:19
Author: Leon A.
File Description: ---

*/
#include<stdio.h>

int main(){
    int input = 0; //input 
    int counter = 0;
    int array1[1000] = {0};

    printf("\n Calculates some things for statistics (Max amount of numbers = 1000 [Integers])");
    while(input>=0){
        printf("\n Enter a number: ");
        scanf("%d", &input);
        array1[counter] = input;
        counter++;
    }

    //calculations
    int smallest = array1[0];
    int biggest = array1[0];
    float result = 0;
    counter = 0;
    while(array1[counter]>=0){
        result = result+array1[counter];

        if(array1[counter]<smallest){
            smallest = array1[counter];
        }
        if(array1[counter]>biggest){
            biggest = array1[counter];
        }
        counter++;
    }
    printf("\n Smallest number: %d\n Biggest number: %d \n The middle in the numbers is %.2f", smallest, biggest, result/counter);

    return 0;
}