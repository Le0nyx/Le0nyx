/*
File: 03_Semaphoren.c
Date: 11-11-2024  09:07
Author: Leon A.
File Description: ---

Erstelle 3 Threads
Benutze Semaphoren
Ausgabe immer a b c


ZUSATZ: THreads können random Zeit schlafen



*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t sem_a, sem_b, sem_c;


void *thread_function_a(void *x) {
    sem_wait(&sem_a);
    sleep(rand()%7+2);
    printf("\na \n");
    sem_post(&sem_b);
    pthread_exit(NULL);
}

void *thread_function_b(void *x) {
    sem_wait(&sem_b);
    sleep(rand()%7+2);
    printf("\nb \n");
    sem_post(&sem_c);
    pthread_exit(NULL);
}

void *thread_function_c(void *x) {
    sem_wait(&sem_c);
    sleep(rand()%7+2);
    printf("\nc \n");
    sem_post(&sem_a);
    pthread_exit(NULL);
}



int main(int argc, char* argv[]) {
    srand(time(NULL));

    sem_init(&sem_b, 0, 0);
    sem_init(&sem_c, 0, 0);

    pthread_t thread[3];

    printf("\n");
    for(int i = 0;i<10;i++){
        if (pthread_create(&thread[0], NULL, thread_function_a, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread 0\n"); return -1; }
        if (pthread_create(&thread[1], NULL, thread_function_b, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread 1\n"); return -1; }
        if (pthread_create(&thread[2], NULL, thread_function_c, NULL)) { fprintf(stderr, "Fehler beim Erstellen von Thread 2\n"); return -1; }
    }
    sem_post(&sem_a);

    for (int i = 0; i < 3; i++){ pthread_join(thread[i], NULL); }

    printf("\n");
    sem_destroy(&sem_a);
    sem_destroy(&sem_b);
    sem_destroy(&sem_c);
    return 0;
}
