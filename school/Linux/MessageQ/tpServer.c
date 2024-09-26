/*
File: tpServer.c
Date: 29-05-2024  15:10
Author: Leon A.
File Description: 

cd "####"
Is a Registery server for the tpUser.c
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

#define MAX_USERS 100
#define CHAR_MAX 100


typedef struct msgQ_strct{
    long mtype;
    char mtext[CHAR_MAX];
}MSGQ;

typedef struct shmem_strct{
    char name[CHAR_MAX];
    int pid;
    int status;
}SHMEM;


//initialize functions
void print_UsrStrct(SHMEM arr[]);
void end_server(int msgQ_id, int shmid, SHMEM users[]);


int main(int argc, char* argv[]){ //registering the server
    printf("\n%d New Server - ", getpid());
    //ftok is used to generate a unique key by passing a file path and a char value that create a key

    MSGQ msgQ;
    // create keys of shm msgq and get their IDs/ sync with other with same key
    int msgQ_key = ftok("/bin/gcc", 'a');
    if (msgQ_key == -1) { perror("ftok"); exit(1); }
    printf("msgQ_key: %d ", msgQ_key);
    int msgQ_id = msgget(msgQ_key, IPC_CREAT | 0666);
    if(msgQ_id < 0){ perror("msgget"); exit(1); }
    int shm_key = ftok("/bin/gcc", 'b');
    if(shm_key == -1){ perror("ftok"); exit(1); }
    int shmid = shmget(shm_key, sizeof(SHMEM) * MAX_USERS, 0666 | IPC_CREAT);
    if(shmid < 0){ perror("shmget"); exit(1); }
    printf("- shmid: %d\n", shmid); 

    //attaching shmem
    SHMEM *users = shmat(shmid, 0, 0);
    if(users == (void*)-1){ perror("shmat"); exit(1); }
    //initiate users
    for(int i = 0; i < MAX_USERS; i++){ users[i].status = 0; }

    //register users and shutdown
    int x = fork();
    if( x < 0){ perror("fork"); exit(1); }
    if(x == 0){ //child
        // registering users
        
        while(4){ //child gets killed by parentP
            //register over type 1
            if(msgrcv(msgQ_id, &msgQ, sizeof(msgQ.mtext), 1, 0) < 0){ perror("msgrcv"); exit(1); }
            
            int free_slot = -1;
            for(int i = 0; i < MAX_USERS; i++){
                if(users[i].status == 0){
                    free_slot = i;
                    break; // exits for loop
                }
            }
            if(free_slot == -1){ printf("\n SERVER OVERLOADED. SHUTTING DOWN...\n"); kill(getppid(), SIGTERM); end_server(msgQ_id, shmid, users); exit(1); }
            char buffer[CHAR_MAX];
            strcpy(buffer, msgQ.mtext);
            users[free_slot].pid = atoi(strtok(buffer, ":")); //strtok returns a pointer for a string with the content till the symbol gets cut
            strcpy(users[free_slot].name, buffer + strlen(strtok(buffer, ":")) + 2); 
            users[free_slot].status = 1;

            //print users
            print_UsrStrct(users);
        }
 
        exit(1); //failsafe
    }else{ //parent
        int choice = 0;
        while(choice != 1){
            printf("\n\n [1] Server Shutdown\n [Else] Print updated Users\n\n");
            scanf("%d", &choice);
            if(choice == 1){ break; } // breaks out of while loop
            print_UsrStrct(users);
        }
    }
    //detach and remove msgq and shm here after shutdown initiated

    kill(x, SIGTERM); //kills child
    end_server(msgQ_id, shmid, users);
    return 0;
}


void end_server(int msgQ_id, int shmid, SHMEM users[]){
    printf("\n SERVER SHUTTING DOWN... \n");
    for(int i = 0; i < MAX_USERS; i++){
        if(users[i].status == 1){
            kill(users[i].pid, SIGTERM);
        }
    }
    shmdt(users);
    shmctl(shmid, IPC_RMID, NULL);
    msgctl(msgQ_id, IPC_RMID, NULL);
    exit(0);
}


void print_UsrStrct(SHMEM arr[]){
    printf("\n ----------------- \n");
    for(int i = 0; i < MAX_USERS; i++){
        if(arr[i].status == 1){
            printf("\n%d : %s", arr[i].pid ,arr[i].name);
        }
    }
    printf("\n\n");
}
