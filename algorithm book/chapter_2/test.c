#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2-1

//int main()
//{
//	for (int i = 100; i <= 999; i++) {
//		if (i == pow(i / 100, 3) + pow((i / 10) % 10, 3) + pow(i % 10, 3))
//			printf("%d ", i);
//	}
//	printf("\n");
//
//	return 0;
//}



//2-2

//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int a, b, c, kase = 0;
//	while ((scanf("%d%d%d", &a, &b, &c)) != EOF) {
//		int i = 0, flag = 0;
//		for (i = 10; i <= 100; i++) {
//			if (i % 3 == a && i % 5 == b && i % 7 == c) {
//				printf("Case %d: %d\n", ++kase, i);
//				flag = 1;
//			}
//		}
//		if (i == 101 && flag == 0)
//			printf("Case %d: %s\n", ++kase, "No answer");
//	}
//
//	return 0;
//}



//2-3

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		//打印前面空格
//		for (int j = 0; j < i; j++) {
//			printf(" ");
//		}
//		//打印*
//		for (int j = 0; j < 2 * (n - i) - 1; j++) {
//			printf("*");
//		}
//		//打印后面空格
//		for (int j = 0; j < i; j++) {
//			printf(" ");
//		}
//		//换行
//		printf("\n");
//	}
//
//	return 0;
//}



//2-4

//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int n, m, kase = 0;
//	while (1) {
//		scanf("%d%d", &n, &m);
//		if (n == 0 && m == 0)
//			break;
//		double sum = 0;
//		while (n <= m) {
//			sum += 1.0 / (pow(n, 2));
//			n++;
//		}
//		printf("Case %d: %.5f\n", ++kase, sum);
//	}
//
//	return 0;
//}



//2-5(bug)

//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int a, b, c, kase = 0;
//	double sum = 0;
//	while (1) {
//		scanf("%d%d%d", &a, &b, &c);
//		if (a == 0 && b == 0 && c == 0)
//			break;
//		sum = (double)a / b;
//		printf("Case %d: %f\n", ++kase, sum);
//	}
//
//	return 0;
//}



//2-6

int main()
{
	int num1, num2, num3;
	int a, b, c, d, e, f, g, h, i;
	for (num1 = 123; num1 <= 987; num1++) {
		a = num1 / 100;
		b = (num1 / 10) % 10;
		c = num1 % 10;
		if (a == b || a == c || b == c)
			continue;
		for (num2 = 123; num2 <= 987; num2++) {
			d = num2 / 100;
			e = (num2 / 10) % 10;
			f = num2 % 10;
			if (d == e || d == f || e == f)
				continue;
			if (d == a || d == b || d == c || e == a || e == b || e == c || f == a || f == b || f == c)
				continue;
			for (num3 = 123; num3 <= 987; num3++) {
				g = num3 / 100;
				h = (num3 / 10) % 10;
				i = num3 % 10;
				if (g == h || g == i || h == i)
					continue;
				if (g == a || g == b || g == c || h == a || h == b || h == c || i == a || i == b || i == c)
					continue;
				if (g == d || g == e || g == f || h == d || h == e || h == f || i == d || i == e || i == f)
					continue;
				if (num1 * 2 == num2 && num1 * 3 == num3)
					printf("%d %d %d\n", num1, num2, num3);
			}
		}
	}

	return 0;
}