#pragma once

#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap {
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// 堆的初始化
void HeapInit(Heap* hp);

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);

// 堆的销毁
void HeapDestory(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
bool HeapEmpty(Heap* hp);

// 向上调整
void AdjustUp(HPDataType* a, int child);

// 向下调整
void AdjustDown(HPDataType* a, int parent, int n);