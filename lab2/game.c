// 21 Match sticks
// Max no. of ms can be picked = 4
// minimum = 1
// Two player will play the game
// who pick the last one will loss the game
#include<stdio.h>

int main(){
	int sticks = 21;
	int n, picked = 0;
	int remaining = sticks;
	printf("There are %d sticks\n", sticks);
	while(1){
		// user choose
		printf("Choose no. of sticks: ");
		scanf("%d", &n);
		picked += n;
		remaining = sticks - picked;
		printf("Remaining Sticks: %d\n", 21 - picked);
		if(remaining <= 0){
			printf("you loose");
			break;
		}
		
		// computer choose
		picked += (5 - n);
		printf("Computer picks: %d\n", 5 - n);
		printf("Remaining Sticks: %d\n", 21 - picked);
		if(remaining <= 0){
			printf("Computer looses");
			break;
		}
		
		
	}
}