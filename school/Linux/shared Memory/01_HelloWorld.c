/*
File: 01_HelloWorld.c
Date: 21-10-2024  08:05
Author: Leon A.
File Description: ---


Nur EIN Prozess soll eine Shared memory anlegen
es der SHM hinzufügen und "Hello World " hineinschreiben
aus diesem wieder auslesen und mit printf ausgeben





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
    
    char* buffer = "Hello World!";

    int shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if(shm_id < 0){ perror("shmget"); exit(-1); }
    if( shmat(shm_id, buffer, 0) < 0){ perror("shmat"); exit(-1); }


    printf("\n Data in shared memory: %s  \n", buffer);

    shmdt(buffer);
    shmctl(shm_id, IPC_RMID, NULL);
    return 0;
}
