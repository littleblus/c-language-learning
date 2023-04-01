#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		//包含end为-1，tmp放在0下标
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	//gap > 1 预排序
	//gap = 1 插入排序
	int gap = n;
	while (gap > 1) {
		//gap递减并保证gap最小为1
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}