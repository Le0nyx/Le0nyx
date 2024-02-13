/*
File: 1-charcountFromFile.c
Date: 15-01-2024  12:20
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
    FILE *file_pointer;
    file_pointer = fopen(argv[1], "r");
    if(file_pointer == NULL){ //error handeling
        printf("\n argv[1] = %s", argv[1]);
        printf("\n ERROR OCCURED OPENING FILE OR NO/WRONG ARGUMENT GIVEN\n");
        return 0;
    }
    int temp = 0;
    int arr[26] = {0};

    while((temp = fgetc(file_pointer))!=EOF){  //eof is end of file
        if(temp>='A' && temp<='Z'){
            temp = temp-('A'-'a');
        }
        if(temp>='a' && temp<='z'){
            arr[temp-'a']++;
        }
    }

    for(int i = 0;i<26;i++){
        printf("\n %c: %d", 'a'+i, arr[i]);
    }
    fclose(file_pointer);    
    return 0;
}
