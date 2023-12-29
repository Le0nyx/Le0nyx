#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
     system("cls");
    srand(time(NULL));
    int number_range = 100;
    int array_size = 8; 
    int number_array[array_size];
    int temp1 = 0;
    int counter1 = 0;
    
    printf("\n Not sorted array: "); //declaring variables into array
    for(int i= 0;i<array_size;i++){ 
        number_array[i] = rand() % number_range;
        printf("%d, ", number_array[i]);
    }

    for(int i = 1;i<array_size;i++){ //insertion sort code
       
            temp1 = number_array[i]; //this is the number to move (temp1)
            counter1 = i-1;

            while(counter1 >= 0 && number_array[counter1] > temp1){
                        number_array[counter1 + 1] = number_array[counter1];
                        counter1--;
                    }
                    number_array[counter1 + 1] = temp1;
    }

    printf("\n \n The sorted array looks like this now: ");
    for(int i = 0;i<array_size;i++){ 
        printf("%d, ", number_array[i]);
    }

    return 0;
}