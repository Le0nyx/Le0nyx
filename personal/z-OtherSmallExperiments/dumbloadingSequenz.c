/*
File: dumbloadingSequenz.c
Date: 15-05-2024  16:06
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int load(int add_percent, char *preview_message);


int main(int argc, char* argv[]){
    int add_percent = 6;
    char *message = "Hello World is the code. Its sleeping rn so please wait till it wakes back up";

    while(load(add_percent, message) >= 0){}

    printf("\n\n Woke up\n");

    return 0;
}



int load(int add_percent, char *preview_message){
    static int percent = 0;
    percent += add_percent;
    #ifdef _WIN32
        system("cls"); //Win
    #else
        system("clear"); // Unix 
    #endif

    printf("\n\n\n%s \n\nStatus: [ ", preview_message);
    for (int i = 0; i < 100/4; i++)
    {
        if(i<percent/4){
            printf("#");
        }else{
            printf(".");
        }
    }
    printf(" ] %d%%/ 100%% \n", percent);
    sleep(1);
    return percent;
}
