// Implementation of mergeSort in c
#include<stdio.h>
#include<limits.h>

void mergeSort(int* arr, int lo, int hi);
void mergeArr(int* arr, int lo, int hi);
void displayArr(int* start, int size);

int main(){
	int n;
	printf("Enter the no of elements: ");
	scanf("%d", &n);
	int arr[n];
	
	int i;
	printf("Enter elements: ");
	for(i = 0; i < n ; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Before sorting\n");
	displayArr(arr, n);
	mergeSort(arr, 0, n - 1);
	
	printf("After sorting\n");
	displayArr(arr, n);
	
	
	return 0;
}

void mergeSort(int* arr, int lo, int hi){
	if(lo == hi){
		return;
	}
	int mid = (lo + hi) / 2;
	mergeSort(arr, lo, mid);
	mergeSort(arr, mid + 1, hi);
	
	mergeArr(arr, lo, hi);
}

void mergeArr(int* arr, int lo, int hi){
	int mid = (lo + hi) / 2;
	int leftArr[mid - lo + 2];
	int rightArr[hi - mid + 1];
	
	int i;
	for(i = lo; i <= mid; i++){
		leftArr[i - lo] = arr[i];
	}
	leftArr[mid - lo + 1] = INT_MAX;
	
	for(i = mid + 1; i <= hi; i++){
		rightArr[i - mid - 1] = arr[i];
	}
	rightArr[hi - mid] = INT_MAX;
	
	int leftOfLeftArr = 0, leftOfRightArr = 0;

	for(i = lo; i <= hi; i++){
		// find the lowest element between the left of leftArr and rightArr
		if(leftArr[leftOfLeftArr] < rightArr[leftOfRightArr]){
			arr[i] = leftArr[leftOfLeftArr];
			leftOfLeftArr++;	
		}else{
			arr[i] = rightArr[leftOfRightArr];
			leftOfRightArr++;
		}
		
	}
	
}

void displayArr(int* start, int size){
	int i;
	printf("The array elements are : ");
	for(i = 0; i < size; i++){
		printf("%d ", *start);
		start++;
	}
	printf("\n");
}