#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int iq;
	while (~scanf("%d", &iq)){
		if (iq >= 140) {
			printf("genius");
		}
	}
	return 0;
}