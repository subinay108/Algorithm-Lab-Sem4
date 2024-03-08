#include<stdio.h>

#define SIZE 3 // size of the tic-tac-toe

struct Turn{
	int x;
	int y;
};

int board[SIZE][SIZE];

void printGameOpening(){
	printf("Welcome to the game of tic-tac-toe\n");
	printf("Game rules: You are always X and enter the position to play\n\
<row no><space><col no>\n\
Example: |o|x| |\n\
         |o|x| |\n\
         | | | |\n\
Suppose you want to play the middle column of last row then enter: 3 2\n\
Let\'s start the game... \n\n");	
}

void printBoard(){
	int i, j;
	char c;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			switch(board[i][j]){
				case 0:
					c = ' ';
					break;
				case 1:
					c = 'o';
					break;
				case -1:
					c = 'x';
					break;
				default:
					c = ' ';
					break;
			}
			printf("|%c", c);
		}
		printf("|\n");
	}
}

void setBoard(int row, int col, int value){
	board[row][col] = value;
}

struct Turn getRandomTurn(){
	if
}

int main(){
	printGameOpening();
	
	int running = 1;
//	int userTurn[2], computerTurn[2];
	struct Turn userTurn, computerTurn;
	while(running){
		printBoard();
		
		// user's turn
		printf("You play: ");
		scanf("%d %d", &userTurn.x, &userTurn.y);
		setBoard(userTurn.x, userTurn.y, 1);
		
		// computer's turn
		computerTurn = getRandomTurn();
		printf("Computer plays: %d %d", computerTurn.x, computerTurn.y);	
		
//		running = 0;
	}
	return 0;
}
