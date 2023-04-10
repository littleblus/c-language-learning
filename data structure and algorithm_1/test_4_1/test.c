#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"

void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestOP() {
	srand((unsigned int)time(NULL));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i) {
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	printf("InsertSort:%d\n", end1 - begin1);

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("ShellSort:%d\n", end2 - begin2);

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();
	printf("SelectSort:%d\n", end3 - begin3);

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	printf("HeapSort:%d\n", end4 - begin4);

	int begin5 = clock();
	//BubbleSort(a5, N);
	int end5 = clock();
	printf("BubbleSort:%d\n", end5 - begin5);
	
	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();
	printf("QuickSort:%d\n", end6 - begin6);
	
	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();
	printf("MergeSort:%d\n", end7 - begin7);
	
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}


void test() {
	int arr[] = { 9, 8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MonkeySort(arr, len);
	Print(arr, len);
}

int main() {
	TestOP();
	//test();
	return 0;
}