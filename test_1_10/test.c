#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct s1 {
	char a;
	char b;
	char c;
}tmp1;

struct s2 {
	struct s1 tmp1;
	char a;
}tmp2;

int main()
{
	printf("%d\n",sizeof(tmp1));
	printf("%d\n", sizeof(tmp2));

	return 0;
}