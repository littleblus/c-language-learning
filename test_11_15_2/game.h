#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define LINE 3

//��Ϸ����
void menu();
//��ʼ������
void init(char arr[ROW][LINE],int row,int line);
//��ӡ����
void print(char arr [ROW][LINE], int row, int line);