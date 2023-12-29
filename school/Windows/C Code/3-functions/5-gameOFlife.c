/*
File: 6-gameOFlife.c
Date: 07-12-2023  08:32
Author: Leon A.
File Description: ---

*/
 
void print_field(int x, int y, char field[x][y]);
int checkFields(int zeilen, int spalten, char welt[zeilen][spalten], char player, int i, int j);
void Unicls();

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int Xlen = 0, Ywidth = 0; //variables
    int infested = 0;
    int temp = 0;
    //input
    printf("\n Enter the X-length of the field: ");
    scanf("%d", &Xlen);
    printf("\n Enter the Y-width of the field: ");
    scanf("%d", &Ywidth);
    printf("\n Enter how many cells shall be alive: ");
    scanf("%d", &infested);
    //array
    char field[Xlen][Ywidth];
    char tempfield[Xlen][Ywidth];

    for(int i = 0;i<Xlen;i++){ //fill it with basic stuff
        for(int j = 0;j<Ywidth;j++){
            field[i][j] = '-'; //vs code dont like for some reason
            tempfield[i][j] = field[i][j];
        }
    }
    for(int i = 0;i<infested;i++){ //fill it with infested
        field[rand()%Xlen][rand()%Ywidth] = 'x';
    }

    int gameOn = 1;
    while(gameOn==1){
        sleep(1);
        Unicls();
        for(int i = 0;i<Xlen;i++){
            for(int j = 0;j<Ywidth;j++){
                temp = checkFields(Xlen, Ywidth, field, 'x', i, j);
                if(temp == 3){
                    tempfield[i][j] = 'x';
                }else if(temp < 2){
                    tempfield[i][j] = '-';
                }else if(temp > 3){
                    tempfield[i][j] = '-';
                }
            }
        }
        for(int i = 0;i<Xlen;i++){
            for(int j = 0;j<Ywidth;j++){
                field[i][j] = tempfield[i][j];
            }
        }
        print_field(Xlen, Ywidth, field);
    }
    return 0;
}


void print_field(int x, int y, char field[x][y]){
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

int checkFields(int zeilen, int spalten, char welt[zeilen][spalten], char player, int i, int j){
    int neighbors = 0;
    if (welt[(i - 1 + zeilen) % zeilen][(j + 0 + spalten) % spalten] == player){
        neighbors++;
    }
    if (welt[(i + 1 + zeilen) % zeilen][(j + 0 + spalten) % spalten] == player){
        neighbors++;
    }
    for (int a = -1; a < 2; a++){
        if (welt[(i + a + zeilen) % zeilen][(j - 1 + spalten) % spalten] == player){
            neighbors++;
        }
        if (welt[(i + a + zeilen) % zeilen][(j + 1 + spalten) % spalten] == player){
            neighbors++;
        }
    }
    return neighbors;
}

void Unicls(){
    #ifdef _WIN32
        system("cls"); //Win
    #else
        system("clear"); // Unix 
    #endif
}