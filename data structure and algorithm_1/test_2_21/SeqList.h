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

//��ʼ��
void SLinit(SL* s);

//ɾ��
void SLdestory(SL* s);

//��ӡ˳���
void SLprint(SL* s);

//β��
void SLpushback(SL* s, SLDataType val);

//βɾ
void SLpopback(SL* s);

//ͷ��
void SLpushfront(SL* s, SLDataType val);

//ͷɾ
void SLpopfront(SL* s);

//��pos����ֵ
void SLinsert(SL* s, int pos, SLDataType val);

//��posɾ��ֵ
void SLerase(SL* s, int pos);

//��˳����в���
int SLfindpos(SL* s, SLDataType val);