#include<stdio.h>

int main(){
    
    //input
    int height = 0;
    int age = 0;
    printf("\n Enter height and age of a tree. Max. age = 70 and Max. height is 20m \n Height (Meters): ");
    scanf("%d", &height);
    printf("\n Enter age (years): ");
    scanf("%d", &age);

    //calculations and output
    if(height>20 && age>70){
        printf("\n The tree should be cut down, since it is %d too tall and %d years too old. \n\n", (height-20), (age-70));
    }else{
        if(age<70){
            printf("\n The tree doesn't need to be cut down yet, because it's too young.");
            printf("\n The tree is %d years too young. \n\n", (70-age));
        }
        if(height<20){
            printf("\n The tree doesn't need to be cut down yet, because it's too small.");
            printf("\n The tree is %dm too small to be cut down.\n\n", 20-height);
        } 
    }

    return 0;
}