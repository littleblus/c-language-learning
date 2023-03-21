#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "queue.h"

//用队列实现栈
typedef struct {
    Queue* a;
    Queue* b;
} MyStack;

MyStack* myStackCreate() {
    MyStack* tmp = (MyStack*)malloc(sizeof(MyStack));
    Queue* at = (Queue*)malloc(sizeof(Queue));
    Queue* bt = (Queue*)malloc(sizeof(Queue));
    if (!tmp || !at || !bt) {
        perror("malloc failed");
        return NULL;
    }
    tmp->a = at;
    tmp->b = bt;
    tmp->a->head = tmp->a->tail = NULL;
    tmp->b->head = tmp->b->tail = NULL;
    return tmp;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->b->head) {
        QPush(obj->b, x);
    }
    else {
        QPush(obj->a, x);
    }
}

int myStackPop(MyStack* obj) {
    int ret = 0;
    if (obj->b->head) {
        //将b队列元素依次放到a队列
        while (QSize(obj->b) != 1) {
            QPush(obj->a, QFront(obj->b));
            QPop(obj->b);
        }
        //弹出b的“栈顶”元素
        ret = QFront(obj->b);
        QPop(obj->b);
    }
    else {
        while (QSize(obj->a) != 1) {
            QPush(obj->b, QFront(obj->a));
            QPop(obj->a);
        }
        ret = QFront(obj->a);
        QPop(obj->a);
    }
    return ret;
}

int myStackTop(MyStack* obj) {
    if (obj->b->head) {
        return QBack(obj->b);
    }
    else {
        return QBack(obj->a);
    }
}

bool myStackEmpty(MyStack* obj) {
    if (obj->a->head || obj->b->head) {
        return false;
    }
    else {
        return true;
    }
}

void myStackFree(MyStack* obj) {
    QDestory(obj->a);
    QDestory(obj->b);
    free(obj);
}
