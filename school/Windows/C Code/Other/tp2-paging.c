/*
File: tp2-paging.c
Date: 01-03-2024  08:50
Author: Leon A.
File Description: This program simulates the FIFO, LRU, Optimal, and Second Chance page algorithms

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function declarations
void fifoAlgorithm(int pages, int time_length, int array[pages+1][time_length]);
void lruAlgorithm(int pages, int time_length, int array[pages+1][time_length]);
void optimalAlgorithm(int pages, int time_length, int array[pages+1][time_length]);
void secondChanceAlgorithm(int pages, int time_length, int array[pages+1][time_length]);
void print_array(int pages, int time_length, int array[pages+1][time_length]);


int main(int argc, char* argv[]){
    srand(time(NULL));
    int pages = 4;
    int time_length = 17;
    int array[pages+1][time_length]; // Increase size of array by 1 for preferences in first row
    int preferences[time_length];

    // fill array with 0
    for(int i = 0; i < pages+1; i++){
        for (int j = 0; j < time_length; j++) {
            array[i][j] = 0;
        }
    }

    // preferences vom Aufgabenblatt (Excel)
    array[0][0] = 4;
    array[0][1] = 2;
    array[0][2] = 6;
    array[0][3] = 1;
    array[0][4] = 3;
    array[0][5] = 5;
    array[0][6] = 1;
    array[0][7] = 4;
    array[0][8] = 2;
    array[0][9] = 6;
    array[0][10] = 5;
    array[0][11] = 3;
    array[0][12] = 6;
    array[0][13] = 4;
    array[0][14] = 1;
    array[0][15] = 5;
    array[0][16] = 2;

    // random numbers for preferences
    /*
    for(int i = 0; i < time_length; i++) {
        array[0][i] = rand() % 10;
    }
    */

    printf("\n 1. FIFO \n 2. LRU \n 3. Optimal \n 4. Second Chance \n\nChoose the algorithm: ");
    int chosen = 0;
    scanf("%d", &chosen);

    // chose algorithm 
    switch(chosen){
        case 1:
            printf("FIFO Algorithm\n\n");
            fifoAlgorithm(pages, time_length, array);
            break;
        case 2:
            printf("LRU Algorithm\n\n");
            lruAlgorithm(pages, time_length, array);
            break;
        case 3:
            printf("Optimal Algorithm\n\n");
            optimalAlgorithm(pages, time_length, array);
            break;
        case 4:
            printf("Second Chance Algorithm\n\n");
            secondChanceAlgorithm(pages, time_length, array);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
            break;
    }

    print_array(pages, time_length, array);
    return 0;
}


void print_array(int pages, int time_length, int array[pages+1][time_length]){
    for(int i = 0; i < pages+1; i++){
        for(int j = 0; j < time_length; j++){
            printf("%3d ", array[i][j]);
        }
        printf("\n");
        if(i == 0){
            printf("\n");
        }
    }   
}


void fifoAlgorithm(int pages, int time_length, int array[pages+1][time_length]){
    int page_faults = 0;
    int page_index = 0;
    int page_queue[pages];
    // fill page queue with -1
    for(int i = 0; i < pages; i++){
        page_queue[i] = -1;
    }

    // go through the preferences
    for(int i = 0; i < time_length; i++){
        int page_number = array[0][i];
        int page_found = 0;

        // check if in queue
        for(int j = 0; j < pages; j++){
            if(page_queue[j] == page_number){
                page_found = 1;
                break;
            }
        }

        // If page is not found replace the oldest page in the queue
        if(!page_found){
            page_queue[page_index] = page_number;
            page_index = (page_index + 1) % pages;
            page_faults++;
        }

        // Update the array with the current page into queue
        for(int j = 1; j < pages+1; j++){
            array[j][i] = page_queue[j-1];
        }
    }

    printf("Page Faults: %d\n", page_faults);
}


