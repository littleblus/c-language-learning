#pragma once

#include <stdbool.h>

typedef int DataType;

typedef struct {
	DataType* data;
	int top;
	int capacity;
}Stack;

//��ʼ��ջ
void STInit(Stack* ps);

//����ջ
void STDestory(Stack* ps);

//ջ�Ĳ���
void STPush(Stack* ps, DataType val);

//ջ�ĵ���
void STPop(Stack* ps);

//��ȡջ��Ԫ��
DataType STTop(Stack* ps);

//ջ����ЧԪ�ظ���
size_t STSize(Stack* ps);

//�ж�ջ�Ƿ�Ϊ�գ��շ����棬�ǿշ��ؼ�
bool STEmpty(Stack* ps);