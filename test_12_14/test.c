#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <assert.h>
//
////ģ��ʵ��strcpy
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

//ģ��ʵ��strlen
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