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
	if (!new) {
		return;
	}
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
	assert(pplist);
	SLTNode* new = CreateSLTNode(val);
	if (!new) {
		return;
	}
	new->next = *pplist;
	*pplist = new;
}

void SLTPopBack(SLTNode** pplist) {
	assert(pplist);
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
	assert(pplist);
	if (!(*pplist)) {
		return;
	}
	//只有一个节点
	if (!(*pplist)->next) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SLTNode* tmp = (*pplist)->next;
		free(*pplist);
		*pplist = tmp;
		tmp = NULL;
	}
}

SLTNode* SLTSearch(SLTNode* plist, SLTDataType val) {
	while (plist) {
		if (plist->data == val) {
			return plist;
		}
		else {
			plist = plist->next;
		}
	}
	return NULL;
}

void SLTInsertAfter(SLTNode* pos, SLTDataType val) {
	assert(pos);
	SLTNode* new = CreateSLTNode(val);
	if (!new) {
		return;
	}
	new->next = pos->next;
	pos->next = new;
}

void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	if (pos->next == NULL) {
		return;
	}
	SLTNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
	next = NULL;
}

void SLTDestory(SLTNode** pplist) {
	assert(pplist);
	if (*pplist == NULL) {
		return;
	}
	SLTNode* cur = *pplist;
	SLTNode* tmp = NULL;
	while (cur) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	cur = NULL;
	tmp = NULL;
	*pplist = NULL;
}