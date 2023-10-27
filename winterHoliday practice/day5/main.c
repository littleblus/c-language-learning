#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//第一题

int GetNumberOfK(int* data, int dataLen, int k) {
	if (dataLen == 0)
		return 0;
	int left = 0;
	int right = dataLen - 1;
	int mid = (left + right) / 2;
	//二分查找找到k
	while (left < right) {
		mid = (left + right) / 2;
		if (data[mid] > k) {
			right--;
		}
		else {
			left++;
		}
	}
	//定位到第一个k
	while (data[mid] == k) {
		mid--;
	}
	//计数
	int count = 0;
	while (data[++mid] == k) {
		count++;
	}
	return count;
}



//第二题

int convertInteger(int A, int B) {
	//计算A与B的不同位数
	//首先A与B按位异或
	unsigned int t = A ^ B;
	//之后计算t中1的个数
	int count = 0;
	while (t) {
		t = t & (t - 1);
		count++;
	}
	return count;
}