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
                return false;
            }
            switch (*cur) {
            case ')':
                if ('(' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    return false;
                }
                break;
            case ']':
                if ('[' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    return false;
                }
                break;
            case '}':
                if ('{' == Stack.data[Stack.top - 1]) {//������ջ
                    Stack.top--;
                }
                else {
                    return false;
                }
                break;
            default:
                return false;
                break;
            }
        }
        cur++;
    }
    if (Stack.top % 2 != 0) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    const char* str = "()";
    bool tmp = isValid(str);
    return 0;
}