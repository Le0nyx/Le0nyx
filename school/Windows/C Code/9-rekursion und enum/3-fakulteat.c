/*
File: 3-fakulteat.c
Date: 11-03-2024  12:57
Author: Leon A.
File Description: fakulteat in c with recursion

*/
#include<stdio.h>

int fakultaet(int x);

int main() {
    int a = 5;
    printf("Fakultaet von %d ist %d\n", a, fakultaet(a));
    return 0;
}


int fakultaet(int x) {
    if(x > 0) {
        return x * fakultaet(x-1);
    }else {
        return 1;
    }
}
