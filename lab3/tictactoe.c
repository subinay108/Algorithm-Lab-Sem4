#include<stdio.h>
#include<stdlib.h>
#include<time.h>


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
	printf("\n");
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

struct Turn getAvailableRandomTurn(){
	int i, j;
	struct Turn t;
	int available = 0;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			if(board[i][j] == 0){
				available++;
			}
		}
	}
	srand(time(NULL));
	int randomNo = rand() % available;
	
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			if(board[i][j] == 0){
				if(randomNo == 0){
					t.x = i;
					t.y = j;
					return t;
				}
				randomNo--;
			}
		}
	}
	
}

int checkWinner(int value){
	int row, col;
	if(board[0][0] == value && board[0][0] == board[0][1] && board[0][0] == board[0][2]){
		
	}
	
	// checks all rows 
	for(row = 0; row < SIZE; row++){
		if(board[row][0] == value && 
		   board[row][0] == board[row][1] && 
		   board[row][0] == board[row][2]){
			return 1;
		}
	}
	
	// checks all cols
	for(col = 0; col < SIZE; col++){
		if(board[0][col] == value && 
		   board[0][col] == board[1][col] && 
		   board[0][col] == board[2][col]){
			return 1;
		}
	}
	
	// checks right diagonal
	if(board[0][0] == value && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
		return 1;
	}
	if(board[0][2] == value && board[0][2] == board[1][1] && board[0][2] == board[2][0]){
		return 1;
	}
	
	return 0;
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
		printBoard();	

		if(checkWinner(1)){
			printf("\nYou win\n");
			running = 0;
			continue;
		}
		
		// computer's turn
		computerTurn = getAvailableRandomTurn();
		printf("Computer plays: %d %d", computerTurn.x, computerTurn.y);
		setBoard(computerTurn.x, computerTurn.y, -1);
		
		if(checkWinner(-1)){
			printf("\nYou loose\n");
			running = 0;
			continue;
		}	
		
//		running = 0;
	}
	return 0;
}
