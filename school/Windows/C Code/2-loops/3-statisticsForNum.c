#include<stdio.h>

int main(){
    int isDone = 0;
    int chosen = 0;
    int array[101] = {0};
    printf("\n This programm is to make a statistic on the numbers from 0-100. Any numbers higher or lower wont be accepted (Integers). \n");
    
    //input for the numbers into array
    while(isDone == 0){
        do{ //GUI
            printf("\n------------------\n [1] Another number   [2] Go to statistic and close \n :");
            scanf("%d", &chosen);
        }while(chosen!=1 && chosen!=2);

        if(chosen==2){ //GUI end var
            isDone = 1;
        }

        if(chosen==1){
            int tmp1 = 0;
            if(tmp1>=0 && tmp1<=100){
                printf("\n Enter a number: ");
                scanf("%d", &tmp1);
                array[tmp1]++;
            }
        }
    }

    //print statistic here
    for(int i = 0; i<101;i++){
        if(array[i]!=0){
            printf("\n%d: ", i);
            for(int j = 0;j<=array[i];j++){
                printf("#");
                //printf("%d", array[i]);
                array[i]--;
            }
        }
    }


    return 0;
}