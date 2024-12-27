/*
File: 01_monitor_first.c
Date: 04-12-2024  15:22
Author: Leon A.
File Description: ---


Zugriff auf eine geteilte Ressource (z.B. gemeinsamer Zähler) mithilfe von Monitoren in C syncrhonisiert
Das Programm sollte drei Treads starten, von denen jeder de Zähler erhöht, wenn er auf die geteilte Ressource zugreift.
Die Threads sollen syncrhonisiert arbeiten, um Rennbedingungen und Dateninkonsistenzen zu vermeiden.

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
#include<semaphore.h>
#include<time.h>


typedef struct monitor_strct{
    int counter;
    pthread_mutex_t mutex;
}MONITOR;


MONITOR monitor1;



void *thread_func(void *args){
    for(int i = 0;i<10;i++){
        pthread_mutex_lock(&monitor1.mutex);
        monitor1.counter++;
        printf("\n %ld prints %d", pthread_self(), monitor1.counter);
        pthread_mutex_unlock(&monitor1.mutex);
    }

}



int main(int argc, char* argv[]){
    pthread_t thread[3];

    for(int i = 0;i<3;i++){ pthread_mutex_init(&monitor1.mutex, NULL); }
    for(int i = 0;i<3;i++){ pthread_create(&thread[i], NULL, thread_func, NULL); }

// -------------------------

    for(int i = 0;i<3;i++){ pthread_join(thread[i], NULL); }
    for(int i = 0;i<3;i++){ pthread_mutex_destroy(&monitor1.mutex); }
    
    return 0;
}
