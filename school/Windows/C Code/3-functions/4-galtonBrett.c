/*
File: 5-galtonBrett.c
Date: 06-12-2023  15:28
Author: Leon A.
File Description: ---

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int boxITfell(int layers);
void print_stats(int layers, int stats[layers]);

int main(){
    srand(time(NULL));
    //variables
    int layers = 0, ball_counter = 0;
    //input
    printf("\n Please Enter how many layers you would like: \n");
    scanf("%d", &layers);
    printf("\n How many balls you want to throw in: \n");
    scanf("%d", &ball_counter);
    
    int stats[layers+1]; //calculations and initializing array
    for(int i = 0; i<layers+1;i++){ //setting all to 0 in the array
        stats[i] = 0;
    }
    for(int i = 0;i<ball_counter;i++){ //in what box it falls
        stats[boxITfell(layers)]++;
    }
    //output
    print_stats(layers, stats); //1 is the normal print    everything else is the diagramm
    return 0;
}


void print_stats(int layers, int stats[layers]){
    //normal array output
    for(int i = 0;i<layers+1;i++){
        printf("\n %d: %d", i, stats[i]);
    }
    printf("\n\n\n");
    //diagramm here
    for(int i = 0;i<layers+1;i++){
        printf("\n %d: ", i);
        for(int j = 0;j<stats[i];j++){
            printf("#");
        }
    }
}


int boxITfell(int layers){
    int rights = 0;
    for(int i = 0;i<layers;i++){
        if(rand()%2 == 1){
            rights++;
        }
    }
    return rights;
}
