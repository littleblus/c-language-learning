#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
////输入一个正整数n，输出该数32位2进制表示中1的个数，其中负数用补码表示
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//创建一个1然后左移依次比较
//	int p = 1;
//	int count = 0;
//	for (int i = 0; i < 32; i++) {
//		int f = n & p;
//		if (p == f)
//			count++;
//		p = p << 1;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}



////求两个数二进制中不同位的个数
////输入两个整数，输出一个整数
//#include <stdio.h>
//
//int main() 
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int ret = 0;
//	//m,n进行异或运算返回到f中，不同的位为1
//	int f = m^n;
//	//创建一个1，进行左移，计算f中1的个数
//	int p = 1;
//	for (int i = 0; i < 32; i++) {
//		if (p == (f & p))
//			ret++;
//		p = p << 1;
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}



////小乐乐走台阶-BC117
////小乐乐需要走n阶台阶，一次可以选择走一阶或者两阶，一共有多少种走法
////
////解题思路 递归
//
//#include <stdio.h>
//#include <assert.h>
//
//unsigned int stage(unsigned int n)
//{
//	assert(n >= 1 && n <= 30);
//	unsigned int ret = 0;
//	if (n > 2) {
//		ret = stage(n - 2) + stage(n - 1);
//		return ret;
//	}
//	if (n == 2)
//		return 2;
//	if (n == 1)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	unsigned int ret = stage(n);
//	printf("%d\n", ret);
//
//	return 0;
//}



//获得月份天数 - BC54
//输入两个整数 年 月（多组输入）
//输出对应天数

#include <stdio.h>

int is_leap_year(const int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

int main()
{
	int year = 0;
	int month = 0;
	int flag = 0;
start:
	while (scanf("%d %d", &year, &month) != EOF) {

		int ret = 0;
		switch (month) {
		case 1:
			ret = 31;
			break;
		case 2:
			flag = is_leap_year(year);
			if (flag == 1) {
				ret = 29;
			}
			else
				ret = 28;
			break;
		case 3:
			ret = 31;
			break;
		case 4:
			ret = 30;
			break;
		case 5:
			ret = 31;
			break;
		case 6:
			ret = 30;
			break;
		case 7:
			ret = 31;
			break;
		case 8:
			ret = 31;
			break;
		case 9:
			ret = 30;
			break;
		case 10:
			ret = 31;
			break;
		case 11:
			ret = 30;
			break;
		case 12:
			ret = 31;
			break;
		default:
			printf("月份输入错误，请重新输入\n");
			goto start;
		}
		printf("%d\n", ret);
	}

	return 0;
}