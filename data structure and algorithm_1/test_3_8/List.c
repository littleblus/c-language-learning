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
    //�����½ڵ������
    newnode->next = pos;
    newnode->prev = pos->prev;
    //����prev�ڵ������
    newnode->prev->next = newnode;
    //����pos�ڵ������
    pos->prev = newnode;
}

void LTPushFront(LTNode* plist, DataType val) {
    assert(plist);
    //��guard->nextλ�ò���
    LTInsert(plist->next, val);
}

void LTPushBack(LTNode* plist, DataType val) {
    assert(plist);
    //��guardλ�ò���
    LTInsert(plist, val);
}

void LTErase(LTNode* pos) {
    assert(pos);
    //����posǰһ�ڵ������
    pos->prev->next = pos->next;
    //����pos��ǰһ�ڵ�
    LTNode* prev = pos->prev;
    //�ͷ�pos
    free(pos);
    //����prev��һ�ڵ������
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