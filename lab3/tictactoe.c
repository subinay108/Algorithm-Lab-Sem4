#include<stdio.h>

int main(){
	printf("Welcome to the game of tic-tac-toe\n");
	printf("Game rules: You are always X and enter the position to play\n\
<row no><space><col no>\n\
Example: |o|x| |\n\
         |o|x| |\n\
         | | | |\n\
Suppose you want to play the middle column of last row then enter: 3 2\n\
Let\'s start the game: \n ");
	int running = 1;
	int playerTurn;
	while(running){
		printf("You play: ");
		scanf("%d", &playerTurn);
	}
	return 0;
}