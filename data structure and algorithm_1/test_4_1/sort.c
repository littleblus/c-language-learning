#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
		//����endΪ-1��tmp����0�±�
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	//gap > 1 Ԥ����
	//gap = 1 ��������
	int gap = n;
	while (gap > 1) {
		//gap�ݼ�����֤gap��СΪ1
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
			//ѡ��������Сֵ
			if (a[i] < min) {
				min = a[i];
				mini = i;
			}
			if (a[i] > max) {
				max = a[i];
				maxi = i;
			}
		}
		//����С�����ֱ������ұ߽罻��
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
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, i, n);
	//��ĩβ�������µ���
	int end = n - 1;
	while (end > 0) {
		swap(&a[end], &a[0]);
		AdjustDown(a, 0, end);
		end--;
	}
}

void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {//��n-1��
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

//horea��
int PartSort1(int* a, int left, int right) {
	int l = left, r = right;
	//����ȡ��
	int midi = GetMidI(a, left, right);
	if (midi != left)
		swap(&a[left], &a[midi]);
	int keyi = left;
	int key = a[left];
	while (left < right) {
		//������С
		while (left < right && a[right] >= key)
			right--;
		//�����Ҵ�
		while (left < right && a[left] <= key)
			left++;
		swap(&a[left], &a[right]);
	}
	//��ʱleft == right
	swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

//�ڿӰ�
int PartSort2(int* a, int left, int right) {
	int l = left, r = right;
	//����ȡ��
	int midi = GetMidI(a, left, right);
	if (midi != left)
		swap(&a[left], &a[midi]);
	int key = a[left];
	int hole = left;
	while (left < right) {
		//�ұ���С
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;
		//�����Ҵ�
		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//˫ָ���
int PartSort3(int* a, int left, int right) {
	//����ȡ��
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
	//С�����Ż������ٵݹ����
	if (right - left + 1 > 10) {
		// int keyi = PartSort1(a, left, right);
		// int keyi = PartSort2(a, left, right);
		int keyi = PartSort3(a, left, right);
		//�ݹ�
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else {
		InsertSort(&a[left], right - left + 1);
	}
}

//��������ķǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right) {
	Stack st;
	STInit(&st);
	//���һ������
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st)) {
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		//С�����Ż�
		if (right - left + 1 > 10) {
			int keyi = PartSort3(a, begin, end);
			if (keyi - 1 > begin) {
				STPush(&st, keyi - 1);
				STPush(&st, begin);
			}
			if (keyi + 1 < end) {
				STPush(&st, end);
				STPush(&st, keyi + 1);
			}
		}
		else {
			InsertSort(&a[begin], end - begin + 1);
		}
	}
	STDestory(&st);
}

static void _MergeSort(int* a, int* tmp, const int left, const int right) {
	//С�����Ż�
	if (right - left + 1 <= 10) {
		InsertSort(&a[left], right - left + 1);
		return;
	}
	int mid = (right + left) >> 1;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);
	// [left , mid] [ mid + 1 , right]
	int p1 = left;
	int p2 = mid + 1;
	int i = left;
	while (p1 <= mid && p2 <= right) {
		if (a[p1] < a[p2]) {
			tmp[i++] = a[p1++];
		}
		else {
			tmp[i++] = a[p2++];
		}
	}
	//����һ��ָ���ߵ��˾�ͷ
	while (p1 <= mid) {
		tmp[i++] = a[p1++];
	}
	while (p2 <= right) {
		tmp[i++] = a[p2++];
	}
	//����ԭ����
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (!tmp) {
		perror("malloc failed");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void MergeSortNonR(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (!tmp) {
		perror("malloc failed");
		return;
	}
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i;
			int end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap;
			int end2 = begin2 + gap - 1;
			//printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);
			if (end1 >= n || begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;
			int j = i;//tmpβָ��
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}
			//����һ��ָ���ߵ��˾�ͷ
			while (begin1 <= end1) {
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2) {
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		//printf("\n");
		gap *= 2;
	}
}

void CountSort(int* a, int n) {
	int max, min;
	max = min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int num = max - min + 1;
	int* count = (int*)calloc(num, sizeof(int));
	if (!count) {
		perror("calloc failed");
		return;
	}
	for (int i = 0; i < n; i++) {
		count[a[i] - min]++;
	}
	int p = 0;
	for (int i = 0; i < num; i++) {
		while (count[i]--) {
			a[p++] = i + min;
		}
	}
	free(count);
}

void MonkeySort(int* a, int n) {
	int i, j;
	srand((unsigned int)time(NULL));
	while (1) {
		for (i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				break;//�����Ԫ���ڲ���ȷ��λ�ã�����ѭ��
			}
		}
		if (i == n - 1) {//�������Ԫ�ض�����ȷλ�ã��������
			return;
		}
		for (i = 0; i < n; i++) {
			j = rand() % n;//�����������Ԫ�ص�λ��
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}