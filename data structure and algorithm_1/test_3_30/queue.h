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

//���еĳ�ʼ��
void QInit(Queue* pq);

//���е�����
void QDestory(Queue* pq);

//�����
void QPush(Queue* pq, DataType val);

//������
void QPop(Queue* pq);

//��ȡ����ͷ��Ԫ��
DataType QFront(Queue* pq);

//��ȡ����β��Ԫ��
DataType QBack(Queue* pq);

//��������ЧԪ�ظ���
size_t QSize(Queue* pq);

//�������Ƿ�Ϊ�գ������򷵻��棬�ǿշ��ؼ�
bool QEmpty(Queue* pq);