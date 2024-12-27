/*
File: 06_testprep.c
Date: 02-12-2024  08:09
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

#define THREADS_NUMBER 3
#define ARRAY_SIZE 100
#define RANDOM_MAX 999  // starts at 0

pthread_t threadid[THREADS_NUMBER];
int counter = 0;

pthread_mutex_t lock_array;

void* sortArr(void* args);
void print_int_arr(int arr[], int size);


int main(int argc, char* argv[]){
    srand(time(NULL));

    int arr[ARRAY_SIZE];
    for(int i = 0;i<ARRAY_SIZE;i++){ arr[i] = rand()%RANDOM_MAX; }


    pthread_mutex_init(&lock_array, NULL);

    print_int_arr(arr, ARRAY_SIZE);
    for(int i = 0;i<THREADS_NUMBER;i++) { pthread_create(&threadid[i], NULL, sortArr, arr); }

    for(int i = 0;i<THREADS_NUMBER;i++) { pthread_join(threadid[i], NULL); }

    pthread_mutex_destroy(&lock_array);
    printf("\n\n");
    print_int_arr(arr, ARRAY_SIZE);

    return 0;
}


void* sortArr(void* args){
    int *arr = args;
    int temp = 0;

    while(counter < ARRAY_SIZE){
        pthread_mutex_lock(&lock_array);

        int smallestPos = counter;
        for(int i = counter + 1; i < ARRAY_SIZE; i++){ //important to start again at counter +1
            if(arr[i] < arr[smallestPos]){
                smallestPos = i;
            }
        }
        temp = arr[counter]; //swapping
        arr[counter] = arr[smallestPos];
        arr[smallestPos] = temp;

        counter++;

        pthread_mutex_unlock(&lock_array);
    }

}


void print_int_arr(int arr[], int size){
    for(int i = 0; i < size; i++) { printf("%d, ", arr[i]); }
}

