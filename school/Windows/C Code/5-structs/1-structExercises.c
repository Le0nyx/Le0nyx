#include<stdio.h>

struct adresse {
        char name[15];
        char sirName[20];
        char idk[22];
    };

struct random {
    char wth[200];
    char ig[34];
    char ig2[34];
    char dontknow[222];
};



int main(){
    system("cls");

    //structs declarations
    struct adresse yourself = {.name="Leon", .sirName="Astner", .idk="heyo"};
    struct adresse other = {.idk="bloons", .sirName="de Luca", .name="Alessandro"};
    struct random ig;
    
    printf("%s %s and random is %s \n", yourself.name, yourself.sirName, yourself.idk);
    printf("%s %s and random is %s \n", other.name, other.sirName, other.idk);


    printf("\n Enter a Text or anything: ");
    fgets(ig.wth, 200, stdin); //is like scanf but gets everything, first where to then the lengh and then where it was input from
   
    printf("\n Enter a Number: ");
    fgets(ig.ig, 50, stdin);
    printf("\n Enter another number: ");
    fgets(ig.ig2, 50, stdin);
    printf("\n Enter another Text: ");
    fgets(ig.dontknow, 200, stdin);
    system("cls");

    printf("\nYou entered for the first text: %s", ig.wth);
    printf("\nYou entered for the first number: %s", ig.ig);
    printf("\nYou entered for the second number: %s", ig.ig2);
    printf("\nYou entered for the second text: %s", ig.dontknow);

    return 0;
}