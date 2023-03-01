#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单链表打印
void SLTPrint(SLTNode* plist);

//单链表尾插
void SLTPushBack(SLTNode** pplist, SLTDataType val);

//单链表头插
void SLTPushFront(SLTNode** pplist, SLTDataType val);

//单链表尾删
void SLTPopBack(SLTNode** pplist);

//单链表头删
void SLTPopFront(SLTNode** pplist);
