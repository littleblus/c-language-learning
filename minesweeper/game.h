#pragma once
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//�к��зֱ��2
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE 10

//��������ʼ������
void initboard(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col);

//��ӡplayboard
void print(char playboard[ROWS][COLS], int row, int col);

//�������
void setmines(char myboard[ROWS][COLS], int row, int col);

//�û�����
void usercheck(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col);

//�ж�ʤ��
int iswin(char playboard[ROWS][COLS], int row, int col);