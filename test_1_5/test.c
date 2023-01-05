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



//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);

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
//			printf("查找的数下标为%d %d\n", line, row);
//			return;
//		}
//	}
//	printf("找不到\n");
//}
//
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
//	YangShiJuZhen(arr, 5, 5, 16);
//
//	return 0;
//}



//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

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



//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

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