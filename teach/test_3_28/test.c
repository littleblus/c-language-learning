#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
*  1.while循环
*  2.do ... while循环
*  3.for循环
*  4.break continue语句
*  5.goto语句
*/


int main() {
	////while语句
	//int i = 5;
	//i == 5;//true
	//i == 4;//false
	/////*非0值*/ 1 - 99 666; //true
	////0 //false
	//while (/*表达式*/i) { //i != 0
	//	/*循环语句*/
	//	printf("hehe\n");
	//	i--;
	//}

	////do while循环
	int password = 123;
	int x;
	int count = 3;
	do {
		/*循环语句*/
		printf("请输入密码>");
		scanf("%d", &x);
		count--;
	} while (/*表达式*/password != x && count != 0);
	if (count == 0)
		printf("尝试次数用尽\n");
	else
		printf("正确\n");

	//for循环

	for (/*表达式1*/int i=1; /*表达式2*/i<=50; /*表达式3*/i++) {
		/*循环语句*/
		if (i == 30)
			continue;
		printf("%d\n", i);
	}

	//break和continue语句
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" % d X %d = %d", i, j, i * j);
		}
		printf("\n");
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			//i是4 j是3
			if (i == 4 && j == 3)
				goto liuweijun;
		}
	}
liuweijun:

	return 0;
}

int main() {
	//生成1-10000的所有质数
	printf("2\n");
	for (int i = 3; i <= 100000000; i+=2) {
		//质数：除了1和它本身，找不到任何可以整除的因数
		int flag = 0;//0是质数，1是合数
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d\n", i);
	}
	return 0;
}

int main() {
	//算阶乘
	int x;
	/* -1 */scanf("%d", &x);
	int sum = 1;
	while (x != 0) {
		sum = sum * x;
		x--;
	}
	printf("%d\n", sum);
	return 0;
}