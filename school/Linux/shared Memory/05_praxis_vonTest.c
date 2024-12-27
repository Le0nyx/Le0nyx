/*
File: 05_praxis_vonTest.c
Date: 04-11-2024  22:48
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

/*
Erstellen Sie ein C-Programm mit einem Vater- und zwei Kindprozessen. Der Vater legt die Nachricht "Hallo von Vater" im Shared Memory ab. 
Das erste Kind dreht die Nachricht um und schreibt sie zurück. Dann signalisiert es (SIGUSR1) dem zweiten Kind, das die umgedrehte Nachricht liest und ausgibt,
bevor es dem Vater mit SIGUSR2 signalisiert. Der Vater gibt anschließend die Meldung "Beide Kinder haben die Nachricht verarbeitet" aus und beendet das Programm.

Hinweis: Nur SIGUSR1, SIGUSR2 und Shared Memory zur Synchronisation verwenden; sleep und pause sind verboten. 
Beide Kinderprozesse müssen sofort aufeinanderfolgend erstellt werden.
*/

int flag = 0;

void signal_handler(){ if(flag == 0){ flag = 1; }else{ flag = 0; } }


int main(int argc, char* argv[]){
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);


    int shmid = shmget(ftok("05_praxis_vonTest.c", 1), sizeof(char)*250, 0666|IPC_CREAT);
    if(shmid < 0){ printf("\n ERRROR OCCURED \n"); return -1; }
    char* shared_memory = (char*)shmat(shmid, NULL, 0);

    int x = fork();
    if(x < 0){ printf("\n ERRROR OCCURED \n"); return -1; }
    
    if(x==0){
        printf("\n CHild 2\n");
        while(flag == 0){ usleep(40); }
        printf("\n%s", shared_memory);
        kill(getppid(), SIGUSR2);
        shmdt(shared_memory);
        exit(0);
    }else{
        int y = fork();
        if(y < 0){ printf("\n ERRROR OCCURED \n"); return -1; }

        if(y == 0){
            printf("\n CHild 1\n");
            while(flag == 0){ usleep(40); }
            int i = 0;
            int j = strlen(shared_memory) - 1;
            while(i < j){
                char temp = shared_memory[i];
                shared_memory[i] = shared_memory[j];
                shared_memory[j] = temp;
                i++;
                j--;
            }
            kill(x, SIGUSR1);

            shmdt(shared_memory);
            exit(0);
        }else if(x != 0 && y != 0){ // parent
            printf("\n Parent\n");
            strcpy(shared_memory, "Hallo von Vater");
            kill(y, SIGUSR1);
            while(flag == 0){ usleep(40); }
            printf("\n Beide Kinder haben die Nachricht verarbeitet \n");
            shmdt(shared_memory);
            shmctl(shmid, IPC_RMID, NULL);
        }
    }
    
    return 0;
}
