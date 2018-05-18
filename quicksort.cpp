#include <stdio.h>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivotValue = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivotValue) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {

		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void printArry(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {10, 80, 30, 90, 100, 50, 35};
	int n = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr, 0, n - 1);
	printArry(arr, n);
	return 0;
}