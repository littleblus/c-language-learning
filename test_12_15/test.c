#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
////����һ��������n���������32λ2���Ʊ�ʾ��1�ĸ��������и����ò����ʾ
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//����һ��1Ȼ���������αȽ�
//	int p = 1;
//	int count = 0;
//	for (int i = 0; i < 32; i++) {
//		int f = n & p;
//		if (p == f)
//			count++;
//		p = p << 1;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}



////���������������в�ͬλ�ĸ���
////�����������������һ������
//#include <stdio.h>
//
//int main() 
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int ret = 0;
//	//m,n����������㷵�ص�f�У���ͬ��λΪ1
//	int f = m^n;
//	//����һ��1���������ƣ�����f��1�ĸ���
//	int p = 1;
//	for (int i = 0; i < 32; i++) {
//		if (p == (f & p))
//			ret++;
//		p = p << 1;
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}



////С������̨��-BC117
////С������Ҫ��n��̨�ף�һ�ο���ѡ����һ�׻������ף�һ���ж������߷�
////
////����˼· �ݹ�
//
//#include <stdio.h>
//#include <assert.h>
//
//unsigned int stage(unsigned int n)
//{
//	assert(n >= 1 && n <= 30);
//	unsigned int ret = 0;
//	if (n > 2) {
//		ret = stage(n - 2) + stage(n - 1);
//		return ret;
//	}
//	if (n == 2)
//		return 2;
//	if (n == 1)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	unsigned int ret = stage(n);
//	printf("%d\n", ret);
//
//	return 0;
//}



//����·����� - BC54
//������������ �� �£��������룩
//�����Ӧ����

#include <stdio.h>

int is_leap_year(const int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

int main()
{
	int year = 0;
	int month = 0;
	int flag = 0;
start:
	while (scanf("%d %d", &year, &month) != EOF) {

		int ret = 0;
		switch (month) {
		case 1:
			ret = 31;
			break;
		case 2:
			flag = is_leap_year(year);
			if (flag == 1) {
				ret = 29;
			}
			else
				ret = 28;
			break;
		case 3:
			ret = 31;
			break;
		case 4:
			ret = 30;
			break;
		case 5:
			ret = 31;
			break;
		case 6:
			ret = 30;
			break;
		case 7:
			ret = 31;
			break;
		case 8:
			ret = 31;
			break;
		case 9:
			ret = 30;
			break;
		case 10:
			ret = 31;
			break;
		case 11:
			ret = 30;
			break;
		case 12:
			ret = 31;
			break;
		default:
			printf("�·������������������\n");
			goto start;
		}
		printf("%d\n", ret);
	}

	return 0;
}