#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////接收一个数，打印乘法口诀表
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

////用来交换两个数的函数
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
//	printf("交换前：%d %d\n", a, b);
//	//交换两个数
//	Swap(&a, &b);
//	printf("交换后：%d %d\n", a, b);
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
//	//输入两个数字确定范围,a<=b
//	scanf("%d %d", &a, &b);
//	//计算范围中的闰年并打印
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