// Write a program to solve Knapsack Problem using Dynamic Programming
#include<stdio.h>

int max(int a, int b);
void displayMatrix(int* matrix, int row, int col);

//v[i, w] = max(v[i - 1, w], v[i-1, w-W[i]] + P[i])

int main(){
	int profitArr[] = {0, 1, 2, 5, 6};
	int weightArr[] = {0, 2, 3, 4, 5};
	int capacity = 8, n = 5, profit;
	
	int V[n + 1][capacity + 1];
	int i , w;
	int maxProfit = 0;
	
	// Initialize V matrix with 0
	for(i = 0; i <= n; i++){
		for(w = 0; w <= capacity; w++){
			V[i][w] = 0;
		}
	}
	
	printf("Before: \n");
	displayMatrix(&V[0][0], n + 1, capacity + 1);
	
	printf("After: \n");
	for(i = 1; i <= n; i++){
		for(w = 1; w <= capacity; w++){
			V[i][w] = max(V[i - 1][w], ((w - weightArr[i]) < 0 ? 0: V[i - 1][w - weightArr[i]]) + profitArr[i]); 
			maxProfit = max(maxProfit, V[i][w]);
		}
	}
	V[4][8]
	
	displayMatrix(&V[0][0], n + 1, capacity + 1);
	
	printf("Maximum profit: %d", maxProfit);
		
	return 0;
}

int max(int a, int b){
	return (a > b ? a: b);
}

void displayMatrix(int* matrix, int row, int col){
	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%4d ", matrix[i * col + j]);
		}
		printf("\n");
	}
}