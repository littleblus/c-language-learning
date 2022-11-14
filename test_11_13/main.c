#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

int main()
{
	int tmp = 0;
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 11,12,13,14,15,16,17,18,19,20 };
	//开始交换
	for (int a = 0; a < 10; a++) {
		tmp = arr1[a];
		arr1[a] = arr2[a];
		arr2[a] = tmp;
	}
	//查看结果
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (int j = 0; j < 10; j++) {
		printf("%d ", arr2[j]);
	}
	return 0;
}