/*
File: 9-fillTwoDimArr.c
Date: 06-11-2023  12:18
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int lenX = 10, lenY = 10;
    int arr[lenX+1][lenY+1];

    for(int i = 0;i<=lenX;i++){ //input the numbers
        for(int j = 1;j<=lenY;j++){
            arr[i][j] = i*j;
            printf("%d* %d = %d \n", i, j, arr[i][j]);   //could also just make print here 
        }
        printf("\n");
    }

    srand((unsigned)time(NULL));
    int len2X = 7, len2Y = 13;
    int upperlimit = 1000, lowerlimit = 500;
    int arr2[len2X][len2Y];
    int greatestLine = 0, temp = 0, sum = 0;
    int sumOfEach[7];
    
    for(int i = 0;i<len2X;i++){ //input the numbers
        for(int j = 1;j<=len2Y;j++){
            arr2[i][j] = rand()%(upperlimit-lowerlimit)+lowerlimit;
            printf("%d, ", arr2[i][j]);
            temp = temp + arr2[i][j];
        }
        printf("\n");
        if(temp>sum){ //see what the greatest Line summ is and replace if needed
            sum = temp;
            greatestLine = i;
        }
        sumOfEach[i] = temp;
        temp = 0; //set back to 0 for next line
    }

    printf("\n---------------- \nSumme von jeweiligen Linie:");
    for(int i = 0;i<len2X;i++){
        printf("\n%d: %d", i+1, sumOfEach[i]);
    }

    printf("\nDie Zeile mit der groessten Summe ist die %d. Zeile. \n\n", greatestLine+1);
    return 0;
}