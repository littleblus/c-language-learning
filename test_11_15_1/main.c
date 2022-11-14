#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1; j++) {
			if (arr[j] > arr[j + 1]) {
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 6,4,5,7,2,9,0,1,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}