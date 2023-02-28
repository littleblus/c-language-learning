#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//qsortʹ����ϰ

//int cmpint(const void* a, const void* b);

//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmpint);
//	//��ӡ
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}



//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
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
	//ð������
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmpint);
	//��ӡ
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}