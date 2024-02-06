#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//本题要求计算并输出不超过n的最大的k个素数以及它们的和。
//输入在一行中给出n(10<n<10000)和k(1<k<10)的值
//在一行中按下列格式输出:
//素数1 + 素数2 + . + 素数k = 总和值
//递减输出

int main()
{
	int n = 0;
	int k = 0;
	int flag1 = 0;
	int flag2 = 0;
	int count = 0;
	int sum = 0;
	scanf("%d %d", &n, &k);
	//试除法判断素数
	//可判断奇偶并通过只输入偶数减少计算总量
	for (int i = n; i >= 2; i--) {
		//判断打印素数个数是否达到输入要求最大个数
		if (count == k) {
			printf("=%d\n", sum);
			flag2 = 1;
			break;
		}
		//判断素数（可用sqrt加快时间，需包含math库）
		for (int j = 2; j < i; j++) {
			flag1 = 0;
			if (i % j == 0) {
				flag1 = 1;
				break;
			}
			else
				continue;
		}
		//将素数加和sum并计数
		if (flag1 == 0) {
			count++;
			sum = sum + i;
			printf("%d", i);
			//判断未达到最大要求时输出+号
			if(count < k)
				printf("+");
		}

	}
	//若没有达到最大个数，删掉多余+号并输出sum
	if(flag2==0)
		printf("\b=%d\n", sum);
	
	return 0;
}
