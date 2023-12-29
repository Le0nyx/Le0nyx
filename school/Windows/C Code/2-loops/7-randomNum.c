/*
File: 7-randomNum.c
Date: 25-10-2023  16:37
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>


int main(){
    srand(time(NULL)); //variables and initialization
    int a = 0;
    int arr[6] = {0};

    //writing into array
    for(int i = 0;i<100000;i++){
        arr[rand()%6]++;
    }

    //output
    for(int i = 0;i<6;i++){
        printf("\n %d: %d", i+1, arr[i]);
    }
    return 0;
}