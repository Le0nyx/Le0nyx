#include<stdio.h>

int main(){
    int number = 0;
    printf("\n Remember to read the binary bottom up.\n Enter a number to see it in binary: ");
    scanf("%d", &number);
    
    int a[10],n,i; 
    n = number;  
    for(i=0;n>0;i++)    {    
        a[i]=n%2;    
        n=n/2;    
    }    
    printf("\nBinary of Given Number is=");    
    for(i=i-1;i>=0;i--){    
        printf("%d",a[i]);    
    }   


    while(number>0){
        printf("\n %d : 2 = \t %.2f - %d", number, (float) number/2 ,number%2);
        number=number/2;
    } 

    return 0;
}