#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main() {
	int a = 1, b = 2, m = 0, n = 0, k; 
	k = (n = b < a) && (m = a);
	printf("%d,%d\n", k, m); 
	return 0;
}