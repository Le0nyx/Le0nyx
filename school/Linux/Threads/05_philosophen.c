/*
File: 05_philosophen.c
Date: 20-11-2024  15:18
Author: Leon A.
File Description: 

5 philosophen in a circle. 
5 forks. 

each needs 2 forks to eat. 
it has cycles each one dies after 3/4 cycles (include in testing)

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

int currentCycle = 0;
int philosopherX[] = {1, 2, 3, 4, 5}; // total 5 starts at 0
int who_ate[] = {-1, -1};
int N = 100; // is amount of cycles

pthread_t philo[5];
pthread_mutex_t forks[5];


void* beingPhilo(void *x);

int main(int argc, char* argv[]){
    
    for(int i = 0;i<5;i++){ pthread_mutex_init(&forks[i], NULL); }

    for(int i = 0;i<5;i++){ pthread_create(&philo[i], NULL, beingPhilo, (void *)&philosopherX[i]); }   

    for(int i = 0;i<N;i++){
        if(currentCycle%3 == 0){
            who_ate[0] = 1; who_ate[1] = 3;
        }else if(currentCycle%3 == 1){
            who_ate[0] = 2; who_ate[1] = 4;
        }else if(currentCycle%3 == 2){
            who_ate[0] = 5; who_ate[1] = -1;
        }
        while(who_ate[0] != -1 || who_ate[1] != -1) { } // wait until all are done 
        currentCycle++;
    }

    for(int i = 0;i<5;i++){ pthread_mutex_destroy(&forks[i]); }
    for(int i = 0;i<5;i++){ pthread_join(philo[i], NULL); }

    return 0;
}


void* beingPhilo(void *x){
    int philoNum = *((int *)x);
    while(currentCycle < N){
        if(who_ate[0] == philoNum || who_ate[1] == philoNum && currentCycle < N){ 
            int leftFork = (philoNum-1);
            int rightFork = ((philoNum-1) + 1) % 5;

            pthread_mutex_lock(&forks[leftFork]);
            pthread_mutex_lock(&forks[rightFork]);

            printf("Philosopher %d is eating.\n", philoNum);
            //sleep(1); // simulate eating

            if(who_ate[0] == philoNum){ who_ate[0] = -1; }
            if(who_ate[1] == philoNum){ who_ate[1] = -1; }


            pthread_mutex_unlock(&forks[rightFork]);
            pthread_mutex_unlock(&forks[leftFork]);
        }
        
    }

}
