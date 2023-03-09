#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//链表的初始化
LTNode* InitLT();

//链表的打印
void LTPrint(LTNode* plist);

//链表指定位置插入
void LTInsert(LTNode* pos, DataType val);

//链表的头插
void LTPushFront(LTNode* plist, DataType val);

//链表的尾插
void LTPushBack(LTNode* plist, DataType val);

//链表指定位置删除
void LTErase(LTNode* pos);

//链表的头删
void LTPopFront(LTNode* plist);

//链表的尾删
void LTPopBack(LTNode* plist);

//链表的查找
LTNode* LTFind(LTNode* plist, DataType findval);

//链表的销毁
void LTDestroy(LTNode* plist);