#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
////�ݹ�ͷǵݹ�ֱ�����n��쳲�������
//
//////�ݹ鷽��
////int Fib(int n)
////{
////	if (n > 2)
////		return Fib(n - 1) + Fib(n - 2);
////	else
////		return 1;
////}
//
////�ǵݹ鷽��
//int Fib(int n)
//{
//	int sum = 1;
//	int a = 1;
//	int b = 1;
//	if (n > 2) {
//		for (int i = 2; i < n; i++) {
//			sum = a + b;
//			a = b;
//			b = sum;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = Fib(a);
//	printf("%d", ret);
//	return 0;
//}

//#include <string.h>
////�ַ������򣨵ݹ�ʵ�֣�
//
//void reverse_string(char* string)
//{
//	int right = strlen(string);
//	char tmp = *string;
//	*string = *(string + right - 1);
//	*(string + right - 1) = '\0';
//	if (strlen(string + 1) >= 2)
//		reverse_string(string + 1);
//	*(string + right - 1) = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�

////�ݹ�ʵ��
//int Fac(int n)
//{
//	if (n > 1)
//		return Fac(n - 1) * n;
//	else
//		return 1;
//}

//�ǵݹ�ʵ��
int Fac(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum = sum * i;
	}
	return sum;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = Fac(a);
	printf("%d\n", ret);
	return 0;
}