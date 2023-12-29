#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Alternate version:
make an variable for each like float 1 or so
make them float so if you divide the last digit of it that you have you can see if its exactly 1 or not
*/

void enter_to_continue(){
    char input[10];
    printf("\n --------------------\n Press Enter to continue... ");
    fflush(stdin);
    fgets(input, 10, stdin);
    system("cls");
}



int main() {
    enter_to_continue();
    //input
    printf("\n Geben Sie eine Integerzahl ein: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // convert and remove the end \0
    input[strcspn(input, "\n")] = '\0';
    
    // count all the ones
    int num = atoi(input);
    int count_ones = 0;
    while (num != 0) {
        if (num % 10 == 1) {
            count_ones++;
        }
        num /= 10;
    }
    
    // Statistic of how often a number is
    int digit_counts[10] = {0};
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char digit = input[i];
        if (digit >= '0' && digit <= '9') {
            digit_counts[digit - '0']++;
        }
    }
    
    // output
    printf("Anzahl der Einsen in der Zahl: %d\n", count_ones);
    
    printf("Statistik ueber die Haeufigkeit der Ziffern:\n");
    for (int i = 0; i < 10; i++) {
        printf("Ziffer %d kommt %d mal vor. \t", i, digit_counts[i]);
        for(int j = 0;j<digit_counts[i];j++){
            printf("#");
        }
        printf("\n");
    }
    
    printf("Ziffern, die oefter als einmal vorkommen: ");
    for (int i = 0; i < 10; i++) {
        if (digit_counts[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
}
