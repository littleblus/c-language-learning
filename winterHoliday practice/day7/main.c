#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��һ��

//int cmp(const void* a, const void* b) {
//	return *(char*)a - *(char*)b;
//}
//
//int main()
//{
//	char str[1000];
//	scanf("%s", str);
//	qsort(str, strlen(str), sizeof(char), cmp);
//	printf("%s\n", str);
//
//	return 0;
//}



//�ڶ���

int pivotIndex(int* nums, int numsSize) {
	int p = 0, lsum = 0, rsum = 0;
	for (int i = 0; i < numsSize; i++) {
		//lsum,rsum����
		lsum = 0;
		rsum = 0;
		//����lsum
		for (int j = 0; j < p; j++) {
			lsum += nums[j];
		}
		//����rsum
		for (int j = p + 1; j < numsSize; j++) {
			rsum += nums[j];
		}
		if (lsum == rsum)
			return p;
		p++;
	}
	return -1;
}