#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//�������ӡ
void SLTPrint(SLTNode* plist);

//������β��
void SLTPushBack(SLTNode** pplist, SLTDataType val);

//������ͷ��
void SLTPushFront(SLTNode** pplist, SLTDataType val);

//������βɾ
void SLTPopBack(SLTNode** pplist);

//������ͷɾ
void SLTPopFront(SLTNode** pplist);

//���������
SLTNode* SLTSearch(SLTNode* plist, SLTDataType val);

//��������pos�����ֵ
void SLTInsertAfter(SLTNode* pos, SLTDataType val);

//������ɾ����pos���ֵ
void SLTEraseAfter(SLTNode* pos);

//�����������
void SLTDestory(SLTNode** pplist);