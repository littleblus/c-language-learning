#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆

void CreateNnums(FILE* data, int n) {
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) {
		fprintf(data, "%d\n", rand() % 10000);
	}
}

int main() {
	const char* filename = "data.txt";
	//FILE* data = fopen(filename, "w");
	//CreateNnums(data, 200);
	FILE* data = fopen(filename, "r");
	int arr[200];
	for (int i = 0; i < 200; i++) {
		fscanf(data, "%d", &arr[i]);
	}
	Heap test;
	HeapCreate(&test, arr, 10);
	for (int i = 10; i < 200; i++) {
		if (arr[i] > HeapTop(&test)) {
			test._a[0] = arr[i];
			AdjustDown(test._a, 0, 10);
		}
	}
	//打印
	for (int i = 0; i < 10; i++) {
		printf("%d\n", HeapTop(&test));
		HeapPop(&test);
	}
	return 0;
}