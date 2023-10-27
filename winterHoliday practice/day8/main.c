#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//第一题

//int main()
//{
//	int arr[128] = { 0 };
//	char str[500];
//	int sum = 0;
//	char* pc = gets(str);
//	while (*pc) {
//		arr[*pc] = 1;
//		pc++;
//	}
//	for (int i = 0; i < 128; i++) {
//		sum += arr[i];
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}



//第二题

int majorityElement(int* nums, int numsSize) {
	int m = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (count == 0) {
			m = nums[i];
			count = 1;
		}
		else if (m == nums[i]) {
			count++;
		}
		else if (m != nums[i]) {
			count--;
		}
	}
	return m;
}

int main()
{
	int arr[] = { 3,2,3 };
	int t = majorityElement(arr, 3);
	printf("%d\n", t);

	return 0;
}