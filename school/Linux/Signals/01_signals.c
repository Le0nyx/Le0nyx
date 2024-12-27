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


void signalchild(){
    printf("\n C recieved signal\n");
}

void signalparent(){
    printf("\n P Precieved signal\n");
}


int main(int argc, char* argv[]){
    int mainpid = getpid();
    int x = fork();
    if(x < 0){ printf("\n ERRROR OCCURED FORKING"); return 0; }


    if(x == 0){ //child
        signal(SIGUSR2, signalchild);
        printf("\n C waiting for signal\n");
        pause();
        kill(mainpid, SIGUSR1);

    }else{ // parent
        signal(SIGUSR1, signalparent);
        sleep(1);
        printf("\n P Sending Signal to child\n");
        kill(x, SIGUSR2);
        printf("\n P waiting for a response \n");
        pause();
    }

    return 0;
}
