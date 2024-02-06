#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//设计一个函数模拟strlen的功能

////非递归
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}

////递归实现
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		str++;
//	else
//		return 0;
//	return 1+my_strlen(str);
//}
//
//int main()
//{
//	char arr[] = "hellobit";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//递归方式实现打印一个整数的每一位
//1234 = 
void pel(int x){
	if (x > 9)
		pel(x / 10);
	printf("%d ", x%10);
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	pel(a);
	return 0;
}