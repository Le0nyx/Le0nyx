#include<stdio.h>

int main(){
    float prize = 0;
    float fistPer = 0;
    float secondPer = 0;

    printf("\n Bitte tippe den Preis, Mehrwertsteuer und dann Aufschlag ein. \n");
    //input
    printf("\n Preis (Euro): ");
    scanf("%f", &prize);
    printf("\n Mehrwertsteuer (Prozent): ");
    scanf("%f", &fistPer);
    printf("\n Aufschlag (Prozent): ");
    scanf("%f", &secondPer);

    //calculating
    fistPer = fistPer/100;
    secondPer = secondPer/100;
    prize = prize+(prize*fistPer);
    prize = prize+(prize*secondPer);
    printf("\n Der Finale Preis ist %.2f", prize);

    return 0;
}