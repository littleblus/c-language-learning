#pragma once

#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap {
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// �ѵĳ�ʼ��
void HeapInit(Heap* hp);

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
bool HeapEmpty(Heap* hp);

// ���ϵ���
void AdjustUp(HPDataType* a, int child);

// ���µ���
void AdjustDown(HPDataType* a, int parent, int n);