/*
File: tpUser.c
Date: 29-05-2024  15:11
Author: Leon A.
File Description:

cd "####"
Is a User for the tpServer.c
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
void quit_user(SHMEM arr[], int child_pid);


int main(int argc, char* argv[]){ //for each user
    printf("\n%d New User - ", getpid());

    MSGQ msgQ;
    // create keys of shm msgq and get their IDs/ sync with other with same key
    int msgQ_key = ftok("/bin/gcc", 'a');
    if (msgQ_key == -1) { perror("ftok"); exit(1); }
    printf("msgQ_key: %d ", msgQ_key);
    int msgQ_id = msgget(msgQ_key, 0666);
    if(msgQ_id < 0){ perror("msgget"); exit(1); }
    int shm_key = ftok("/bin/gcc", 'b');
    if(shm_key == -1){ perror("ftok"); exit(1); }
    int shmid = shmget(shm_key, sizeof(SHMEM) * MAX_USERS, SHM_RDONLY);
    if(shmid < 0){ perror("shmget"); exit(1); }
    printf("- shmid: %d\n", shmid);
    
    //attaching shmem
    SHMEM *users = shmat(shmid, 0, 0);
    if(users == (void*)-1){ perror("shmat"); exit(1); }
    
    
    //read in user data
    printf("\n\n Username:  ");
    char username[CHAR_MAX-15];
    fgets(username, CHAR_MAX-15, stdin); // READ IN STRING
    //scanf("%s", username);
    sprintf(msgQ.mtext, "%d : %s", getpid(), username);
    msgQ.mtype = 1;

    //send username to server
    if(msgsnd(msgQ_id, &msgQ, sizeof(msgQ.mtext), 0) < 0){ perror("msgsnd"); quit_user(users, getpid()); exit(1); }

    //wait until server registered user
    int counter = 0;
    while(4){
        if(counter >= MAX_USERS){ counter = 0; } // waits until user is registered
        if(users[counter].pid == getpid()){ break; }
        counter++;
    }


    //fork for recieving and sending
    int x = fork();
    if(x < 0){ perror("fork"); exit(1); }
    if(x == 0){ //recieve messages
        while(4){
            if(msgrcv(msgQ_id, &msgQ, sizeof(msgQ.mtext), getppid(), 0) < 0){ perror("msgrcv"); quit_user(users, getppid()); exit(1); } //recieve msg of parent since child has new pid
            printf("\n Recieved: %s \n", msgQ.mtext);
        }
        exit(0);
 
    }else{ //send messages
        while(4){
            //print users form shm here before writing each msg
            print_UsrStrct(users);

            printf("\n\n [0] Quit [1] Print updated Users \n\n Enter user PID to send: ");
            int send_pid = 2;
            scanf("%d", &send_pid);
            if(send_pid == 0){ quit_user(users, x); break; } // break as failsafe
            if(send_pid == 1){ print_UsrStrct(users); } // continue as failsafe

            //check if pid is in range of the users available here
            int user_exists = 0;
            for(int i = 0; i < MAX_USERS; i++){
                if(users[i].pid == send_pid){ user_exists = 1; break; }
            }
            if(user_exists == 0 && send_pid != 1){ printf("\n -----------------\nUser not found. Please try an available PID. \n"); }

            //send message
            if(send_pid != 1 && user_exists == 1){ 
                printf("\n\n Message: ");
                getchar();
                fgets(msgQ.mtext, CHAR_MAX, stdin); // READ IN STRING
                //scanf("%s", msgQ.mtext);
                msgQ.mtype = send_pid;
                if(msgsnd(msgQ_id, &msgQ, sizeof(msgQ.mtext), 0) < 0){ perror("msgsnd"); quit_user(users, x); exit(1); }
            }
        }
    }

    return 0;
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


void quit_user(SHMEM arr[], int child_pid){
    printf("\n\n QUITING USER... \n");
    for(int i = 0; i < MAX_USERS; i++){
        if(getpid() == arr[i].pid){
            arr[i].status = 0;
            break;
        }
    }
    kill(child_pid, SIGTERM);
    exit(0);
}
