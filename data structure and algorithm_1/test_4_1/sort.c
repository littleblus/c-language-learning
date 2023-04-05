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
		bool exchange = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				exchange = true;
			}
		}
		if (!exchange)
			break;
	}
}

static int GetMidI(int* a, int left, int right) {
	int midi = (left + right - 1) / 2;
	if (a[left] < a[midi]) {
		if (a[midi] < a[right])
			return midi;
		else if (a[right] < a[left])
			return left;
		else
			return right;
	}
	else {//left > midi
		if (a[right] > a[left])
			return left;
		else if (a[right] > a[midi])
			return right;
		else
			return midi;
	}
}

//horea版
int PartSort1(int* a, int left, int right) {
	int l = left, r = right;
	//三数取中
	int midi = GetMidI(a, left, right);
	if (midi != left)
		swap(&a[left], &a[midi]);
	int keyi = left;
	int key = a[left];
	while (left < right) {
		//右走找小
		while (left < right && a[right] >= key)
			right--;
		//左走找大
		while (left < right && a[left] <= key)
			left++;
		swap(&a[left], &a[right]);
	}
	//此时left == right
	swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

//挖坑版
int PartSort2(int* a, int left, int right) {
	int l = left, r = right;
	//三数取中
	int midi = GetMidI(a, left, right);
	if (midi != left)
		swap(&a[left], &a[midi]);
	int key = a[left];
	int hole = left;
	while (left < right) {
		//右边找小
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;
		//左走找大
		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//双指针版
int PartSort3(int* a, int left, int right) {
	//三数取中
	int midi = GetMidI(a, left, right);
	if (midi != left)
		swap(&a[left], &a[midi]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right) {
		if (a[cur] < a[keyi] && ++prev != cur)
			swap(&a[prev], &a[cur]);
		cur++;
	}
	swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int left, int right) {
	if (left >= right)
		return;
	// int keyi = PartSort1(a, left, right);
	// int keyi = PartSort2(a, left, right);
	int keyi = PartSort3(a, left, right);
	//递归
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}