/*
File: 2-recursion_introduction.c
Date: 11-03-2024  12:52
Author: Leon A.
File Description: Starting with recursion

*/
#include<stdio.h>

void printLines(int x);

int main(int argc, char* argv[]){

    printLines(5);

    return 0;
}
    

void printLines(int x) {
    if(x > 0) {
        printf("Zeile Nr. %d\n", x);
        printLines(x-1);
    }
}
