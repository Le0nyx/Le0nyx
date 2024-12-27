/*
File: 06_raceConditionCreation.c
Date: 06-11-2024  15:39
Author: Leon A.
File Description: ---

Erstelle eine Race Condition zwischen zwei Prozessen, die Shared Memory dabei verwenden

*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h> 
#include<sys/wait.h> 


int main(int argc, char* argv[]){

    int shmid = shmget(ftok("06_raceConditionCreation.c", 1), sizeof(int), 0666|IPC_CREAT);
    if(shmid < 0){ printf("\n ERRROR OCCURED \n"); return -1; }
    int* shared_memory = (int*)shmat(shmid, NULL, 0);
    *shared_memory = 0;

    int x = fork();
    if(x < 0){ printf("\n ERRROR OCCURED \n"); return -1; }

    if(x==0){
        for(int i = 0;i<100;i++){
            (*shared_memory)++;
        }
        shmdt(shared_memory);
        exit(0);
    }else{
        while(*shared_memory < 100){
            if(*shared_memory%2 == 0){
                printf("\n Parent: %d \n", *shared_memory);
            }
        }
    }

    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
