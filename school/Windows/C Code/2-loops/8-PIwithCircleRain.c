/*
File: 8-PIwithCircleRain.c
Date: 26-10-2023  08:00
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int main(){
    double randomX = 0; //variables
    double randomY = 0;
    long long inCircle = 0;
    long long howOften = 10000000; //all Raindrops = howOften

    //Pi ca. = (4*tropfen im Viertelkreis) / Gesamtzahl der Tropfen
    srand(time(NULL)); //calculations r = 10 instead of 1

    for(int i = 0;i<100;i++){
        rand();
    }


    for(long long i = 0;i<howOften;i++){
        randomX = (double)rand() /RAND_MAX;
        randomY = (double)rand() /RAND_MAX;
        if((randomX*randomX+randomY*randomY)<=1.0){
            inCircle++;
        }
    }
    //Output
    printf("\n PI is aproxametly: %f", (double) (inCircle*4.0)/howOften);
    
    return 0;
}
