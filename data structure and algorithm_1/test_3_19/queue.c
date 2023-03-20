#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void QInit(Queue* pq) {
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}

void QDestory(Queue* pq) {
    assert(pq);
    while (pq->head) {
        QNode* tmp = pq->head;
        pq->head = tmp->next;
        free(tmp);
    }
    pq->tail = NULL;
}

void QPush(Queue* pq, DataType val) {
    assert(pq);
    //创建新节点
    QNode* tmp = (QNode*)malloc(sizeof(QNode));
    if (!tmp) {
        perror("malloc failed");
        return;
    }
    tmp->val = val;
    tmp->next = NULL;
    if (QEmpty(pq)) {
        pq->head = tmp;
        pq->tail = tmp;
    }
    else {
        pq->tail->next = tmp;
        pq->tail = tmp;
    }
}

void QPop(Queue* pq) {
    assert(pq);
    if (QEmpty(pq))
        return;
    if (pq->head == pq->tail)
        pq->tail = NULL;
    QNode* tmp = pq->head;
    pq->head = pq->head->next;
    free(tmp);
    tmp = NULL;
}

DataType QFront(Queue* pq) {
    assert(pq);
    assert(!QEmpty(pq));
    return pq->head->val;
}

DataType QBack(Queue* pq) {
    assert(pq);
    assert(!QEmpty(pq));
    return pq->tail->val;
}

size_t QSize(Queue* pq) {
    assert(pq);
    if (QEmpty(pq))
        return 0;
    else {
        QNode* cur = pq->head;
        for (size_t count = 0;; cur = cur->next, count++) {
            if (!cur)
                return count;
        }
    }
}

bool QEmpty(Queue* pq) {
    assert(pq);
    if (pq->head == NULL)
        return true;
    else
        return false;
}