/*
File: 05_revising3.c
Date: 30-09-2024  08:47
Author: Leon A.

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
#include<time.h>

/*
- Kids got the remote and dad tryna countdown to 0 from 30
- Kids arrive at 25 sec

- Der erste Kinderprozess sendet das Signal SIGINT, um den Countdown neu zu starten, was allerdings maximal einmal geschehen darf. 
- Der zweite Kinderprozess kann mit SIGUSR1 den Countdown pausieren, wobei diese Pause maximal dreimal erfolgen darf. 
- Der dritte Kinderprozess kann den Countdown, wenn er pausiert ist, mit dem Signal SIGUSR2 fortsetzen.


Da die Erstellung von Prozessen systemseitig Leistung erfordert, soll gewährleistet sein, dass
der Countdown trotzdem jede Sekunde exakt herunterzählt und keine Verzögerung durch das
Erstellen der Kinderprozesse entsteht. Der Countdown läuft also ununterbrochen weiter, auch
während die Kinderprozesse gestartet werden.
Das Programm soll sauber beendet werden, indem alle Prozesse ordnungsgemäß terminiert und alle
genutzten Ressourcen freigegeben werden.

ZUSATZ:
Zusätzlich soll das Programm ohne Verwendung von sleep() umgesetzt werden.
*/

int x = -1; // child to reset timer
int y = -1; // child to pause timer
int z = -1; // child to let timer continue

int kids_born = 0; //max once
int should_wait = 0;  // 1 if we should pause the countdown

long long time_remaining = 0; // remaining time after pause
long long current_time = 0; // current unix timestamp
long long time_goal = 0; // goal unix timestamp


void redo_child(){ // SIGINT
    printf("\n Resetting countdown by Child 1.\n");
    current_time = time(NULL);
    time_goal = current_time + 30;
    time_remaining = 30; // if gets reset during a wait
}

void wait_child(){ // SIGUSR1
    if (should_wait == 0) { // Ensure max 3 pauses
        should_wait = 1; // Set pause flag
        printf("\n Pausing countdown by Child 2. \n");
        time_remaining = time_goal - current_time; // Save the remaining time
    }
}

void unpause_child(){ // SIGUSR2
    if (should_wait == 1) { // Only resume if paused
        should_wait = 0; // Clear pause flag
        printf("\n Resuming countdown by Child 3. \n");
        current_time = time(NULL); // Update current time
        time_goal = current_time + time_remaining; // Adjust goal time
    }
}



int main(int argc, char* argv[]){
    srand(time(NULL));

    int shmid;
    int *shared_int;

    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) { perror("shmget failed"); exit(1); }
    shared_int = (int *) shmat(shmid, NULL, 0);
    if (shared_int == (int *) -1) { perror("shmat failed"); exit(1); }
    *shared_int = 0;


    current_time = time(NULL);
    time_goal = current_time + 30;
    while((time_goal - current_time) > 0){
        current_time = time(NULL);

        if(time_goal - current_time == 25 && kids_born == 0){ // birth kids here
            kids_born = 1;

            x = fork();
            if( x < 0){ printf("\n ERRROR OCCURED FORK 1"); return -1; }

            if(x != 0){
                y = fork();
                if( y < 0){ printf("\n ERRROR OCCURED FORK 2"); return -1; }
            }

            if(x != 0 && y != 0){
                z = fork();
                if( z < 0){ printf("\n ERRROR OCCURED FORK 3"); return -1; }
            }


            if(x == 0 && y != 0 && z != 0){ // child 1
                int was_redone = 0; //max once
                if(was_redone == 0){
                    was_redone = 1;
                    sleep(rand() % 9 + 3);
                    kill(getppid(), SIGINT); // redoes the timer
                }
                exit(0); // end kid1 after successfull redo
            }

            
            if(x != 0 && y == 0 && z != 0){ // child 2
                int count = 0;
                while(count < 3){
                    sleep(1);
                    if(*shared_int == 0){
                        count++;
                        sleep(rand() % 7 + 1); // Simulate random delay
                        kill(getppid(), SIGUSR1); // Signal parent to pause the timer
                        *shared_int = 1;
                    }
                }
                exit(0); // end kid2 after successfull pauses
            }

            if(x != 0 && y != 0 && z == 0){ // child 3
                int count = 0;
                while(count < 3){
                    sleep(1);
                    if(*shared_int == 1){
                        count++;
                        sleep(rand() % 9 + 2); // Simulate random delay
                        kill(getppid(), SIGUSR2); // Signal parent to unpause the timer
                        *shared_int = 0;
                    }
                }
                exit(0); // end kid3 after successfull unpauses
            }
        }


        if(x != 0 && y != 0 && z != 0){ // only parent process
            signal(SIGINT, redo_child);
            signal(SIGUSR1, wait_child);
            signal(SIGUSR2, unpause_child);

            while(should_wait == 1){ // pause the countdown
                sleep(1);
            }
        }
        printf("\n Countdown: %lld seconds \n", time_goal - current_time);

        sleep(1); // technically not needed since the timestamp is used, but reduces cpu usage drastically
    } // end of while loop

    while(wait(NULL) > 0); // wait for all children to finish

    shmdt(shared_int); // Detach from shared memory
    shmctl(shmid, IPC_RMID, NULL);
    printf("\n\n End of Code \n");
    return 0;
}
