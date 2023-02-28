#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//轮转数组
void rotate(int* nums, int numsSize, int k) {
	if (k >= numsSize)
		k %= numsSize;
	if (k == 0)
		return;
	int* tmp = calloc(k + 5, sizeof(int));
	if (tmp != NULL) {
		memcpy(tmp, nums + numsSize - k, sizeof(int) * k);
		memmove(nums + k, nums, (numsSize - k) * sizeof(int));
		memcpy(nums, tmp, sizeof(int) * k);
	}
	free(tmp);
}

//消失的数字
int missingNumber(int* nums, int numsSize) {
	int xornums = 0;
	int xorn = 0;
	for (int i = 0; i < numsSize; i++) {
		xornums ^= nums[i];
	}
	for (int i = 0; i <= numsSize; i++) {
		xorn ^= i;
	}
	return xornums ^ xorn;
}