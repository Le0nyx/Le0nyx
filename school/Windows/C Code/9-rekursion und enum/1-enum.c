/*
File: 1-enumExercises.c
Date: 11-03-2024  12:36
Author: Leon A.
File Description: Seeing how enum works

*/
#include<stdio.h>

int main(int argc, char* argv[]){
    typedef enum  num { TRUE=1, FALSE=0, NUM1 = 25, NUM2, NUM3 = -3, NUM4}num_t; //keeps on counting ++ from previouse if nothing given
    // enum are a constant and cannot be changed

    printf("enum: \n True is represented by: %d \n False is represented by: %d\n", TRUE, FALSE);
    num_t x = 5; //does not make it a constant 
    x = 3; 
    printf("\n x is equal to: %d\n Number1 = %d\n Number2 = %d\n Number3 = %d\n Number4 = %d\n", x, NUM1, NUM2, NUM3, NUM4);
    printf("\n Size of enum number %d and size of int %d are the same", sizeof(x), sizeof(int));
    return 0;
}
