/*
File: 7-palindrom_recursive.c
Date: 18-03-2024  11:37
Author: Leon A.
File Description: this code checks if a string is a palindrom using recursion

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int is_palindrom(char* str, int start, int end);

int main(int argc, char* argv[]){
    char str[MAX];
    printf("\n Please enter string: ");
    scanf("%s", &str);
    
    printf("\nIs palindrom (1 = yes / 0 = no): %d", is_palindrom(str, 0, strlen(str)-1)); //strlen -1 cuz \0
    return 0;
}


int is_palindrom(char* str, int start, int end){
    if(start >= end){
        return 1;
    }
    if(towlower(str[start]) != towlower(str[end])){ // tolower come from the ctype.h library
        return 0;
    }
    return is_palindrom(str, start+1, end-1);
}
