#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s) {
    struct stack {
        char* data;
        int top;
        int capacity;
    }Stack;
    Stack.data = (struct stack*)malloc(sizeof(char) * 100);
    Stack.capacity = 100;
    Stack.top = 0;
    char* cur = s;
    while (*cur) {
        if (Stack.top == Stack.capacity) {//�ж�����
            Stack.data = (struct stack*)realloc(Stack.data, Stack.capacity * 2);
            Stack.capacity *= 2;
        }
        if (*cur == '(' || *cur == '[' || *cur == '{') {
            //��ջ
            Stack.data[Stack.top] = *cur;
            Stack.top++;
        }
        else {
            //�ж�ջ��
            if (Stack.top == 0) {//ջΪ�ղ��Ҳ���������
                free(Stack.data);
                return false;
            }
            switch (*cur) {
            case ')':
                if ('(' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    free(Stack.data);
                    return false;
                }
                break;
            case ']':
                if ('[' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    free(Stack.data);
                    return false;
                }
                break;
            case '}':
                if ('{' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    free(Stack.data);
                    return false;
                }
                break;
            default:
                free(Stack.data);
                return false;
                break;
            }
        }
        cur++;
    }
    free(Stack.data);
    if (Stack.top == 0) {
        return true;
    }
    else {
        return false;
    }
}

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

//����������O(N)�汾������
//struct Node* copyRandomList(struct Node* head) {
//    if (!head) {
//        return NULL;
//    }
//    struct Node* cur = head;
//    //���½ڵ����ӵ�Դ�ڵ����һλ
//    while (cur) {
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node*));
//        struct Node* next = cur->next;
//        copy->val = cur->val;
//        copy->next = next;
//        cur->next = copy;
//        cur = next;
//    }
//    cur = head;
//    //�޸��½ڵ��random
//    while (cur) {
//        struct Node* copy = cur->next;
//        //���ж�Դrandom�Ƿ�ΪNULL
//        if (copy->random) {
//            copy->random = copy->random->next;
//        }
//        else {
//            copy->random = NULL;
//        }
//        cur = copy->next;
//    }
//    //���Դ�����������
//    struct Node* copyhead = NULL, * copytail = NULL;
//    cur = head;
//    while (cur) {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//        //copyβ��
//        if (copyhead == NULL) {
//            copyhead = copy;
//            copytail = copy;
//        }
//        else {
//            copytail->next = copy;
//            copytail = copytail->next;
//        }
//        //�ָ�Դ����
//        cur->next = next;
//        cur = next;
//    }
//    return copyhead;
//}

int main() {
    struct Node n1 = { 0 };
    struct Node n2 = { 0 };
    struct Node n3 = { 0 };
    struct Node n4 = { 0 };
    struct Node n5 = { 0 };

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    n1.val = 7;
    n2.val = 13;
    n3.val = 11;
    n4.val = 10;
    n5.val = 1;

    n1.random = NULL;
    n2.random = &n1;
    n3.random = &n5;
    n4.random = &n3;
    n5.random = &n1;

    struct Node* new = copyRandomList(&n1);

    return 0;
}

//���ش�
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    for (struct Node* newNode = head; newNode != NULL; newNode = newNode->next->next) {
        struct Node* cur = malloc(sizeof(struct Node));
        cur->val = newNode->val;
        cur->next = newNode->next;
        newNode->next = cur;
    }
    for (struct Node* newNode = head; newNode != NULL; newNode = newNode->next->next) {
        newNode->next->random = newNode->random == NULL ? NULL : newNode->random->next;
    }
    struct Node* res = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) {
        struct Node* newNode = node->next;
        node->next = node->next->next;
        newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
    }
    return res;
}