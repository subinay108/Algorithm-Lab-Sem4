// Find the subsets of a given set whose sum is equal to target

#include<stdio.h>
#define SIZE 6

int ht[SIZE];
int count = 0;
void find_subset_sum(int *set,int pos, int tg){
	if(pos == SIZE){
		return;	
	}
	if(set[pos] == tg){
		ht[pos] = 1;
        count++;
		printf("Subset: ");
		int i;
		for(i = 0; i < SIZE; i++){
			if(ht[i]){
				printf("%d ", set[i]);
			}
		}
		printf("\n");
		ht[pos] = 0;
		return;
	}
	if(set[pos] < tg){
		ht[pos] = 1;
		find_subset_sum(set, pos + 1, tg - set[pos]);
	}
	ht[pos] = 0;
	find_subset_sum(set, pos + 1, tg);
}

void main(){
	int set[SIZE] = {5, 10, 12, 13, 15, 18};
	int sum = 30;
	printf("Target Sum: %d\n", sum);
	printf("Set: ");
	int i;
	for(i = 0; i < SIZE; i++){
		printf("%d ", set[i]);
	}
	printf("\n");
	
	find_subset_sum(set, 0, sum);
    if(count == 0){
        printf("No subset found");
    }
}