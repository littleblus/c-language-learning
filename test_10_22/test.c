#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//�ж��������ѭ����ӡ5
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


//��ӡ1-100����3�ı���������
//int main()
//{
//	for (int a = 1; a <= 100; a++) {
//		if (a % 3 == 0)
//			printf("%d\n", a);
//	}
//	return 0;
//}


//���������������Ӵ�С���
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("�����������������ÿո������\n");
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


//��ӡ1000-2000�е�����
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


//����������������������������Լ��
//������Сֵ����
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
//	int ret = 0;//��ʼ�����
//	scanf("%d %d", &a, &b);
//	//�����Լ��������
//	int r = MIN(a, b);
//	//�����Գ���ѭ����������ֹͣ
//	for (int n = 1; n <= r; n++) {
//		if (a % n == 0 && b % n == 0) {
//			//������Ҫ���������
//			ret = n;
//		}
//	}
//	//������
//	printf("%d", ret);
//	return 0;
//}


//��ӡ100-200������
//int main()
//{
//	int p = 0;//�жϱ���
//	for (int n = 100; n <= 200; n++) {
//		for (int a = 2; a < n; a++) {
//			p = 0;
//			//��������ɹ�����n��������
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