/*
File: 02_counterTogether.c
Date: 21-10-2024 08:21
Author: Leon A.
File Description: ---

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/wait.h> 

int main(int argc, char* argv[]) {
    int* counter;
    int last_counted = 0;

    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) { perror("shmget"); exit(-1); }
    counter = shmat(shm_id, NULL, 0);
    if (counter == (int*) -1) { perror("shmat"); exit(-1); }

    *counter = 0;

    int x = fork();
    if (x < 0) { printf("\n ERROR OCCURRED FORKING"); return -1; }

    last_counted = *counter;

    if (x == 0) { // Child process
        sleep(1);
        for (int i = 0; i < 25; i++) {
            (*counter)++;
            last_counted = *counter;
            printf("\n Child Counter: %d \n", *counter);
            while (!(last_counted+1 == *counter)) {
                sleep(1);
            }
        }


    } else { // Parent process
        for (int i = 0; i < 25; i++) {
            (*counter)++;
            last_counted = *counter;
            printf("\n Parent Counter: %d \n", *counter);
            while (!(last_counted+1 == *counter)) {
                sleep(1);
            }
        }
    }

    shmdt(counter);
    shmctl(shm_id, IPC_RMID, NULL);
    return 0;
}
