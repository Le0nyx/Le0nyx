/*
File: 04_mutexANDconditionVar.c
Date: 18-11-2024  08:16
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
#include<semaphore.h>
#include<time.h>

#define N 10

int arr[N];

pthread_mutex_t mutex;
pthread_cond_t condition1, condition2;


void* producer(void* arg);
void* consumer(void* arg);


int main(int argc, char* argv[]){
    pthread_t thread_consumer1, thread_consumer2, thread_producer; 

    for(int i = 0;i<N;i++){ arr[i] = -1; } // fill array with -1

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition1, NULL);
    pthread_cond_init(&condition2, NULL);

    printf("\n");
    if(pthread_create(&thread_producer, NULL, producer, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread Producer\n"); return -1; }
    if(pthread_create(&thread_consumer1, NULL, consumer, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread Consumer\n"); return -1; }
    if(pthread_create(&thread_consumer2, NULL, consumer, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread Consumer\n"); return -1; }


    pthread_join(thread_consumer1, NULL);
    pthread_join(thread_consumer2, NULL);
    pthread_join(thread_producer, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition1);
    pthread_cond_destroy(&condition2);
    printf("\n\n\n Code ends\n");
    return 0;
}


void* consumer(void* arg){
    sleep(1);
    int pos = -1;

    for(int i = 0;i<10;i++){ // can be replaced with infinite while or used as a for loop   for(int i = 0;i<10;i++)
        pos = -1; // reset pos
        pthread_mutex_lock(&mutex); 

        while(pos == -1){ // wait till new num arrives
            for(int i = 0;i<N;i++){
                if(arr[i] >= 0){
                    pos = i;
                    break;
                }
            }
            if(pos == -1) {
                pthread_cond_signal(&condition2);
                pthread_cond_wait(&condition1, &mutex);
            }
        }

        printf("\n Consumer %ld took %d at pos %d [%d]", pthread_self(), arr[pos], pos, pos);
        arr[pos] = -1;
        pthread_mutex_unlock(&mutex);
    }

}


void* producer(void* arg){
    int counter = 0;
    int pos = 0;

    for(int i = 0;i<20;i++){ // can be replaced with infinite while or used as a for loop   for(int i = 0;i<20;i++)
        usleep(100);
        pthread_mutex_lock(&mutex);

        // Wait if the array is full
        int isfull = 1;
        while (arr[pos] != -1) {
            pthread_cond_wait(&condition2, &mutex);
        }

        if (arr[pos] == -1) {
            arr[pos] = counter;
            printf("\n Wrote %d into [%d]", counter, pos);
            counter++;
            pos = (pos + 1) % N; // move to the next position
        }
        pthread_cond_signal(&condition1);
        pthread_mutex_unlock(&mutex);
    }
}
