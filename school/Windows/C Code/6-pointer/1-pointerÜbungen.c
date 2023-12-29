#include <stdio.h>
#include <string.h>


void swap(int *a, int *b); //übergibt die Adressen der Pointer

int main(){

int a=4, b=3; //deklaration von Variablen und Speicherplatz reserviert
printf("\n a= %d", a);
printf("\n b= %d", b);

swap(&a, &b); //übergibt die Adresse wo es im Speicher liegt

printf("\n a= %d", a);
printf("\n b= %d", b);

return 0;
}

void swap(int *a, int *b){ //nimmt die Value der übergebenen Adresse und swapped sie im Speicher
int temp = *a;
*a=*b;
*b= temp;
}

