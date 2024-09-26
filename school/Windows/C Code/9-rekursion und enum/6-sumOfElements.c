/*
File: 6-sumOfElements.c
Date: 11-03-2024  18:40
Author: Leon A.
File Description: ---

*/
#include<stdio.h>

int sum(int size, int arr[]);

int main(int argc, char* argv[]){
    int arr[] = {2, 3, 1, 6, 4}; //sum is 16

    printf("\n Sum is: %d", sum(sizeof(arr)/sizeof(arr[0]), arr));
    return 0;
}

int sum(int size, int arr[]){
    if(size == 0){
        return 0;
    }
    return arr[size-1] + sum(size-1, arr); //size -1 cuz arr starts at 0
}
