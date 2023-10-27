#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//��һ��

int* selfDividingNumbers(int left, int right, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int));
	int num = 0;
	for (int i = left; i <= right; i++) {
		int tmp = i;
		if (i >= 1 && i <= 9) {
			num++;
			arr = (int*)realloc(arr, sizeof(int) * num);
			assert(arr);
			arr[i - left] = i;
			continue;
		}
	con:
		//�ж��Ƿ���0
		if (tmp % 10 == 0)
			continue;
		if (tmp >= 1 && tmp <= 9 && i % (tmp % 10) == 0) {
			num++;
			arr = (int*)realloc(arr, sizeof(int) * num);
			assert(arr);
			arr[num - 1] = i;
		}
		if (tmp > 9) {
			if (i % (tmp % 10) == 0) {
				tmp = tmp / 10;
				goto con;
			}
		}
	}
	*returnSize = num;
	return arr;
}



//�ڶ���

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	//���۳˻�
	int* leftsum = (int*)malloc(sizeof(int) * numsSize);
	//���۳˻�
	int* rightsum = (int*)malloc(sizeof(int) * numsSize);
	//��������
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	memset(arr, 0, sizeof(int) * numsSize);
	leftsum[0] = 1;
	rightsum[numsSize - 1] = 1;
	//���leftsum,rightsum,arr�Ƿ񴴽��ɹ�
	assert(leftsum && rightsum && arr);
	for (int i = 1; i < numsSize; i++) {
		leftsum[i] = leftsum[i - 1] * nums[i - 1];
	}
	for (int i = numsSize - 2; i >= 0; i--) {
		rightsum[i] = rightsum[i + 1] * nums[i + 1];
	}
	for (int i = 0; i < numsSize; i++) {
		arr[i] = leftsum[i] * rightsum[i];
	}
	*returnSize = numsSize;
	return arr;
}