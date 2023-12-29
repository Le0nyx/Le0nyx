/*
File: 1-optimizedTicTacToe.c
Date: 13-11-2023  11:36
Author: Leon A.
File Description: ---

*/
#include<stdio.h>

//declaring functions
void printGame(char place[]);
int WinCheck(char player, char place[]);

//global variables
int winsX = 0, winsO = 0;

int main (){
	//declaring variables
	int eingabeX = 0, eingabeO = 0;
	int gameOn = 1, gameOver = 0, replayGame = 0;
    char exapleO = 'O', exapleX = 'X', eingabeRepeat = ' ';
	char place[11];
	int blocked[11];

	printf("\n \n Please use for the fields only Integers");
	while(replayGame!=1){ //restarts game later on
		for(int i = 0;i < 11;i++){ //chars all to spaces
			place[i] = ' ';
			blocked[i] = ' ';
		}

		while(gameOn == 1){ //loop for UI and game
			//drawing X turn
			printGame(place);
			//reading input and putting in X
			printf("\n \n(X) Where do you want your X to be placed: ");
			scanf("%d", &eingabeX);
			while(eingabeX<1 || eingabeX >9 || eingabeX == blocked[eingabeX]){ //be in the place
				printf("\n \n(X) Re-enter a new matching Value or that isnt taken already: ");
				scanf("%d", &eingabeX);
			}
			
			place[eingabeX] = 'X';
			blocked[eingabeX] = eingabeX;
			gameOn = WinCheck(exapleX, place);
			
			//drawing O turn
			printGame(place);
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
			gameOn = WinCheck(exapleO, place);
			
			gameOver++;
			if(gameOver == 9){
				gameOn = 0;
			}
			if(gameOn == 0){ //still prints new field but then ends loop
                printGame(place);
				break;
			}
		}//if replayGame = 1 is over
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

void printGame(char place[]){
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
}

int WinCheck(char player, char place[]){
    int won = 0;
	//horizontal
	for(int i = 0;i<9;i=i+3){
		if(place[i+1] == player && place[i+2] == player && place[i+3] == player){
			won=1;
		}
	}
    //vertical
	for(int i = 0;i<3;i++){
		if(place[i+1] == player && place[i+4] == player && place[i+7] == player){
			won=1;
		}
	}
    //cross
    if(place[1] == player && place[5] == player && place[9] == player){
        won = 1;
    }
    if(place[3] == player && place[5] == player && place[7] == player){
        won = 1;
    }

    if(player == 'X' && won == 1){
        printf("\n X won.");
        winsX++;
        return 0;
    }
    if(player == 'O' && won == 1){
        printf("\n O won.");
        winsO++;
        return 0;
    }
    return 1;
}


/*
                 ,----------------,              ,---------,          
            ,-----------------------,          ,"        ,"|     
          ,"                      ,"|        ,"        ,"  |   
         +-----------------------+  |      ,"        ,"    |      
         |  .-----------------.  |  |     +---------+      |        
         |  |                 |  |  |     | -==----|      |       
         |  |  Leon           |  |  |     |         |      |        
         |  |                 |  |  |/----|`---=    |      |        
         |  |  C:\>_          |  |  |   ,/|==== ooo |      ;        
         |  |                 |  |  |  // |(((( [33]|    ,"        
         |  `-----------------'  |," .;'| |((((     |  ,"         
         +-----------------------+  ;;  | |         |,"            
            /_)______________(_/  //   | +---------+            
       ___________________________/___  `,                          
      /  oooooooooooooooo  .o.  oooo /,   ,\"-----------            
     / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"            
    /_==__==========__==_ooo__ooo=_/'   /___________,"            
    `-----------------------------'                                
*/