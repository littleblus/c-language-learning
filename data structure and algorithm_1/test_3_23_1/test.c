#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��

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
	//��ӡ
	for (int i = 0; i < 10; i++) {
		printf("%d\n", HeapTop(&test));
		HeapPop(&test);
	}
	return 0;
}