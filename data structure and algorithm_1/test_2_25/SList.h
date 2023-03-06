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

//单链表查找
SLTNode* SLTSearch(SLTNode* plist, SLTDataType val);

//单链表在pos后插入值
void SLTInsertAfter(SLTNode* pos, SLTDataType val);

//单链表删除在pos后的值
void SLTEraseAfter(SLTNode* pos);

//单链表的销毁
void SLTDestory(SLTNode** pplist);