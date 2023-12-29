#include<stdio.h>

int strlen(char *str){
    int len = 0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

int main(){
    char str[] = "Hello there";
    int temp = strlen(str); //the \0 doesnt get counted
    printf("\n Length is: %d", temp);
    return 0;
} 
