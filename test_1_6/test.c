#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//qsort使用练习

//int cmpint(const void* a, const void* b);

//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmpint);
//	//打印
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}



//模仿qsort的功能实现一个通用的冒泡排序
int cmpint(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void Swap(char* a, char* b, const int width) {
	for (int i = 0; i < width; i++) {
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

void bubble_sort(void* base, const int num, const int width, int(*cmp)(const void*, const void*)) {
	//冒泡排序
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmpint);
	//打印
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}