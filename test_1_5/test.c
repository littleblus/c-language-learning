#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	int num;
//
//	return 0;
//}



//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    char* str4 = "hello bit.";
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}



//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);

//void YangShiJuZhen(int arr[5][5], int i, int j, int x) {
//	int line = 0;
//	int row = j - 1;
//	while (line < i && row >= 0) {
//		if (arr[line][row] < x) {
//			line++;
//		}
//		else if (arr[line][row] > x) {
//			row--;
//		}
//		else {
//			printf("���ҵ����±�Ϊ%d %d\n", line, row);
//			return;
//		}
//	}
//	printf("�Ҳ���\n");
//}
//
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
//	YangShiJuZhen(arr, 5, 5, 16);
//
//	return 0;
//}



//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//void ZuoXuan(char* s, const int len, const int n) {
//	char ch;
//	for (int i = 0; i < n; i++) {
//		ch = s[0];
//		for (int j = 1; j < len; j++) {
//			s[j - 1] = s[j];
//		}
//		s[len - 1] = ch;
//	}
//}
//
//int main()
//{
//	char str[] = "littleblus";
//	ZuoXuan(str, strlen(str), 3);
//	printf("%s\n", str);
//
//	return 0;
//}



//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

int isXuan(char* s1, char* s2, const int len) {
	char ch;
	for (int i = 0; i < len; i++) {
		ch = s1[0];
		for (int j = 1; j < len; j++) {
			s1[j - 1] = s1[j];
		}
		s1[len - 1] = ch;
		if (strcmp(s1, s2) == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char s1[] = "AABCD";
	char s2[] = "DAABC";
	int ret = isXuan(s1, s2, strlen(s1));
	printf("%d\n", ret);

	return 0;
}