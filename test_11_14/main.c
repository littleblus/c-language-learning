#define _CRT_SECURE_NO_WARNINGS 1


////����һ���������飬��ɶ�����Ĳ���
////
////ʵ�ֺ���init() ��ʼ������Ϊȫ0
////ʵ��print()  ��ӡ�����ÿ��Ԫ��
////ʵ��reverse()  �����������Ԫ�ص����á�
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
//	//����
//	reverse(arr,sz);
//	print(arr,sz);
//	//��ʼ��Ϊ0
//	init(arr,sz);
//	print(arr,sz);
//
//	return 0;
//}
