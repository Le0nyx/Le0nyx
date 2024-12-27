/*
File: 02_threadArray10.c
Date: 11-11-2024  08:39
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


int counter = 0;


void *thread1_function(void *x){
    printf("\n Thread [%d]: Hello from Thread! Counter: %d \n", *(int*)x, counter);
    counter++;
    pthread_exit(NULL);
}


int main(int argc, char* argv[]){
    pthread_t thread1[10];

    
    for(int i = 0;i<10;i++){
        if(pthread_create(&thread1[i], NULL, thread1_function, &i)){ fprintf(stderr, "Fehler beim erstellen von Thread %d \n", i); return 1; }
        sleep(1); // temporary
    }



    for(int i = 0;i<10;i++){
        pthread_join(thread1[i], NULL);
    }

    printf("\n Main: Alles zurück und am Beenden. \n");
    return 0;
}
