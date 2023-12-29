#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int worst = 0;

int main(){
system("cls");
srand(time(NULL));
int array_size = 180;
int number_array[array_size];

printf("\n Not sorted array: "); //declaring variables into array
for(int i= 0;i<array_size;i++){
    number_array[i] = rand() % 100;
    printf("%d, ", number_array[i]);
    worst++;
}

//bubblesort

int temp1 = 0;
int switching = 0;

for(int i = 0;i<array_size;i++){
    for(int j = 0;j<array_size;j++){
        if(number_array[j]>=number_array[j+1]){ //swapping
            temp1 = number_array[j];
            number_array[j]=number_array[j+1];
            number_array[j+1]=temp1;
            switching++;
            worst++;
        }
         
    }
    
}
    printf("\n \n The sorted array looks like this now: ");
    for(int i = 0;i<array_size;i++){
        printf("%d, ", number_array[i]);
        worst++;
    }

    printf("\n Swapped %d time/s", switching);
    printf("\n Worst %d time/s", worst);

    return 0;
}


