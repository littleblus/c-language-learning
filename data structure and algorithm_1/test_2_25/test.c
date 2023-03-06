#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void test1() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);

	SLTPrint(plist);

	SLTPopFront(&plist);

	SLTPrint(plist);
	SLTNode* ret = SLTSearch(plist, 10);
	if (ret == NULL)
		printf("NULL");
	else
		printf("%d\n", ret->data);
}

void test2() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTInsertAfter(SLTSearch(plist, 2), 100);
	SLTPrint(plist);
	SLTEraseAfter(SLTSearch(plist, 100));
	SLTPrint(plist);

	SLTDestory(&plist);
}

int main() {
	//test1();
	test2();
	return 0;
}