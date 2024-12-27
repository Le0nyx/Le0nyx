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

void sig_handler(int signum){
    printf("\n Sighandler");

}

int main(int argc, char* argv[]){
    signal(SIGINT, sig_handler);   

    for(int i = 0;;i++){
        printf("\n Main loop");
        sleep(1);
    }
    return 0;
}
