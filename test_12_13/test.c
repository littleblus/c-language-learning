#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
////��������ʹ����ȫ��λ��ż��ǰ��
//void change(int arr[], int sz)
//{
//	//��Ϊż��������������������
//	for (int i = 0; i < sz; i++) {
//		if (0 == arr[i] % 2) {
//			int k = sz - 1;
//			while (k>=0) {
//				//�ڽ��������н��м�飬��k�Ѿ�����iѭ����û��ֹͣ��������֤�������Ѿ�ȫ��������ϣ�
//				if (k == i)
//					goto finish;
//				int flag = 0;
//				if (1 == arr[k] % 2) {
//					int tmp = arr[i];
//					arr[i] = arr[k];
//					arr[k] = tmp;
//					flag = 1;
//				}
//				if (1 == flag)
//					break;
//				k--;
//			}
//		}
//	}
//finish:
//	;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &arr[i]);
//	}
//	change(arr, 10);
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


////�������кϲ�
//#include <stdio.h>
//
//void sort(int arr[], int sz)
//{
//	int end = sz - 1;
//	for (int i = 0; i < sz-1; i++) {
//		for (int j = 0; j < end; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//		end--;
//	}
//}
//
//void Add_arr(int arr1[], int sz1, int arr2[], int sz2, int ret[])
//{
//	//�ϲ���������
//	for (int i = 0; i < sz1; i++) {
//		ret[i] = arr1[i];
//	}
//	for (int i = 0; i < sz2; i++) {
//		ret[sz1+i] = arr2[i];
//	}
//	//ð������
//	sort(ret, sz1 + sz2);
//}
//
//int main()
//{
//	int sz1 = 0;
//	int sz2 = 0;
//	scanf("%d %d", &sz1, &sz2);
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	int ret[2000] = { 0 };
//	for (int i = 0; i < sz1; i++) {
//		scanf("%d", &arr1[i]);
//	}
//	for (int i = 0; i < sz2; i++) {
//		scanf("%d", &arr2[i]);
//	}
//	Add_arr(arr1, sz1, arr2, sz2, ret);
//	for (int i = 0; i < sz1 + sz2; i++) {
//		printf("%d ", ret[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//���������ж�
#include <stdio.h>
#include <stdbool.h>

bool is_sort(int arr[], int sz)
{
	int count = 0;
	for (int i = 0; i < sz - 1; i++) {
		if (arr[i] > arr[i + 1])
			count++;
	}
	if (sz - 1 != count && 0 != count)
		return false;
	return true;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bool ret = is_sort(arr,n);
	if (true == ret)
		printf("sorted\n");
	else
		printf("unsorted\n");

	return 0;
}