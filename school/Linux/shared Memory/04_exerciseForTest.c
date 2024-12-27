/*
File: 04_exerciseForTest.c
Date: 23-10-2024  15:28
Author: Leon A.
File Description: ---

// countdown from 10 to 0 with 0 processes

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
    int shmid = shmget(ftok("04_exerciseForTest.c", 14), sizeof(int), IPC_CREAT | 0666);
    int* counter = (int* )shmat(shmid, NULL, 0);
    
    *counter = 10;

    int x = fork();
    if( x < 0){ printf("\n ERRROR OCCURED FORKING"); return -1; }


    if(x == 0){ // child
        while(*counter > 0){
            if(*counter % 2 == 0){
                printf("\n Counter: %d \n", *counter);
                (*counter)--;
            }
        }
        exit(0);
    }else{ // parent
        while(*counter > 0){
            if(!(*counter % 2 == 0)){
                printf("\n Counter: %d \n", *counter);
                (*counter)--;
            }
        }
    }
    printf("\n Done with Code \n");

    shmdt(counter);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
