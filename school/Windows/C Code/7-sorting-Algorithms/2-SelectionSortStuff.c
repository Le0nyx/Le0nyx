#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    system("cls"); //declaration and cls
    srand(time(NULL));
    int array_size = 4;
    int number_array[array_size];
    int temp1 = 0;

    printf("\n Not sorted array: "); //declaring variables into array
    for(int i= 0;i<array_size;i++){
        number_array[i] = rand() % 100;
        printf("%d, ", number_array[i]);
    }
    
    for(int i=0;i<array_size;i++){ //selected swapping
        for(int j=0;j<array_size;j++){ 
           if(number_array[i]<number_array[j]){ //find the smallest (depending in which direction the > is looking it will print)
                temp1=number_array[i];
                number_array[i] = number_array[j];
                number_array[j]=temp1;
           }
        }//basic idea is go through the entire array and see if anything is bigger than the first and then switch and then ++
    }

    printf("\n \n The sorted array looks like this now: "); //sorted output
    for(int i = 0;i<array_size;i++){
        printf("%d, ", number_array[i]);
    }
    return 0;
}