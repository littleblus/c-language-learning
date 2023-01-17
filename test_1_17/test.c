#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//模拟实现atoi

int my_atoi(const char* str) {
	int len = (int)strlen(str);
	int ret = 0;
	while (1) {
		if (*str >= '0' && *str <= '9') {
			for (int i = len - 1; i >= 0; i--) {
				ret += (*str - '0') * (int)pow(10, i);
				str++;
			}
		}
		else if(*str=='\0'){
			break;
		}
		else {
			return 0;
		}
	}
	return ret;
}

int main()
{
	int val;
	char str[20];

	strcpy(str, "08993489");
	val = my_atoi(str);
	printf("字符串值 = %s, 整型值 = %d\n", str, val);

	strcpy(str, "littleblus");
	val = my_atoi(str);
	printf("字符串值 = %s, 整型值 = %d\n", str, val);

	return 0;
}