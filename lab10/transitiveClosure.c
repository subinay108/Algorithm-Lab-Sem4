// Find the transitive closre of a graph using Floyd Warshall Algorithm

#include<stdio.h>

// Number of vertices in the graph
#define V 4

void transitiveClosure(int[][V]);

int main(){
	// Adjacency matrix of the graph with 1 when i == j
	int graph[V][V] = {
	{1, 1, 1, 0},
	{0, 1, 0, 0}, 
	{0, 1, 1, 1}, 
	{1, 0, 0, 1}};
	
	transitiveClosure(graph);
	return 0;
}



void transitiveClosure(int graph[][V]){
	int reach[V][V];
	int i, j, k;
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			reach[i][j] = graph[i][j];
		}
	}
	
	for(k = 0; k < V; k++){
		for(i = 0; i < V; i++){
			for(j = 0; j < V; j++){
				if(reach[i][j] == 1){ // if i can reach j
					// if j can reach k, then i can also reach k
					if(reach[j][k] == 1 ){
						reach[i][k] = 1;	
					}
				}	
			}
		}
	}
	
	// print reach matrix
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			printf("%d ", reach[i][j]);
		}
		printf("\n");
	}
	
}