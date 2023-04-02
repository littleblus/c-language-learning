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

void SelectSort(int* a, int n) {
	int left = 0;
	int right = n - 1;
	int mini = left;
	int maxi = left;
	while (left < right) {
		int min, max;
		min = max = a[left];
		for (int i = left; i <= right; i++) {
			//选出最大和最小值
			if (a[i] < min) {
				min = a[i];
				mini = i;
			}
			if (a[i] > max) {
				max = a[i];
				maxi = i;
			}
		}
		//将最小与最大分别与左右边界交换
		swap(&a[left], &a[mini]);
		if (left == maxi)
			maxi = mini;
		swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}

void AdjustDown(int* a, int parent, int n) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child]) {
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int* a, int n) {
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, i, n);
	//从末尾依次向下调整
	int end = n - 1;
	while (end > 0) {
		swap(&a[end], &a[0]);
		AdjustDown(a, 0, end);
		end--;
	}
}

void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {//走n-1趟
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}

void QuickSort(int* a, int n) {

}