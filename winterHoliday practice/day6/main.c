#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//��һ��

int dominantIndex(int* nums, int numsSize) {
	int max1 = 0;
	int max2 = 0;
	int flag = 0;
	//�ҵ����ֵ
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max1)
			max1 = nums[i];
	}
	//�����ֵ��ǣ�׼�����Ҵδ�ֵ
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == max1) {
			flag = i;
			break;
		}
	}
	//���Ҵδ�ֵ
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max2 && i != flag)
			max2 = nums[i];
	}
	//����Ƿ����������׼
	if (max1 >= 2 * max2)
		return flag;
	else
		return -1;
}



//�ڶ���

//way 1:���д���

//int Delete(int* num, int n) {
//	for (int i = 0; i < n - 1; ++i) {
//		//��num[i]����һλ��ʼ�Ƚϣ�ֱ�����һλ
//		for (int j = i + 1; j < n; ++j) {
//			if (num[i] == num[j]) {
//				//��num[j]��ʼ����������ǰ��һλ
//				for (int k = j; k < n - 1; ++k) {
//					num[k] = num[k + 1];
//				}
//				--n;
//				//��Ϊ��++j�����������ȼ�һ�£�����num[i]�Ƚϵ����ƶ�֮�����һλ����©��һ����
//				--j;
//			}
//		}
//	}
//	return n;
//}
//
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//	//��������,ʱ�临�Ӷ�O(N^2)
//	int n = 1;
//	int* pa = malloc(sizeof(int) * n);
//	int* parr = pa;
//	for (int i = 0; i < nums1Size; i++) {
//		for (int j = 0; j < nums2Size; j++) {
//			if (nums1[i] == nums2[j]) {
//				realloc(parr, sizeof(int) * n);
//				*pa = nums1[i];
//				pa++;
//				n++;
//			}
//		}
//	}
//	//ɾ���������ظ���Ԫ��
//	n = Delete(parr, n);
//	realloc(parr, sizeof(int) * n);
//	return parr;
//}



//way2

int cmpint(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	qsort(nums1, nums1Size, sizeof(int), cmpint);
	qsort(nums2, nums2Size, sizeof(int), cmpint);
	*returnSize = 0;
	int index1 = 0, index2 = 0;
	int* intersection = malloc(sizeof(int) * (nums1Size + nums2Size));
	while (index1 < nums1Size && index2 < nums2Size) {
		int num1 = nums1[index1], num2 = nums2[index2];
		if (num1 == num2) {
			// ��֤����Ԫ�ص�Ψһ��
			if (!(*returnSize) || num1 != intersection[(*returnSize) - 1]) {
				intersection[(*returnSize)++] = num1;
			}
			index1++;
			index2++;
		}
		else if (num1 < num2) {
			index1++;
		}
		else {
			index2++;
		}
	}
	return intersection;
}