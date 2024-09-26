/*
File: turningOn_log.c
Date: 12-03-2024  15:59
Author: Leon A.
File Description: This code logs the time when the computer was turned on

*/
#include<stdio.h>
#include<time.h>

int main(int argc, char* argv[]){
    FILE* fp = fopen("turnOnLog.log", "a");
    if(fp == NULL){
        return 0;
    }
    time_t t = time(NULL);

    struct tm tm1 = *localtime(&t);
    fprintf(fp, "%d-%d-%d  %d-%d-%d - INFO : Turned on \n", tm1.tm_year + 1900, tm1.tm_mon + 1, tm1.tm_mday, tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
    fclose(fp);
    return 0;
}
