// Write a program to implement of Warshall's Algorithm
// find the shortest paths between all pairs of nodes in a weighted graph

#include<stdio.h>

#define INF 9999


void displayMatrix(int* matrix, int size);
int min(int a, int b);

int main(){
	int node;
	printf("Enter no. of nodes: ");
	scanf("%d", &node);
	
	int adjMatrix[node][node];
	int i, j;
	
	for(i = 0; i < node; i++){
		for(j = 0; j < node; j++){
			if(i == j){
				adjMatrix[i][j] = 0;
				continue;
			}
            
			printf("Enter weight from Node %d to Node %d (-1 if not present): ", i + 1, j + 1);
			scanf("%d", &adjMatrix[i][j]);
	
			if(adjMatrix[i][j] == -1){
				adjMatrix[i][j] = INF;
			}
		}
	}
	
	printf("Adjecency matrix: \n");
	displayMatrix(&adjMatrix[0][0], node);
	
	
	// Floyd-Warshall Algorithm
	int k;
	for(k = 0; k < node; k++){
		for(i = 0; i < node; i++){
			for(j = 0; j < node; j++){
				adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
			}
		}
	}
	
	printf("Shortest Path matrix: \n");
	displayMatrix(&adjMatrix[0][0], node);
	
	return 0;
}

void displayMatrix(int* matrix, int size){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%4d ", matrix[i * size +  j] == INF ? -1 : matrix[i * size + j]);
		}
		printf("\n");
	}
}

int min(int a, int b){
	return (a < b) ? a : b;
}