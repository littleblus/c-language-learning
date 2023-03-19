#pragma once

typedef int DataType;

typedef struct QueueNode {
	DataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* data;
	QNode* head;
	QNode* tail;
}Queue;

//队列的初始化
Queue* QInit();

//队列的销毁
void QDestory(Queue* pq);