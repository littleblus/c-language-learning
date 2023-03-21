#pragma once

#include <stdbool.h>

typedef int DataType;

typedef struct {
	DataType* data;
	int top;
	int capacity;
}Stack;

//初始化栈
void STInit(Stack* ps);

//销毁栈
void STDestory(Stack* ps);

//栈的插入
void STPush(Stack* ps, DataType val);

//栈的弹出
void STPop(Stack* ps);

//获取栈顶元素
DataType STTop(Stack* ps);

//栈的有效元素个数
size_t STSize(Stack* ps);

//判断栈是否为空，空返回真，非空返回假
bool STEmpty(Stack* ps);