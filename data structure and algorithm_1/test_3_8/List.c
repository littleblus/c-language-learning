#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

static LTNode* CreateNewNode(DataType val) {
    LTNode* new = (LTNode*)malloc(sizeof(LTNode));
    if (!new) {
        perror("malloc failed");
        exit(-1);
    }
    new->data = val;
    new->next = new->prev = NULL;
    return new;
}

LTNode* InitLT() {
    LTNode* guard = CreateNewNode(-1);
    guard->next = guard->prev = guard;
    return guard;
}

void LTPrint(LTNode* plist) {
    assert(plist);
    LTNode* cur = plist->next;
    while (cur != plist) {
        printf(" %d <->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void LTInsert(LTNode* pos, DataType val) {
    assert(pos);
    LTNode* newnode = CreateNewNode(val);
    //更改新节点的链接
    newnode->next = pos;
    newnode->prev = pos->prev;
    //更改prev节点的链接
    newnode->prev->next = newnode;
    //更改pos节点的链接
    pos->prev = newnode;
}

void LTPushFront(LTNode* plist, DataType val) {
    assert(plist);
    //在guard->next位置插入
    LTInsert(plist->next, val);
}

void LTPushBack(LTNode* plist, DataType val) {
    assert(plist);
    //在guard位置插入
    LTInsert(plist, val);
}

void LTErase(LTNode* pos) {
    assert(pos);
    //更改pos前一节点的链接
    pos->prev->next = pos->next;
    //保存pos的前一节点
    LTNode* prev = pos->prev;
    //释放pos
    free(pos);
    //更改prev后一节点的链接
    prev->next->prev = prev;
}

void LTPopFront(LTNode* plist) {
    assert(plist);
    LTErase(plist->next);
}

void LTPopBack(LTNode* plist) {
    assert(plist);
    LTErase(plist->prev);
}

LTNode* LTFind(LTNode* plist, DataType findval) {
    assert(plist);
    LTNode* cur = plist->next;
    while (cur != plist) {
        if (cur->data == findval)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void LTDestroy(LTNode* plist) {
    LTNode* cur = plist->next;
    while (cur != plist) {
        LTErase(cur);
        cur = plist->next;
    }
    free(plist);
}