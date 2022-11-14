#define _CRT_SECURE_NO_WARNINGS 1


////创建一个整形数组，完成对数组的操作
////
////实现函数init() 初始化数组为全0
////实现print()  打印数组的每个元素
////实现reverse()  函数完成数组元素的逆置。
//#include <stdio.h>
//
//void init(int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++) {
//		arr[i] = 0;
//	}
//}
//
//void print(int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int* arr,int sz)
//{
//	int* l = arr;
//	int* r = arr + sz - 1;
//	while (l<r) {
//		int tmp = *l;
//		*l = *r;
//		*r = tmp;
//
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	//逆序
//	reverse(arr,sz);
//	print(arr,sz);
//	//初始化为0
//	init(arr,sz);
//	print(arr,sz);
//
//	return 0;
//}
