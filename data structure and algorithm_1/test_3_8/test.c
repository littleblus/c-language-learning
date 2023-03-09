#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void test1() {
	LTNode* list = InitLT();
	LTPushBack(list, 1);
	LTPushBack(list, 2);
	LTPushBack(list, 3);
	LTPushBack(list, 4);
	LTPushBack(list, 5);
	LTPrint(list);
	LTPushFront(list, 100);
	LTPushFront(list, 200);
	LTPrint(list);
	LTPopFront(list);
	LTPopBack(list);
	LTPrint(list);
}

void test2() {
	LTNode* list = InitLT();
	LTPushBack(list, 100);
	LTPushBack(list, 300);
	LTPushBack(list, 500);
	LTPushBack(list, 700);
	LTPushBack(list, 900);
	LTPrint(list);
	LTErase(LTFind(list, 700));
	LTPrint(list);
	LTDestroy(list);
	list = NULL;
}

int main() {
	//test1();
	test2();
	return 0;
}