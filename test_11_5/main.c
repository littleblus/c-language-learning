#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////����һ��������ӡ�˷��ھ���
//void print_tab(int x)
//{
//	for (int i = 1; i <= x; i++) {
//		for (int n = 1; n <= i; n++) {
//			printf("%dx%d=%d ", i, n,i*n);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print_tab(a);
//	return 0;
//}

////���������������ĺ���
//void Swap(int* x, int* y) 
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ��%d %d\n", a, b);
//	//����������
//	Swap(&a, &b);
//	printf("������%d %d\n", a, b);
//	return 0;
//}

//void is_leap_year(int x, int y)
//{
//	for (; x <= y; x++) {
//		if ((x % 4 == 0 && x % 100  != 0) || x % 400 == 0)
//			printf("%d ", x);
//	}
//}
//
//int main()
//{
//	int a, b;
//	//������������ȷ����Χ,a<=b
//	scanf("%d %d", &a, &b);
//	//���㷶Χ�е����겢��ӡ
//	is_leap_year(a, b);
//	return 0;
//}

#include <math.h>

void is_prime_num(int x, int y)
{
	int flag = 0;
	for (; x <= y;x++) {
		flag = 0;
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0)
				flag = 1;
		}
		if (flag == 0)
			printf("%d ", x);
	}
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	is_prime_num(a, b);
	return 0;
}