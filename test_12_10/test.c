#define _CRT_SECURE_NO_WARNINGS 1


//����ת��
//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);//2 3
//    int arr1[10][10] = { 0 };
//    int arr2[10][10] = { 0 };
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d ", &arr1[i][j]);
//        }
//    }
//    //�����Ϊת�ú������һ
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            arr2[i][j] = arr1[j][i];
//        }
//    }
//    //��ӡ�����
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", arr2[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


////������ɾ��ָ������
////��һ������Ҫ��������ָ���
////�ڶ�������N���������ÿո�ֿ���N<=50��
////������������Ҫ����ɾ����һ������
////���Ϊ1�У�ɾ��ָ������֮�������
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr1[50] = { 0 };
//	int arr2[50] = { 0 };
//	//����N������
//	for (int i = 0; i < n; i++) {
//		scanf("%d ", &arr1[i]);
//	}
//	//����Ҫɾ������
//	int del = 0;
//	scanf("%d", &del);
//	//������������������������2
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (del != arr1[i]) {
//			arr2[count] = arr1[i];
//			count++;
//		}
//	}
//	//��ӡ����2
//	for (int i = 0; i < count; i++) {
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}


////����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
//
//#include <stdio.h>
//
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	//�����ǿ�ƿ���ܺȼ�ƿ��ˮ
//	int init = 0;
//	init = money;
//	//��ƿ�һ�����ˮ
//	int plus = init / 2;
//	printf("%d\n", init + plus);
//	return 0;
//}


////�����Ǿ����ж�
////�����Ǿ������Խ������µ�Ԫ�ض�Ϊ0�ľ���
////���Խ���Ϊ�Ӿ�������Ͻ������½ǵ�����
////��һ�а���һ������n����ʾһ���������n��n�У��ÿո�ָ���(1��n��10)
////��2��n + 1�У�ÿ������n����������Χ - 231~231 - 1�����ÿո�ָ���������n * n������
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//���������������
//	int arr[10][10] = { 0 };
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d ", &arr[i][j]);
//		}
//	}
//	//�ж�
//	int flag = 0;
//	for (int i = n-1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (arr[i][j] != 0)
//				flag = 1;
//		}
//	}
//	if (flag == 1)
//		printf("NO\n");
//	else if (flag == 0)
//		printf("YES\n");
// 
//	return 0;
//}


//��������ж�
//��һ�а�����������n��m����ʾ�����������n��m�У��ÿո�ָ�
//��2��n+1�У�ÿ������m����������Χ-231~231-1�����ÿո�ָ���������n*m��������ʾ��һ�������е�Ԫ�ء�
//��n + 2�е�2n + 1��ÿ������m����������Χ - 231~231 - 1�����ÿո�ָ���������n * m��������ʾ�ڶ��������е�Ԫ�ء�
//1 < n, m < 10

#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	//������������
	int arr1[9][9] = { 0 };
	int arr2[9][9] = { 0 };
	//����һ�����ݴ��浽arr1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &arr1[i][j]);
		}
	}
	//���ڶ������ݴ��浽arr2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &arr2[i][j]);
		}
	}
	//���αȽ��������������
	int flag = 0;//0Ϊ��ͬ��1Ϊ��ͬ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i][j] != arr2[i][j])
				flag = 1;
		}
	}
	if (flag == 0)
		printf("Yes\n");
	else if (flag == 1)
		printf("No\n");

	return 0;
}