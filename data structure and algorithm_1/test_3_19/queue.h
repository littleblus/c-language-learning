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

//���еĳ�ʼ��
Queue* QInit();

//���е�����
void QDestory(Queue* pq);