#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <assert.h>
//
////模拟实现strcpy
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL && src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)
//		;
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = { 0 };
//	char* p = "littleblus";
//	my_strcpy(str1, p);
//	printf("%s\n", str1);
//
//	return 0;
//}



#include <stdio.h>

//模拟实现strlen
unsigned int my_strlen(char* str)
{
	unsigned int ret = 0;
	while (*str++ != '\0')
		ret++;
	return ret;
}

int main()
{
	char str[] = "littleblus";
	int len = my_strlen(str);
	printf("%d\n", len);

	return 0;
}