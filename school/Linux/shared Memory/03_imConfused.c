/*
File: 03_imConfused.c
Date: 21-10-2024  08:38
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


void signalHandler(int sig) { return; }

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
    signal(SIGUSR1, signalHandler);

    if (x == 0) { // Child process
        last_counted = *counter;
        for (int i = 0; i < 20; i++) {
            (*counter)++;
            last_counted = *counter;
            if(i < 19){ pause(); }
        }
        exit(0);

    } else { // Parent process
        int y = fork();
        if( y < 0){ printf("\n ERRROR OCCURED"); return -1; }

        if(y > 0){ // parent
            last_counted = *counter;
            pause();
            for (int i = 0; i < 20; i++) {
                (*counter)++;
                last_counted = *counter;
                if(i < 19){ pause(); }
            }


        }else{ // kid 2
            int swap = 0;
            while (4) {
                usleep(40);
                if(last_counted != *counter){
                    last_counted = *counter;
                    printf("\n Counter: %d \n", *counter);
                    usleep(40);
                    if(swap == 0){
                        swap = 1;
                        kill(getppid(), SIGUSR1);
                    }else{
                        swap = 0;
                        kill(x, SIGUSR1);
                    }
                }
            }
            exit(0);
        }

    }

    shmdt(counter);
    shmctl(shm_id, IPC_RMID, NULL);
    return 0;
}

