#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status = 0;
    
    pid1 = fork(); //

    if (pid1 < 0) {
        fprintf(stderr, "Fehler beim Erzeugen des Kindprozesses 1.\n");
        exit(1);
    } else if (pid1 == 0) {
        // Parent 1
        printf("Ich bin der Kindprozess mit der PID: %d\n", getpid());
        sleep(1);
        
        pid2 = fork(); //

        if (pid2 < 0) {
            fprintf(stderr, "Fehler beim Erzeugen des Kindprozesses 2.\n");
            exit(1);
        } else if (pid2 == 0) {
            // Child 2
            printf("Ich bin der Kindprozess 2 mit der PID: %d\n", getpid());
            exit(0);
        } else {
            // Parent von Child 2
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Kindprozess 2 erfolgreich beendet.\n");
            } else if (WIFSIGNALED(status)) {
                printf("Kindprozess 2 wurde durch ein Signal beendet.\n");
            }
            exit(0);
        }
    } else {
        // Parent
        printf("Ich bin der Elternprozess mit der PID: %d\n", getpid());
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Kindprozess 1 erfolgreich beendet.\n");
        } else if (WIFSIGNALED(status)) {
            printf("Kindprozess 1 wurde durch ein Signal beendet.\n");
        }

        // Fork und warten auf Child 3
        while ((pid3 = fork()) < 0) {
            printf("Konnte Kindprozess 3 nicht erzeugen, versuche es erneut.\n");
            sleep(1);
        }

        if (pid3 == 0) {
            // Child 3
            printf("Ich bin der Kindprozess 3 mit der PID: %d\n", getpid());
            exit(0);
        } else {
            //Parent von Child 3
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Kindprozess 3 erfolgreich beendet.\n");
            } else if (WIFSIGNALED(status)) {
                printf("Kindprozess 3 wurde durch ein Signal beendet.\n");
            }
            exit(0);
        }
    }

    return 0;
}

