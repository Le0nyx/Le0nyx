/*
File: 01_threadsFirst.c
Date: 11-11-2024  08:23
Author: Leon A.
File Description: ---

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
#include<pthread.h> 


void *thread1_function(void *args){
    printf("\n Thread 1: Hello from Thread!\n");
    pthread_exit(NULL);

}


int main(int argc, char* argv[]){
    pthread_t thread1;

    if(pthread_create(&thread1, NULL, thread1_function, NULL)){
        fprintf(stderr, "Fehler beim erstellen von Thread 1 \n");
        return 1;
    }


    pthread_join(thread1, NULL);
    printf("\n Main: Beide Threads haben ihre Ausführung beendet.\n");
    return 0;
}
