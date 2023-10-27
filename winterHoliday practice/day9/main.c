#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//第一题

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
		//判断是否含有0
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



//第二题

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	//左累乘积
	int* leftsum = (int*)malloc(sizeof(int) * numsSize);
	//右累乘积
	int* rightsum = (int*)malloc(sizeof(int) * numsSize);
	//返回数组
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	memset(arr, 0, sizeof(int) * numsSize);
	leftsum[0] = 1;
	rightsum[numsSize - 1] = 1;
	//检测leftsum,rightsum,arr是否创建成功
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