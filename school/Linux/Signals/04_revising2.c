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

int x = 0;

void sighandler(){
    printf("\n P recieved");
}


void signal_end_all(){
    printf("\n Ending all processes\n");
    kill(x, SIGKILL);
    exit(0);
}


int main(int argc, char* argv[]){
    int mainpid = getpid();

    int fd[2];
    if(pipe(fd) < 0){ printf("\n ERRROR OCCURED"); return 0; }

    x = fork();
    if(x < 0){ printf("\n ERRROR OCCURED FORKING"); return 0; }


    if(x == 0){ //child
        close(fd[1]); //write


        int num;
        

        while(1){
            kill(getppid(), SIGUSR2);
            if(num == 10){ printf("\n Sekunde 10 fertig \n"); }
            read(fd[0], &num, sizeof(int));
            printf("\n Zeitstempel: _____ %d Sekunde:", num);

            for(int i = 1;i<=num;i++){
                printf(".");
            }
            printf("\n");
        } 
        

        close(fd[0]); //read
    }else{ // parent
        signal(SIGUSR1, signal_end_all);
        signal(SIGUSR2, sighandler);
        close(fd[0]); //read

        for(int i = 0;i<=10;i++){
            write(fd[1], &i, sizeof(int));
            sleep(1);
        }
        sleep(1);
        kill(getpid(), SIGUSR1);
        close(fd[1]); //write
    }

    return 0;
}
