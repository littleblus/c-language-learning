#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//第一题

int main() {
	int arrnum = 0;
	scanf("%d", &arrnum);
	int tmp = 0;
	int ans = 0;
	for (int i = 0; i < arrnum; i++) {
		scanf("%d", &tmp);
		ans = ans ^ tmp;
	}
	printf("%d\n", ans);

	return 0;
}



//第二题

//遍历方法
int findPeakElement(int* nums, int numsLen) {
	if (numsLen == 2) {
		return nums[0] > nums[1] ? 0 : 1;
	}
	for (int i = 0; i < numsLen - 1; i++) {
		if (nums[i + 1] > nums[i]) {
			if (i == numsLen - 2)
				return i + 1;
			continue;
		}
		else {
			return i;
		}
	}
	return 0;
}

//二分查找方法
int findPeakElement(int* nums, int numsLen) {
	int left = 0;
	int right = numsLen - 1;
	int mid = (left + right) / 2;
	while (left < right) {
		mid = (left + right) / 2;
		if (nums[mid] > nums[mid + 1])
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}