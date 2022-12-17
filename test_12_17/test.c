#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//1元1瓶汽水，2个空瓶可以换一瓶汽水，n元可以喝几瓶汽水？

//int qishui(const int n)
//{
//	int empty = 0;
//	int total = 0;
//	total = n;
//	empty = n;
//	while (empty >= 2) {
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	return total;
//}

//经过计算，给出n元能喝到2n-1瓶汽水
int qishui(const int n)
{
	if (n <= 0)
		return 0;
	return 2*n - 1;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = qishui(n);
	printf("%d\n", ret);

	return 0;
}