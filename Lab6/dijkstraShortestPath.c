// Dijkstra's Shortest Path Finding Algorithm
#include<stdio.h>

#define MAX_SIZE 100
#define INF 99999

int Graph[MAX_SIZE][MAX_SIZE];
int shortestPathArr[MAX_SIZE];

void Dijkstra(int size, int source);
void displayGraph(int size);
void printShortestPath(int size, int source);

int main(){
	int n;
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	int e;
	printf("Enter the no. of edges: ");
	scanf("%d", &e);
	int i, w, v1, v2;
	for(i = 0; i < e; i++){
		printf("Enter the vertices and weight between them: ");
		scanf("%d %d %d", &v1, &v2, &w);
		Graph[v1-1][v2-1] = w;
		Graph[v2-1][v1-1] = w;
	}
	
	displayGraph(n);
	
	Dijkstra(n, 0);
	printShortestPath(n, 0);
	
	return 0;
}

void printShortestPath(int size, int source){
	int i; 
	printf("Vertex\tDistance from %d\n", (source + 1));
	for(i = 0; i < size; i++){
		printf("%d\t%d\n", (i + 1), shortestPathArr[i]);
	}
}

void Dijkstra(int size, int source){
	int visitedArr[size];
	int v;
	for(v = 0; v < size; v++){
		shortestPathArr[v] = INF;
		visitedArr[v] = 0;
	}
	
	shortestPathArr[source] = 0;
	
	int minDist;
	int minDistIndex;
	
	int i;
	for(i = 0; i < size; i++){
		
		// find the vertex with min distance
		minDist = INF;
		for(v = 0; v < size; v++){
			if(visitedArr[v] == 0 && shortestPathArr[v] < minDist){
				minDist = shortestPathArr[v];
				minDistIndex = v;
			}
		 }
		 
		// vertex with min distance is visited
		visitedArr[minDistIndex] = 1;
		
		// update the  shortestPathArr value of the adjacent vertices from the vertex with min distance
		int u = minDistIndex;
		for(v = 0; v < size; v++){
			if(!visitedArr[v] && Graph[u][v] 
			&& shortestPathArr[u] + Graph[u][v] < shortestPathArr[v]){
				shortestPathArr[v] = shortestPathArr[u] + Graph[u][v];
			}
		}
	}

}

void displayGraph(int size){
	int i, j;
	printf("Graph: \n");
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}