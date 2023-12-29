#include<stdio.h>
#include<stdlib.h>

int betrag(int a);

int main(){
    int a = 0;
    printf("\n Enter a num: ");
    scanf("%d", &a);
    printf("%d", betrag(a));
    return 0;
}

int betrag(int a){
    if(a<0){
        return -a;
    }else{
        return a;
    }
}
