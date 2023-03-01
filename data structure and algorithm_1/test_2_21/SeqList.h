#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define INIT_N 4
#define ADDTIMES 2

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

//初始化
void SLinit(SL* s);

//删除
void SLdestory(SL* s);

//打印顺序表
void SLprint(SL* s);

//尾插
void SLpushback(SL* s, SLDataType val);

//尾删
void SLpopback(SL* s);

//头插
void SLpushfront(SL* s, SLDataType val);

//头删
void SLpopfront(SL* s);

//在pos插入值
void SLinsert(SL* s, int pos, SLDataType val);

//在pos删除值
void SLerase(SL* s, int pos);

//在顺序表中查找
int SLfindpos(SL* s, SLDataType val);