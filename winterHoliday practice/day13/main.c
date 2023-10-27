#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//第一题

//int fib(int n) {
//	if (n == 1 || n == 2)
//		return 1;
//	return fib(n - 1) + fib(n - 2);
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	int sum = fib(n);
//	printf("%d\n", sum);
//
//	return 0;
//}



//第二题

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		double sum = a;
		double n = 0.5;
		for (int i = 0; i < b - 1; i++) {
			double tmp = pow(a, n);
			sum += tmp;
			n *= 0.5;
		}
		printf("%.2f\n", sum);
	}

	return 0;
}