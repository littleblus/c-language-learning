#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int front;
	int rear;
	int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->data = (int*)malloc(sizeof(int) * (k + 1));
	obj->front = obj->rear = 0;
	obj->k = k;
	return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	obj->data[obj->rear++] = value;
	obj->rear %= (obj->k + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front++;
	obj->front %= (obj->k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}