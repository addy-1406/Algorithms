#include <stdio.h>

void swap(int *a, int *b){
	int t = *b;
	*b = *a;
	*a = t;
}

void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
	        if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
}

void print(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bubbleSort(arr, n);
	
	printf("Sorted array in ascending order: \n");
	print(arr, n);
}

