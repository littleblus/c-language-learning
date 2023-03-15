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
        if (Stack.top == Stack.capacity) {//判断容量
            Stack.data = (struct stack*)realloc(Stack.data, Stack.capacity * 2);
            Stack.capacity *= 2;
        }
        if (*cur == '(' || *cur == '[' || *cur == '{') {
            //入栈
            Stack.data[Stack.top] = *cur;
            Stack.top++;
        }
        else {
            //判断栈顶
            if (Stack.top == 0) {//栈为空并且不是左括号
                return false;
            }
            switch (*cur) {
            case ')':
                if ('(' == Stack.data[Stack.top - 1]) {//相等则出栈
                    Stack.top--;
                }
                else {
                    return false;
                }
                break;
            case ']':
                if ('[' == Stack.data[Stack.top - 1]) {//相等则出栈
                    Stack.top--;
                }
                else {
                    return false;
                }
                break;
            case '}':
                if ('{' == Stack.data[Stack.top - 1]) {//相等则出栈
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