void lruAlgorithm(int pages, int time_length, int array[pages+1][time_length]){
    int page_faults = 0;
    int page_index = 0;
    int page_queue[pages];
    int page_usage[pages];
    
    // initialize
    for(int i = 0; i < pages; i++){
        page_queue[i] = -1;
        page_usage[i] = 0;
    }
    
    // go through the preferences
    for(int i = 0; i < time_length; i++){
        int page_number = array[0][i];
        int page_found = 0;

        // Check if already in the queue
        for(int j = 0; j < pages; j++){
            if(page_queue[j] == page_number){
                page_found = 1;
                page_usage[j] = i + 1; // Update the page usage
                break;
            }
        }
        
        // page not found == replace least recently used page from queue
        if(!page_found){
            int least_recently_used = 0;
            for (int j = 1; j < pages; j++) {
                if (page_usage[j] < page_usage[least_recently_used]) {
                    least_recently_used = j;
                }
            }
            
            page_queue[least_recently_used] = page_number;
            page_usage[least_recently_used] = i + 1; // Update the page usage
            page_faults++;
        }
        
        // fill array with current page queue
        for(int j = 1; j < pages+1; j++){
            array[j][i] = page_queue[j-1];
        }
    }
    
    printf("Page Faults: %d\n", page_faults);
}


void optimalAlgorithm(int pages, int time_length, int array[pages+1][time_length]){
    int page_faults = 0;
    int page_index = 0;
    int page_queue[pages];

    // initialize
    for(int i = 0; i < pages; i++){
        page_queue[i] = -1;
    }

    // go through preferences
    for(int i = 0; i < time_length; i++){
        int page_number = array[0][i];
        int page_found = 0;

        // if page already in queue
        for(int j = 0; j < pages; j++){
            if(page_queue[j] == page_number){
                page_found = 1;
                break;
            }
        }

        // if the page not found == replace page that will be used in future
        if(!page_found){
            int optimal_page_index = -1;
            int farthest_distance = -1;
            for(int j = 0; j < pages; j++){
                int distance = 0;
                for (int k = i + 1; k < time_length; k++) {
                    if(array[0][k] == page_queue[j]){
                        break;
                    }
                    distance++;
                }
                if(distance > farthest_distance){
                    farthest_distance = distance;
                    optimal_page_index = j;
                }
            }
            page_queue[optimal_page_index] = page_number;
            page_faults++;
        }

        // fill array with current page queue
        for(int j = 1; j < pages+1; j++){
            array[j][i] = page_queue[j-1];
        }
    }

    printf("Page Faults: %d\n", page_faults);
}


void secondChanceAlgorithm(int pages, int time_length, int array[pages+1][time_length]){
    int page_faults = 0;
    int page_index = 0;
    int page_queue[pages];
    int reference_bit[pages];
    
    // initialize
    for(int i = 0; i < pages; i++){
        page_queue[i] = -1;
        reference_bit[i] = 0;
    }
    
    // go through the time slots
    for(int i = 0; i < time_length; i++){
        int page_number = array[0][i];
        int page_found = 0;

        // check if the page already in queue
        for(int j = 0; j < pages; j++){
            if(page_queue[j] == page_number){
                page_found = 1;
                reference_bit[j] = 1; // reference bit to 1
                break;
            }
        }
        
        // page not found == replace page with reference bit 0
        if(!page_found){
            while(1){
                if(reference_bit[page_index] == 0){
                    page_queue[page_index] = page_number;
                    reference_bit[page_index] = 1; // reference bit to 1
                    page_index = (page_index + 1) % pages;
                    page_faults++;
                    break;
                }else{
                    reference_bit[page_index] = 0; // reference bit to 0
                    page_index = (page_index + 1) % pages;
                }
            }
        }
        
        // fill array with page queue
        for(int j = 1; j < pages+1; j++) {
            array[j][i] = page_queue[j-1];
        }
    }
    
    printf("Page Faults: %d\n", page_faults);
}