// Knapsack Problem
#include<stdio.h>

struct Object{
	float profit;
	float weight;
	float ratio;
};

typedef struct Object Object;

void sort(Object* ob, int size);

void swap(Object* a, Object* b);

void displayObjects(Object* objArr, int size);

int main(){
	int n;
	float capacity;
	printf("Enter no. of objects: ");
	scanf("%d", &n);
	printf("Enter capacity: ");
	scanf("%f", &capacity);
	
	Object objectArr[n];
	int i;
	for(i = 0; i < n; i++){
		printf("Enter profit and weight of object%d: ", i + 1);
		scanf("%f %f", &objectArr[i].profit, &objectArr[i].weight);
		objectArr[i].ratio = objectArr[i].profit / objectArr[i].weight;
	}
	
	// Display objectArr
	printf("Object Array before sorting\n");
	displayObjects(objectArr, n);
	
	// sort the objectArr with respect to ratio
	sort(objectArr, n);
	
	// Display objectArr
	printf("Object Array after sorting\n");
	displayObjects(objectArr, n);
	
	
	// loop through the object arr to complete the capacity
	float bagWeight = 0;
	float bagProfit = 0;
	i = 0;
	float weight;
	while(i < n && bagWeight < capacity){
		if(objectArr[i].weight <= capacity - bagWeight){
			bagWeight += objectArr[i].weight;
			bagProfit += objectArr[i].profit;
		}else{
			weight = capacity - bagWeight;
			bagWeight += weight;
			bagProfit += objectArr[i].ratio * weight;
		}
//		printf("at %d -> BagWeight: %f\n", i, bagWeight);
		i++;
	}
	
	printf("Maximum profit: %f\n", bagProfit);
	printf("Weight of bag: %f", bagWeight);
	
	return 0;
}

void swap(Object* a, Object* b){
	Object temp = *a;
	*a = *b;
	*b = temp;
}

void displayObjects(Object* objArr, int size){
	int i;
	printf("Objects\t Profit\t Weight\t Ratio\t\n");
	for(i = 0; i < size; i++){
		printf("Object%d %f %f %f\n", i+1, objArr[i].profit, objArr[i].weight, objArr[i].ratio);
	}
	printf("\n");
}


void sort(Object* objArr, int size){
	int i, j;
	int min;
	for(i = 0; i < size - 1; i++){
		min = i;
		for(j = i + 1; j < size; j++){
			if(objArr[min].ratio < objArr[j].ratio){
				min = j;
//				printf("This hits: %d\n", objArr[min].ratio);
			}
		}
		swap(&objArr[min], &objArr[i]);
	}
}
