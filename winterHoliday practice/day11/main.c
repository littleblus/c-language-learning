#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//第一题

int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int count = 0;
	int max = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 1) {
			count++;
		}
		else
			count = 0;
		if (count > max)
			max = count;
	}
	return max;
}



//第二题

int main() {
	int n = 0;
	scanf("%d", &n);
	if (n < 10) {
		printf("0\n");
		return 0;
	}
	int count = 1;
	for (int i = 10; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			count++;
	}
	printf("%d\n", count);

	return 0;
}