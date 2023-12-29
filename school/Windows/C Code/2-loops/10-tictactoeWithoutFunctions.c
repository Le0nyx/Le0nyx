/*
File: 10-tictactoeWithoutFunctions.c
Date: 06-11-2023  12:41
Author: Leon A.
File Description: ---

*/

#include<stdio.h>
 
int main (){
	//declaring variables
	int eingabeX = 0;
	int eingabeO = 0;
	int gameOn = 1;
	char place[11];
	int blocked[11];
	char exapleO = 'O';
	char exapleX = 'X';
	int gameOver = 0;
	int replayGame = 0;
	char eingabeRepeat = ' ';
	int winsX = 0;
	int winsO = 0;
	
	printf("\n \n Please use for the fields only Integers");
	
	while(replayGame!=1){ //restarts game later on
	
		for(int i = 0;i < 11;i++){ //chars all to spaces
			place[i] = ' ';
			blocked[i] = ' ';
		}

		while(gameOn == 1){ //loop for UI and game
				
			//drawing X turn
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[1], place[2], place[3]);
			printf("\n        |          |        ");
			printf("\n--------|----------|--------       1 | 2 | 3  ");
			printf("\n        |          |              ---|---|--- ");
			printf("\n   %c    |    %c     |   %c           4 | 5 | 6  ", place[4], place[5], place[6]);
			printf("\n        |          |              ---|---|--- ");
			printf("\n--------|----------|--------       7 | 8 | 9  ");
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[7], place[8], place[9]);
			printf("\n        |          |        ");
			printf("\n        |          |        ");
			
			
			
			//reading input and putting in X
			printf("\n \n(X) Where do you want your X to be placed: ");
			scanf("%d", &eingabeX);
			
			while(eingabeX<1 || eingabeX >9 || eingabeX == blocked[eingabeX]){ //be in the place
				printf("\n \n(X) Re-enter a new matching Value or that isnt taken already: ");
				scanf("%d", &eingabeX);
			}
			
			place[eingabeX] = 'X';
			blocked[eingabeX] = eingabeX;
			
			
			//win conditions after X turn
			//horizontal
			if(place[1] == exapleX && place[2] == exapleX && place[3] == exapleX){
				printf("\n X won. 1, 2 and 3 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[2] == exapleO && place[3] == exapleO){
				printf("\n O won. 1, 2 and 3 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[4] == exapleX && place[5] == exapleX && place[6] == exapleX){
				printf("\n X won. 4, 5 and 6 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[4] == exapleO && place[5] == exapleO && place[6] == exapleO){
				printf("\n O won. 4, 5 and 6 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[7] == exapleX && place[8] == exapleX && place[9] == exapleX){
				printf("\n X won. 7, 8 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[7] == exapleO && place[8] == exapleO && place[9] == exapleO){
				printf("\n O won. 7, 8 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			
			//vertical
			if(place[1] == exapleX && place[4] == exapleX && place[7] == exapleX){
				printf("\n X won. 1, 4 and 7 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[4] == exapleO && place[7] == exapleO){
				printf("\n O won. 1, 4 and 7 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[2] == exapleX && place[5] == exapleX && place[8] == exapleX){
				printf("\n X won. 2, 5 and 8 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[2] == exapleO && place[5] == exapleO && place[8] == exapleO){
				printf("\n O won. 2, 5 and 8 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[3] == exapleX && place[6] == exapleX && place[9] == exapleX){
				printf("\n X won. 3, 6 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[3] == exapleO && place[6] == exapleO && place[9] == exapleO){
				printf("\n O won. 3, 6 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			
			//cross
			if(place[1] == exapleX && place[5] == exapleX && place[9] == exapleX){
				printf("\n X won. 1, 5 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[5] == exapleO && place[9] == exapleO){
				printf("\n O won. 1, 5 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[3] == exapleX && place[5] == exapleX && place[7] == exapleX){
				printf("\n X won. 3, 5 and 7 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[3] == exapleO && place[5] == exapleO && place[7] == exapleO){
				printf("\n O won. 3, 5 and 7 are the same\n");
				gameOn = 0;
				winsO++;
			} //gameOn = 0 is going to end the game
			
			
			
			//drawing O turn
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[1], place[2], place[3]);
			printf("\n        |          |        ");
			printf("\n--------|----------|--------       1 | 2 | 3  ");
			printf("\n        |          |              ---|---|--- ");
			printf("\n   %c    |    %c     |   %c           4 | 5 | 6  ", place[4], place[5], place[6]);
			printf("\n        |          |              ---|---|--- ");
			printf("\n--------|----------|--------       7 | 8 | 9  ");
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[7], place[8], place[9]);
			printf("\n        |          |        ");
			printf("\n        |          |        ");
			
			if(gameOn == 0){ //still prints new field but then ends loop
				break;
			}
			
			//reading input and putting in O
			printf("\n \n(O) Where do you want your O to be placed: ");
			scanf("%d", &eingabeO);

			while(eingabeO<1 || eingabeO >9 || eingabeO == blocked[eingabeO]){ //be in the place
				printf("\n \n(O)Re-enter a new matching Value or that isnt taken already: ");
				scanf("%d", &eingabeO);
			}
			place[eingabeO] = 'O';
			blocked[eingabeO] = eingabeO;
			
			//win conditions still missing ((make function for that shit))
			//horizontal 
			//after O turn
			if(place[1] == exapleX && place[2] == exapleX && place[3] == exapleX){
				printf("\n X won. 1, 2 and 3 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[2] == exapleO && place[3] == exapleO){
				printf("\n O won. 1, 2 and 3 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[4] == exapleX && place[5] == exapleX && place[6] == exapleX){
				printf("\n X won. 4, 5 and 6 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[4] == exapleO && place[5] == exapleO && place[6] == exapleO){
				printf("\n O won. 4, 5 and 6 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[7] == exapleX && place[8] == exapleX && place[9] == exapleX){
				printf("\n X won. 7, 8 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[7] == exapleO && place[8] == exapleO && place[9] == exapleO){
				printf("\n O won. 7, 8 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			
			//vertical
			if(place[1] == exapleX && place[4] == exapleX && place[7] == exapleX){
				printf("\n X won. 1, 4 and 7 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[4] == exapleO && place[7] == exapleO){
				printf("\n O won. 1, 4 and 7 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[2] == exapleX && place[5] == exapleX && place[8] == exapleX){
				printf("\n X won. 2, 5 and 8 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[2] == exapleO && place[5] == exapleO && place[8] == exapleO){
				printf("\n O won. 2, 5 and 8 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[3] == exapleX && place[6] == exapleX && place[9] == exapleX){
				printf("\n X won. 3, 6 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[3] == exapleO && place[6] == exapleO && place[9] == exapleO){
				printf("\n O won. 3, 6 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			
			//cross
			if(place[1] == exapleX && place[5] == exapleX && place[9] == exapleX){
				printf("\n X won. 1, 5 and 9 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[1] == exapleO && place[5] == exapleO && place[9] == exapleO){
				printf("\n O won. 1, 5 and 9 are the same\n");
				gameOn = 0;
				winsO++;
			}
			if(place[3] == exapleX && place[5] == exapleX && place[7] == exapleX){
				printf("\n X won. 3, 5 and 7 are the same\n");
				gameOn = 0;
				winsX++;
			}
			if(place[3] == exapleO && place[5] == exapleO && place[7] == exapleO){
				printf("\n O won. 3, 5 and 7 are the same\n");
				gameOn = 0;
				winsO++;
			} //gameOn = 0 is going to end the game
			
			gameOver++;
			//gameOver
			if(gameOver == 9){
				gameOn = 0;
			}
			if(gameOn == 0){ //still prints new field but then ends loop
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[1], place[2], place[3]);
			printf("\n        |          |        ");
			printf("\n--------|----------|--------       1 | 2 | 3  ");
			printf("\n        |          |              ---|---|--- ");
			printf("\n   %c    |    %c     |   %c           4 | 5 | 6  ", place[4], place[5], place[6]);
			printf("\n        |          |              ---|---|--- ");
			printf("\n--------|----------|--------       7 | 8 | 9  ");
			printf("\n        |          |        ");
			printf("\n   %c    |    %c     |   %c    ", place[7], place[8], place[9]);
			printf("\n        |          |        ");
			printf("\n        |          |        ");
				break;
			}
			
		//if replayGame = 1 exe is over
		}
			if(gameOn == 0){
				printf(" \n Statistics: \n X won %d times. \n O won %d times.", winsX, winsO); //statistic
				
				printf("\n \n Want to start a new game? \n [y/n]: "); //new game or not
				scanf("%s", &eingabeRepeat);
					while(eingabeRepeat != 'n' && eingabeRepeat != 'y'){
						printf("\n \n \n WRONG INPUT! \n Want to start a new game? \n [y/n]: "); //new game or not
						scanf("%s", &eingabeRepeat);
					}
				if(eingabeRepeat == 'n'){
					replayGame = 1;
				}
				if(eingabeRepeat == 'y'){
					gameOn = 1;
					gameOver = 0;
				}
			}	
	}
	
	return 0;
}