#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTtest1() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

}

int main() {
	SLTtest1();
	return 0;
}