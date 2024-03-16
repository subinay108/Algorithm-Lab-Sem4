// Write a program to solve 0-1 Knapsack Problem using Dynamic Programming
#include<stdio.h>

int max(int a, int b);
void displayMatrix(int* matrix, int row, int col);

int main(){
	int capacity, n;
	
	printf("Enter no. of objects: ");
	scanf("%d", &n);
	int profitArr[n + 1], weightArr[n + 1], knapSack[n + 1];
	knapSack[0] = 0;
	profitArr[0] = 0;
	weightArr[0] = 0;
	printf("Enter the profits of the objects: ");
	int i;
	for(i = 1; i <= n; i++){
		scanf("%d", &profitArr[i]);
	}
	
	printf("Enter the weights of the objects: ");
	for(i = 1; i <= n; i++){
		scanf("%d", &weightArr[i]);
	}
	
	printf("Enter the capacity of Knapsack: ");
	scanf("%d", &capacity);
	
	int V[n + 1][capacity + 1];
	int w;
	
	for(i = 0; i <= n; i++){
		for(w = 0; w <= capacity; w++){
			if(i == 0 || w == 0){
				V[i][w] = 0;
				continue;
			}
			//v[i, w] = max(v[i - 1, w], v[i-1, w-W[i]] + P[i])
			// if w - W[i] < 0 then take v[i-1, w-W[i]] + P[i] is 0
			V[i][w] = max(V[i - 1][w], ((w - weightArr[i]) < 0 ? 0: V[i - 1][w - weightArr[i]] + profitArr[i])); 
		}
	}
	
	i = n;
	w = capacity;
	while(i > 0){
		if(V[i][w] == V[i - 1][w]){
			knapSack[i] = 0;
			i--;
		}else{
			knapSack[i] = 1;
			w -= weightArr[i];
			i--;
		}	
	}
	
	printf("Table: \n");
	displayMatrix(&V[0][0], n + 1, capacity + 1);
	
	printf("KnapSack Details: \n");
	printf("Profit\t Weight\t Include\n");
	for(i = 1; i <= n; i++){
		printf("%d\t %d\t %s\n", profitArr[i], weightArr[i], (knapSack[i]? "Yes" : "No"));
	}
	
	printf("Maximum profit: %d", V[n][capacity]);
		
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