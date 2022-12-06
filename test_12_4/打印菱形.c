#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char str[13] = { 0 };
	char* pa = str;
	//ÌîÂú*
	for (int i = 0; i < 13; i++) {
		*pa++ = '*';
	}
	printf("%s\n", str);
	return 0;
}