#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define ARRAY_SIZE 10

int main() {
    int arr[ARRAY_SIZE];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int pid1, pid2, pid3, status;
    srand(time(NULL)); // Seed für Zufallszahlen

    // Array mit Zufallszahlen füllen
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10;
        printf("%d \n", arr[i]);
    }
    printf("\n");

    // Erster Prozess
    pid1 = fork();
    if (pid1 == 0) {
        // Kindprozess 1
        for (int i = 0; i < 3; i++) {
            sum1 += arr[i];
        }
        printf("Summe der ersten 3 Zahlen: %d\n", sum1);
        exit(sum1);
    } else if (pid1 < 0) {
        // Fehler beim Forken
        perror("fork");
        exit(1);
    }

    // Zweiter Prozess
    pid2 = fork();
    if (pid2 == 0) {
        // Kindprozess 2
        for (int i = 3; i < 6; i++) {
            sum2 += arr[i];
        }
        printf("Summe der nächsten 3 Zahlen: %d\n", sum2);
        exit(sum2);
    } else if (pid2 < 0) {
        // Fehler beim Forken
        perror("fork");
        exit(1);
    }

    // Dritter Prozess
    pid3 = fork();
    if (pid3 == 0) {
        // Kindprozess 3
        for (int i = 6; i < 10; i++) {
            sum3 += arr[i];
        }
        printf("Summe der letzten 4 Zahlen: %d\n", sum3);
        exit(sum3);
    } else if (pid3 < 0) {
        // Fehler beim Forken
        perror("fork");
        exit(1);
    }

    // Warten auf alle Kindprozesse
    waitpid(pid1, &status, 0);
    sum1 = WEXITSTATUS(status);
    waitpid(pid2, &status, 0);
    sum2 = WEXITSTATUS(status);
    waitpid(pid3, &status, 0);
    sum3 = WEXITSTATUS(status);

    // Gesamtsumme berechnen und ausgeben
    int sum = sum1 + sum2 + sum3;
    printf("Gesamtsumme: %d\n", sum);

    return 0;
}
