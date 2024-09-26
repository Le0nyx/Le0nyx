/*
File: tp1-paging.c
Date: 09-02-2024  08:59
Author: Leon A.
File Description: ---

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Unicls();
void enter_to_continue();
void initilize_array(int array[], int array_size);
void remove_process(int array_size, int array[array_size]);
void print_bitmap(int array_size, int array[]);


int main(){
    int array_size = 256; //Enter the size of the bitmap
    int array[array_size+1]; //Bitmap
    int smallest_gap = array_size;
    initilize_array(array, array_size);

    int isDone = 0, option = 0, gap = 0, isFound = 0;
    int process_number = 0, process_length = 0;
    int position = 0, algorithm_chosen = 0;
    int current_each_gap = 0, position_smallest_gap = 0, next_fit_position = 0;

    
    while(isDone != 1){ //UI code
        Unicls(); //deletes previous screen
        printf("\n [1] Enter Process  [2] Remove Process  [3] Print Bitmap  [4] End Programm \n : ");
        scanf("%d", &option);
      
        if(option==1){ // prozess eintragen
            isFound = 0; //reactivates the loop
            printf("\n Enter a number for the Process: ");
            scanf("%d", &process_number);
            printf("\n Length of Process: ");
            scanf("%d", &process_length);
            printf("\n Choose an algorithm: \n [1] First Fit [2] Best Fit [3] Next Fit \n : ");
            scanf("%d", &algorithm_chosen);

//---------------------------------------------------------
            if(algorithm_chosen==1){ //First fit
                position= 0;
                gap = 0;

                while(isFound!=1){ //finds an free spot
                    if(array[position]!=0){
                        gap = 0;
                        position++;
                    }
                    if(position==array_size+1){
                        printf("\n Not enough space for this Process. \n Please remove one or enter a smaller one");
                        position = 0;
                        enter_to_continue();
                        isFound = 1;
                    }
                    if(array[position]==0){
                        gap++;
                        position++;
                    }
                    if(gap==process_length){ //placement of it
                        position = position-process_length;
                        for(int i = 0;i<process_length;i++){
                            array[i+position] = process_number;
                        }
                        position = process_length+position;
                        isFound = 1;
                    }
                }
            position = 0;
            gap = 0;
            }   
        }
//------------------------------------

        if (algorithm_chosen == 2) { //best fit
            position = 0;
            current_each_gap = 0;
            smallest_gap = array_size + 1;
            isFound = 0;
            //process_number
            while (position < array_size + 1) {
                if (array[position] == 0) {
                    current_each_gap++;
                    position++;
                } else {
                    if (current_each_gap < smallest_gap && current_each_gap >= process_length) {
                        smallest_gap = current_each_gap;
                        position_smallest_gap = position - smallest_gap;
                        isFound = 1; // update isFound flag
                    }
                    current_each_gap = 0;
                    position++;
                }
            }

            if (isFound != 0) { // process was placed
                for (int i = 0; i < process_length; i++) {
                    array[i + position_smallest_gap] = process_number;
                }
            } else { // suitable position not found
                printf("\n Not enough space for this Process. \n Please remove one or enter a smaller one");
                enter_to_continue();
            }
        }//best fit ends here
        //for some reason it puts it in twice into array
//-------------------------------------------

        if(algorithm_chosen==3){ //next fit
            while(isFound!=1){ //finds an free spot
                    if(array[next_fit_position]!=0){
                        gap = 0;
                        next_fit_position++;
                    }
                    if(next_fit_position==array_size+1){ //heres the only diffrence
                        next_fit_position = 0;
                    }
                    if(array[next_fit_position]==0){
                        gap++;
                        next_fit_position++;
                    }
                    if(gap==process_length){ //placement of it
                        next_fit_position = next_fit_position-process_length;
                        for(int i = 0;i<process_length;i++){
                            array[i+next_fit_position] = process_number;
                        }
                        next_fit_position = process_length+next_fit_position;
                        isFound = 1;
                    }   
                }
            gap = 0;
            }   //end of next fit
//---------------------------------
//---------------------------------
        if(option==2){ //prozess entfernen
            remove_process(array_size, array);
        }
        if(option==3){ //prozesse anzeigen
            print_bitmap(array_size, array);
        }
        if(option==4){ //closing programm
            isDone = 1;
        }
    }
    return 0;
} // END OF CODE


void Unicls(){
    #ifdef _WIN32
        system("cls"); //Win
    #else
        system("clear"); // Unix 
    #endif
}


void enter_to_continue(){ //creates a button just to continue if someone presses enter
    printf("\n -------------------------------------- \n Press Enter to continue... \n");
    fflush(stdin);
    getchar();
    fflush(stdin);
    Unicls();
}


void initilize_array(int array[], int array_size){
    for(int i = 0;i<array_size;i++){ //fill the array with all 0
        array[i] = 0;
    } 
}


void remove_process(int array_size, int array[array_size]){
    Unicls();
    int process_number = 0, process_length = 0;
    printf("\n Enter a Number to remove from the Processes: ");
    scanf("%d", &process_number);
    printf("\n How much of the process should be removed: ");
    scanf("%d", &process_length);
    for(int i = 0;i<array_size && process_length != 0;i++){
        if(array[i]==process_number){
            array[i] = 0;
            process_length--;
        }
    }
}


void print_bitmap(int array_size, int array[]){
    Unicls();       
    printf("\n The Bitmap looks like: \n \n ");
    for(int i = 0; i<array_size;i++){
        printf("%d, ", array[i]);
    }
    enter_to_continue();
}
