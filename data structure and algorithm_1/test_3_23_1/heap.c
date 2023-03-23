#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h" 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void Swap(HPDataType* a, HPDataType* b) {
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//小堆
void AdjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

//小堆
void AdjustDown(HPDataType* a, int parent, int n) {
	assert(a);
	int child = parent * 2 + 1;
	while (child < n) {
		//找左右孩子的次大值
		if (child + 1 < n && a[child] > a[child + 1])
			child++;
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapInit(Heap* hp) {
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (!hp->_a) {
		perror("malloc failed");
		return;
	}
	hp->_size = 0;
	hp->_capacity = 4;
}

void HeapCreate(Heap* hp, HPDataType* a, int n) {
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!hp->_a) {
		perror("malloc failed");
		return;
	}
	hp->_size = hp->_capacity = n;
	//复制数组
	for (int i = 0; i < n; i++) {
		hp->_a[i] = a[i];
	}
	//向下调整建堆,从第h-1层开始
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(hp->_a, i, hp->_size);
	}
}

void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	free(hp);
}

void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		//扩容
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity * 2);
		if (!tmp) {
			perror("realloc failed");
			return;
		}
		hp->_a = tmp;
		hp->_capacity *= 2;
	}
	hp->_a[hp->_size++] = x;
	//向上调整
	AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp) {
	assert(hp);
	if (HeapEmpty(hp)) {
		return;
	}
	//交换堆顶和最后一个元素
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	//弹出最后一个元素
	hp->_size--;
	//向下调整
	AdjustDown(hp->_a, 0, hp->_size);
}

HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

bool HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}