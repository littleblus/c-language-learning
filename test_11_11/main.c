#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//���һ������ģ��strlen�Ĺ���

////�ǵݹ�
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}

////�ݹ�ʵ��
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


//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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