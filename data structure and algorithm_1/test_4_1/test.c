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
	int arr[10] = { 3,1,4,5,2,-8,6,18,3,0 };
	//InsertSort(arr, 10);
	ShellSort(arr, 10);
	Print(arr, 10);
	return 0;
}