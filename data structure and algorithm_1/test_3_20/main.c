#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack.h"

//ʹ��ջʵ�ֶ���
typedef struct {
    Stack* push;
    Stack* pop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* qt = (MyQueue*)malloc(sizeof(MyQueue));
    Stack* st1 = (Stack*)malloc(sizeof(Stack));
    Stack* st2 = (Stack*)malloc(sizeof(Stack));
    if (!qt || !st1 || !st2) {
        perror("malloc failed");
        return NULL;
    }
    STInit(st1);
    STInit(st2);
    qt->push = st1;
    qt->pop = st2;
    return qt;
}

void myQueuePush(MyQueue* obj, int x) {
    STPush(obj->push, x);
}

int myQueuePop(MyQueue* obj) {
    if (STEmpty(obj->pop)) {
        //��pushջȫ��ת�Ƶ�popջ
        while (!STEmpty(obj->push)) {
            STPush(obj->pop, STTop(obj->push));
            STPop(obj->push);
        }
    }
    //ȡpopջջ��
    int ret = STTop(obj->pop);
    STPop(obj->pop);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    //���popջ�Ƿ�Ϊ�գ�������Ų��Ԫ��
    if (STEmpty(obj->pop)) {
        //��pushջȫ��ת�Ƶ�popջ
        while (!STEmpty(obj->push)) {
            STPush(obj->pop, STTop(obj->push));
            STPop(obj->push);
        }
    }
    return STTop(obj->pop);
}

bool myQueueEmpty(MyQueue* obj) {
    if (STEmpty(obj->push) && STEmpty(obj->pop))
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    STDestory(obj->push);
    STDestory(obj->pop);
    free(obj);
}