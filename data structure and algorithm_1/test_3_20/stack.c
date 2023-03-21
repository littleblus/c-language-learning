#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

void STInit(Stack* ps) {
	assert(ps);
	DataType* tmp = (DataType*)malloc(sizeof(DataType) * 10);
	if (!tmp) {
		perror("malloc failed");
		return;
	}
	ps->data = tmp;
	ps->top = 0;
	ps->capacity = 10;
}

void STDestory(Stack* ps) {
	assert(ps);
	free(ps->data);
	ps->top = 0;
	ps->capacity = 0;
}

void STPush(Stack* ps, DataType val) {
	assert(ps);
	//ÅÐ¶ÏÊÇ·ñÐèÒªÀ©ÈÝ
	if (STSize(ps) == ps->capacity) {
		DataType* tmp = (DataType*)realloc(ps->data, (size_t)ps->capacity * 2);
		if (!tmp) {
			perror("realloc failed");
			return;
		}
		ps->capacity *= 2;
		ps->data = tmp;
	}
	ps->data[ps->top] = val;
	ps->top++;
}

void STPop(Stack* ps) {
	assert(ps);
	ps->top--;
}

DataType STTop(Stack* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	return ps->data[ps->top - 1];
}

size_t STSize(Stack* ps) {
	assert(ps);
	return ps->top;
}

bool STEmpty(Stack* ps) {
	assert(ps);
	if (ps->top == 0)
		return true;
	else
		return false;
}