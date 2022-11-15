#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define LINE 3

//游戏界面
void menu();
//初始化数组
void init(char arr[ROW][LINE],int row,int line);
//打印棋盘
void print(char arr [ROW][LINE], int row, int line);
//玩家行动（输入）
void human_move(char arr[ROW][LINE], int row, int line);
//电脑行动（随机输入）
void computer_move(char arr[ROW][LINE], int row, int line);
//判断输赢
char is_win(char arr[ROW][LINE], int row, int line);