#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//����ĳ�ʼ��
LTNode* InitLT();

//����Ĵ�ӡ
void LTPrint(LTNode* plist);

//����ָ��λ�ò���
void LTInsert(LTNode* pos, DataType val);

//�����ͷ��
void LTPushFront(LTNode* plist, DataType val);

//�����β��
void LTPushBack(LTNode* plist, DataType val);

//����ָ��λ��ɾ��
void LTErase(LTNode* pos);

//�����ͷɾ
void LTPopFront(LTNode* plist);

//�����βɾ
void LTPopBack(LTNode* plist);

//����Ĳ���
LTNode* LTFind(LTNode* plist, DataType findval);

//���������
void LTDestroy(LTNode* plist);