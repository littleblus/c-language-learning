#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
*  1.whileѭ��
*  2.do ... whileѭ��
*  3.forѭ��
*  4.break continue���
*  5.goto���
*/


int main() {
	////while���
	//int i = 5;
	//i == 5;//true
	//i == 4;//false
	/////*��0ֵ*/ 1 - 99 666; //true
	////0 //false
	//while (/*���ʽ*/i) { //i != 0
	//	/*ѭ�����*/
	//	printf("hehe\n");
	//	i--;
	//}

	////do whileѭ��
	int password = 123;
	int x;
	int count = 3;
	do {
		/*ѭ�����*/
		printf("����������>");
		scanf("%d", &x);
		count--;
	} while (/*���ʽ*/password != x && count != 0);
	if (count == 0)
		printf("���Դ����þ�\n");
	else
		printf("��ȷ\n");

	//forѭ��

	for (/*���ʽ1*/int i=1; /*���ʽ2*/i<=50; /*���ʽ3*/i++) {
		/*ѭ�����*/
		if (i == 30)
			continue;
		printf("%d\n", i);
	}

	//break��continue���
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf(" % d X %d = %d", i, j, i * j);
		}
		printf("\n");
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			//i��4 j��3
			if (i == 4 && j == 3)
				goto liuweijun;
		}
	}
liuweijun:

	return 0;
}

int main() {
	//����1-10000����������
	printf("2\n");
	for (int i = 3; i <= 100000000; i+=2) {
		//����������1���������Ҳ����κο�������������
		int flag = 0;//0��������1�Ǻ���
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
	//��׳�
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