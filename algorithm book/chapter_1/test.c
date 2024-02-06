#define _CRT_SECURE_NO_WARNINGS 1

//1-1
#include <stdio.h>
#include <math.h>

//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	printf("%.3f\n", (a + b + c) / 3.0);
//
//	return 0;
//}



//1-2

//int main()
//{
//	int fah = 0;
//	scanf("%d", &fah);
//	printf("%.3f\n", 5 * (fah - 32) / 9.0);
//
//	return 0;
//}



//1-3

//int main()
//{
//	int n = 0, sum = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		sum += i;
//	printf("%d\n", sum);
//
//	return 0;
//}



//1-4

//#define PI 3.14159265
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%f %f\n", sin((n / 180.0) * PI), cos((n / 180.0) * PI));
//
//	return 0;
//}



//1-5

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n > 3)
//		printf("%.2f\n", 0.85 * 95 * n);
//	else
//		printf("%.2f\n", 95.0 * n);
//
//	return 0;
//}



//1-6

//int main()
//{
//	int a, b, c;
//	int flag = 1;
//	scanf("%d%d%d", &a, &b, &c);
//	//使c为3个数的最大值
//	if (a > c) {
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b > c) {
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	//判断是否构成三角形
//	if (a + b <= c) {
//		printf("not a triangle\n");
//		flag = 0;
//	}
//	//勾股定理判断直角三角形
//	if (a * a + b * b == c * c)
//		printf("yes\n");
//	else if(flag == 1)
//		printf("no\n");
//
//	return 0;
//}



//1-7

int main()
{
	int year = 0;
	scanf("%d", &year);
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}