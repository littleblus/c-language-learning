#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "queue.h"

void test1() {
	Queue a;
	QInit(&a);
	QPush(&a, 1);
	QPush(&a, 2);
	QPush(&a, 3);
	QPush(&a, 4);
	QPush(&a, 5);
	QPop(&a);
	printf("%zd\n", QSize(&a));
	QDestory(&a);
}

int main() {
	test1();
	return 0;
}