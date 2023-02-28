#pragma once
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//行和列分别加2
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE 10

//创建并初始化棋盘
void initboard(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col);

//打印playboard
void print(char playboard[ROWS][COLS], int row, int col);

//随机放雷
void setmines(char myboard[ROWS][COLS], int row, int col);

//用户排雷
void usercheck(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col);

//判断胜负
int iswin(char playboard[ROWS][COLS], int row, int col);