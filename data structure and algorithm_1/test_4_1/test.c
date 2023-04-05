#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "sort.h"

void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	//ÅÅºÃÊÇ-8 0 1 2 3 3 4 5 6 18
	int arr[10] = { 3,1,4,5,2,-8,6,18,3,0 };
	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	//SelectSort(arr, 10);
	//HeapSort(arr, 10);
	//BubbleSort(arr, 10);
	QuickSort(arr, 0, 9);
	Print(arr, 10);
	return 0;
}