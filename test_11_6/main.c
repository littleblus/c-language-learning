#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////�ݹ�ʵ��n��k�η�
//double Pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	//n^k = n^(k-1) * n
//	else if (k > 0)
//		return n * Pow(n, --k);
//	else
//		return 1.0 / Pow(n, -k);
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	double ret =Pow(a, b);
//	printf("%lf", ret);
//	return 0;
//}


//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�

int sum = 0;

//1729 = "172" + 9
int DigitSum(int x)
{
	if (x > 9)
		sum = x%10 + DigitSum(x / 10);
	else
		return x;
	return sum;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = DigitSum(a);
	printf("%d", ret);
	return 0;
}