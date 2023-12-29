/*
File: 11-playerGame.c
Date: 13-11-2023  12:49
Author: Leon A.
File Description: Small game similar to Snake.io, but without having a growing tail. Collect the O's to get points and avoid the Z's that remain on the field.
Controls are explained during the game itself

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<time.h>

// sign for playerfield ░ = 176 in ascii and 254 is the player = ■  (ASCII)
//WARNING: CODE DOESNT KNOW THE SPECIAL SIGNS ABOVE

void enterToContinue(){ //self explainatory
    printf("\n -------------------------------------- \n Press Enter to continue... \n");
    fflush(stdin);
    getchar();
    fflush(stdin);
}

int main(){
    //player introduction
    system("cls");
    printf("\nWelcome to Maze crawler. \n\nYou find yourself in an ever developing maze that keeps getting tighter. \nCollect as many O's as possible and avoid the Z's before you perish! \n\n\n");
    srand(time(NULL));
    int Xsize = 0, Ysize = 0; //playerfield variables
    
    do{ //Set Input beforehand to something valid
       if(Ysize>=40){
            printf("\n -------------- \nWrong Input\nPlease try again under 40");
       }
       printf("\nY-size of Playerfield: ");
        scanf("%d", &Ysize);
    }while(Ysize>=40);
    do{ //Set Input beforehand to something valid
        if(Xsize>=40){
             printf("\n -------------- \nWrong Input\nPlease try again ");
        }
        printf("\nX-size of Playerfield: ");
        scanf("%d", &Xsize);
    }while(Xsize>=40);

    //edge cases
    if(Xsize<0){
        Xsize = Xsize * -1;
    }
    if(Ysize<0){
        Ysize = Ysize * -1;
    }
    if(Ysize == 0 || Xsize == 0){
        return 0;
    }
    //actual game code and logic

    char playerfield[Xsize][Ysize]; //filling playerfield and initializing
    for(int i = 0;i<Xsize;i++){ 
        for(int j = 0;j<Ysize;j++){
            playerfield[i][j] = 176;
        }
    }
    playerfield[Xsize/2][Ysize/2] = 254; //set player in the middle of the field
    int gameOn = 0, life = 3, points = 0;
    char input = ' ';
    int currY = Xsize/2, currX = Ysize/2; //current position of the player
    int Opositions[Ysize];
    int temp = 0, keystrokes = 0; //(xsize+ysize)*2 is max for the O keystrokes

    while(gameOn==0){ //game starts
        if(keystrokes==1){ //after every set amount of keystrockes sets Z's WARNING needs to be 1 later to the O's otherwise wont do more
            for(int i = 0;i<Xsize;i++){
                if(rand()%2==1){
                    temp = rand()%Ysize;
                    if(playerfield[i][temp] != 254){ 
                        playerfield[i][temp] = 'Z';
                    }
                }
            }
        }
        if(keystrokes==((Xsize+3)*2)){  //amount of keystrokes here   AND   disapearing of previouse O's
            keystrokes = 0;
            for(int i = 0;i<Xsize;i++){
                if(playerfield[i][Opositions[i]] != 'Z' && playerfield[i][Opositions[i]] != 254){
                    playerfield[i][Opositions[i]] = 176;
                }
            }
        }
        if(keystrokes==0){ //set the O's after given amount of keystrokes that disapear later
            for(int i = 0;i<Xsize;i++){
                temp = rand()%Ysize;
                if(playerfield[i][temp] != 'Z' && playerfield[i][temp] != 254){
                    Opositions[i] = temp; 
                    playerfield[i][temp] = 'O';
                }
            }
            playerfield[currY][currX] = 254; //regive player position if lost
        }

        //print the entire field
        system("cls");
        printf("\nMaze crawler\n\nPoint of this game is to collect O's and avoid Z's\nO's and Z's spawn after a certain amount of keystrokes\n\nControls: w, a, s, d and x to quit\n\n\nRemaining lifes: %d    Points: %d \n\n\n", life, points);
        for(int i = 0;i<Ysize;i++){ //printing playerfield
            for(int j = 0;j<Xsize;j++){
                printf("%c ", playerfield[i][j]);
            }
            printf("\n");
        }
        if(life==0){
            printf("\nYou died\n\n");
            enterToContinue();
            return 0;
        }
        input = getch();
        //printf("\n %c", input);   //if wanted to see pressed keybind
        if(input == 'w'){ //up movement
            keystrokes++;
            if(currY == 0){//if goes over edge
                playerfield[currY][currX] = 176; //field if player goes over edge
                currY = Ysize;
            }
            currY--;
            if(playerfield[currY][currX] == 'O'){
                points = points+10;
            }
            if(playerfield[currY][currX] == 'Z'){
                life--;
            }
            playerfield[currY][currX] = 254; //new player pos
            playerfield[currY+1][currX] = 176; //field after player leaves

        }else if(input == 's'){ //down movement
            keystrokes++;
            if(currY == Ysize-1){//if goes over edge
                playerfield[currY][currX] = 176; //field if player goes over edge
                currY = -1;
            }
            currY++;
            if(playerfield[currY][currX] == 'O'){
                points = points+10;
            }
            if(playerfield[currY][currX] == 'Z'){
                life--;
            }
            playerfield[currY][currX] = 254; //new player pos
            playerfield[currY-1][currX] = 176; //field after player leaves

        }else if(input == 'a'){ // left movement
            keystrokes++;
            if(currX == 0){//if goes over edge
                playerfield[currY][currX] = 176; //field if player goes over edge
                currX = Xsize;
            }
            currX--;
            if(playerfield[currY][currX] == 'O'){
                points = points+10;
            }
            if(playerfield[currY][currX] == 'Z'){
                life--;
            }
            playerfield[currY][currX] = 254; //new player pos
            playerfield[currY][currX+1] = 176; //field after player leaves

        }else if(input == 'd'){ // right movement
            keystrokes++;
            if(currX == Xsize-1){//if goes over edge
                playerfield[currY][currX] = 176; //field if player goes over edge
                currX = -1;
            }
            currX++;
            if(playerfield[currY][currX] == 'O'){
                points = points+10;
            }
            if(playerfield[currY][currX] == 'Z'){
                life--;
            }
            playerfield[currY][currX] = 254; //new player pos
            playerfield[currY][currX-1] = 176; //field after player leaves

        }else if(input == 'x'){ // x to quit the game
            return 0;
        }
    }
    return 0;
}