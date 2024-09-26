/*
File: 4-queersumme.c
Date: 11-03-2024  13:04
Author: Leon A.
File Description: queersumme von zahlen berechnen

*/
#include<stdio.h>

int quersumme(int x);

int main(int argc, char* argv[]){
    int a = 10301;

    printf("\n Queersumme ist: %d", quersumme(a));
    return 0;
}


int quersumme(int x){
    if(x<=0){
        return 0;
    }
    return x%10 + quersumme(x/10);
}
