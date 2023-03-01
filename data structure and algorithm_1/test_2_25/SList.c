#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

static SLTNode* CreateSLTNode(SLTDataType val) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("malloc failed");
		return NULL;
	}
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

void SLTPrint(SLTNode* plist) {
	SLTNode* cur = plist;
	while (cur) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pplist, SLTDataType val) {
	SLTNode* new = CreateSLTNode(val);
	if (!(*pplist)) {
		*pplist = new;
	}
	else {
		SLTNode* end = *pplist;
		//找尾
		while (end->next) {
			end = end->next;
		}
		end->next = new;
	}
}

void SLTPushFront(SLTNode** pplist, SLTDataType val) {

}

void SLTPopBack(SLTNode** pplist) {
	if (!(*pplist))
		return;
	SLTNode* end = *pplist;
	//只有一个节点
	if (!end->next) {
		free(end);
		end = NULL;
		*pplist = NULL;
	}
	else {
		//找尾
		while (end->next->next) {
			end = end->next;
		}
		free(end->next);
		end->next = NULL;
	}
}

void SLTPopFront(SLTNode** pplist) {

}
