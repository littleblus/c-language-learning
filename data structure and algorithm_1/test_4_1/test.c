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
	for (int i = 0; i < N; ++i) {
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

void test() {
	int arr[] = { 71414 ,8416 ,89348 ,36020 ,21089 ,8816 ,3346 ,850 ,61100 ,93729 ,80057 ,56036 ,33385 ,445 ,1751 ,32643 ,38142 ,93089 ,52796 ,32244 ,68656 ,94855 ,17948 ,5410, 31664 ,99989 ,13444 ,13426 ,8634 ,29950 ,13120 ,25452 ,27858, 74550 ,28716 ,74586 ,38396, 92055 ,62477 ,28779, 85398 ,87566 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len);
	Print(arr, len);
}

int main() {
	TestOP();
	//test();
	return 0;
}