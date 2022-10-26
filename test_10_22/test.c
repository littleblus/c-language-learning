#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//判断输出：死循环打印5
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}


//打印1-100所有3的倍数的数字
//int main()
//{
//	for (int a = 1; a <= 100; a++) {
//		if (a % 3 == 0)
//			printf("%d\n", a);
//	}
//	return 0;
//}


//输入三个整数，从大到小输出
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("请输入三个整数并用空格隔开：\n");
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b && a > c) {
//		if (b > c)
//			printf("%d %d %d\n", a, b, c);
//		else
//			printf("%d %d %d\n", a, c, b);
//	}
//	else if (b > a && b > c) {
//		if (a > c)
//			printf("%d %d %d\n", b, a, c);
//		else
//			printf("%d %d %d\n", b, c, a);
//	}
//	else {
//		if (a > b)
//			printf("%d %d %d\n", c, a, b);
//		else
//			printf("%d %d %d\n", c, b, a);
//	}
//		
//	return 0;
//}


//打印1000-2000中的闰年
int main()
{
	for (int n = 1000; n <= 2000; n++) {
		if (n % 4 == 0 && !(n % 100 == 0)) {
			printf("%d\n", n);
		}
		else {
			if (n % 400 == 0)
				printf("%d\n", n);
		}
	}
	return 0;
}


//给定两个数，求出这两个数的最大公约数
//定义最小值函数
//int MIN(int x, int y)
//{
//	int z = (x < y ? x : y);
//	return z;
//}
//
//
//int main()
//{
//	int a, b;
//	int ret = 0;//初始化结果
//	scanf("%d %d", &a, &b);
//	//求出公约数最大可能
//	int r = MIN(a, b);
//	//依次试除，循环到最大可能停止
//	for (int n = 1; n <= r; n++) {
//		if (a % n == 0 && b % n == 0) {
//			//将符合要求的数保存
//			ret = n;
//		}
//	}
//	//输出结果
//	printf("%d", ret);
//	return 0;
//}


//打印100-200的素数
//int main()
//{
//	int p = 0;//判断变量
//	for (int n = 100; n <= 200; n++) {
//		for (int a = 2; a < n; a++) {
//			p = 0;
//			//如果整除成功，则n不是素数
//			if (n % a == 0) {
//				p = 1;
//				break;
//			}
//			else
//				continue;
//		}
//		if (p == 0)
//			printf("%d\n", n);
//	}
//	return 0;
//}