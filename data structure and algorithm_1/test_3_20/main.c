#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack.h"

//使用栈实现队列
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
        //将push栈全部转移到pop栈
        while (!STEmpty(obj->push)) {
            STPush(obj->pop, STTop(obj->push));
            STPop(obj->push);
        }
    }
    //取pop栈栈顶
    int ret = STTop(obj->pop);
    STPop(obj->pop);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    //检测pop栈是否为空，若空则挪动元素
    if (STEmpty(obj->pop)) {
        //将push栈全部转移到pop栈
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