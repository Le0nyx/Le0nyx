#include<stdio.h>
#include<math.h>

int main(){
    //variables
    float len1 = 0;
    float len2 = 0;

    //input
    printf("\n Enter two lengths of a rectangle. Number range includes floats. \n");

    printf("\n Enter first lenght: ");
    scanf("%f", &len1);
    printf("\n Enter second lenght: ");
    scanf("%f", &len2);

    //calculating
    printf("\n Area of the rectangle: %.2f", (len1*len2));
    printf("\n Surround of the rectangle: %.2f", (2*len1+2*len2));
    printf("\n The Diagonal of the rectangle: %.2f \n\n", sqrt((len1*len1)+(len2*len2)));

    return 0;
}
