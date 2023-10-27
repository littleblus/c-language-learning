#define _CRT_SECURE_NO_WARNINGS 1

//第一题

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	int n = pow(m, 3);
//	int t = 0;
//	int count = 0;
//	for (int i = 1; i <= n; i += 2) {
//		for (int j = i; j <= n; j += 2) {
//			t += j;
//			count++;
//			if (t == n && count == m) {
//				int p = i;
//				while (p <= j) {
//					printf("%d", p);
//					p += 2;
//					if (p <= j)
//						printf("+");
//				}
//				printf("\n");
//			}
//			if (t > n) {
//				count = 0;
//				t = 0;
//				break;
//			}
//		}
//	}
//
//	return 0;
//}



//第二题

#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int count = 0;
	int sum = 0;
	for (int i = 2; count < n; i += 3, count++) {
		sum += i;
	}
	printf("%d\n", sum);

	return 0;
}