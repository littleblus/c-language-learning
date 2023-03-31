#pragma once

#include <stdbool.h>
#include "BinaryTree.h"

typedef BTNode* DataType;

typedef struct QueueNode {
	DataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* head;
	QNode* tail;
}Queue;

//队列的初始化
void QInit(Queue* pq);

//队列的销毁
void QDestory(Queue* pq);

//入队列
void QPush(Queue* pq, DataType val);

//出队列
void QPop(Queue* pq);

//获取队列头部元素
DataType QFront(Queue* pq);

//获取队列尾部元素
DataType QBack(Queue* pq);

//队列中有效元素个数
size_t QSize(Queue* pq);

//检测队列是否为空，若空则返回真，非空返回假
bool QEmpty(Queue* pq);