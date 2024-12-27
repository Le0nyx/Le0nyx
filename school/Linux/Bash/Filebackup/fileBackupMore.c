/*
File: fileBackupMore.c
Date: 19-04-2024  08:32
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h> 
#include<sys/wait.h> 


int main(int argc, char* argv[]){
    int i;
    for (i = 1; i < argc; i++) {
        int pid = fork();
        if (pid == 0) {
            char* args[] = {"bash", "fileBackup.sh", argv[i], NULL};
            execvp(args[0], args);
            exit(0);
        }
        else if (pid < 0) { printf("Fork failed.\n"); exit(1); }
    }
    for (i = 1; i < argc; i++) { wait(NULL); }
    return 0;
}
