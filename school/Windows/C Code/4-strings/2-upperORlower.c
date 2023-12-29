/*
File: Untitled-1
Date: 20-12-2023  15:34
Author: Leon A.
File Description: 

Der Benutzer soll einen beliebigen String eingeben
können.
Der String wird wahlweise in alles Großbuchstaben oder
alles Kleinbuchstaben umgewandelt

Zusatz: Jeder Buchstabe nach einem Leerzeichen soll groß
geschrieben werden.

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    char str[100];
    printf("\n Enter a string: ");
    fgets(str, 100, stdin);

    printf("\n [1] for uppercase\n [2] for lowercase\n [3] for writing the first letter uppercase after every space\n [else] Invalid\n\n : ");
    int choice = 0;
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("\n The string in uppercase is: %s", strupr(str));
    }else if(choice == 2){
        printf("\n The string in lowercase is: %s", strlwr(str));
    }else if(choice == 3){
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            if(str[i] == ' '){
                str[i+1] = str[i+1]+('A'-'a');
            }
        }
        printf("\n The string with the first letter after every space uppercase is: %s", str);
    }else{
        printf("\n Invalid input!");
    }
    return 0;
}