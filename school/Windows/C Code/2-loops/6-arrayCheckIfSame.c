/*
File: 6-arrayCheckIfSame.c
Date: 2023-10-18 15:25
Author: Leon A.
File Description: --- 

*/
#include<stdio.h>

void print_int_array(int array[], int arraysize){ //prints out an integer array
    printf("\n");
    for(int i = 0;i<arraysize;i++){
        printf("%d, ", array[i]);
    }
}

int main(){
    //AA1
    int array1[] = {1,3,2,4,5,6,7,15,9,0};
    int array2[] = {1,3,2,4,5,6,7,15,9,0};
    int array3[] = {1,3,2,4,5,6,7,1,9,0};
    int same = 0;
    
    printf("\n\nArray1: ");
    print_int_array(array2, sizeof(array2)/sizeof(int));
    printf("\n\nArray2: ");
    print_int_array(array2, sizeof(array2)/sizeof(int));
    printf("\n\nArray3: ");
    print_int_array(array3, sizeof(array3)/sizeof(int));

    int counter = 0; //same array
    while(counter<sizeof(array1)/sizeof(int) && same==0){ 
        if(array1[counter]!=array2[counter]){
            same = 1;
        }
        counter++;
    }
    if(same==0){ //output1
        printf("\n\narray1 and array2 are the same and same order\n");
    }else{
        printf("\n\narray1 and array2 are not the same and same order\n");
    }

    counter = 0; //diffrent array
    same = 0;
    while(counter<sizeof(array1)/sizeof(int) && same==0){
        if(array1[counter]!=array3[counter]){
            same = 1;
        }
        counter++;
    }
    if(same==0){ //output2
        printf("\n\narray1 and array3 have the same numbers and same order\n");
    }else{
        printf("\n\narray1 and array3 don't have the same numbers and same order\n");
    }

    //AA2
    same = 0;
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {6,5,4,3,2,1};
    printf("\n\nArr1: ");
    print_int_array(arr1, sizeof(arr1)/sizeof(int));
    printf("\n\nArr2: ");
    print_int_array(arr2, sizeof(arr2)/sizeof(int));

    for(int i = 0; i < sizeof(arr1)/sizeof(int);i++){
        for(int j = 0;j<sizeof(arr2)/sizeof(int);j++){
            if(arr1[i]==arr2[j]){
                same++;
            }
        }
    }
    if(same==sizeof(arr1)/sizeof(int)){ //output 3
        printf("\n Arr1 and Arr2 have the same content");
    }else{
        printf("\n Arr1 and Arr2 have not the same content");
    }

    return 0;
}