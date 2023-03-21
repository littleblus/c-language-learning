#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack.h"

void test1() {
	Stack a;
	STInit(&a);
	STPush(&a, 1);
	STPush(&a, 2);
	STPush(&a, 3);
	STPush(&a, 919);
	STPush(&a, 5);
	STPop(&a);
	printf("%zd\n", STSize(&a));
	printf("%d\n", STTop(&a));
	STDestory(&a);
}

int main() {
	test1();
	return 0;
}