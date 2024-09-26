/*
File: 5-fibonacci.c
Date: 11-03-2024  18:40
Author: Leon A.
File Description: calculate fibonacci number

*/
#include<stdio.h>

int fibonacci(int x, int y[]);

int main(int argc, char* argv[]){
    
    int fibonum[15] = {0, 1};

    fibonacci(sizeof(fibonum)/sizeof(fibonum[0]), fibonum);

    for(int i = 0; i < sizeof(fibonum)/sizeof(fibonum[0]); i++){
        printf("%d, ", fibonum[i]);
    }
    return 0;
}


int fibonacci(int x, int y[]){
    printf("\ncalled function: %d\n", x);
    if(x == 0){
        return 1;
    }
    if(x == 1){
        
        return 1;
    }
    fibonacci(x-1, y);
    //printf("x: %d\n", y[x-1]);
    y[x] = y[x-1] + y[x-2];
    return 1;
}
