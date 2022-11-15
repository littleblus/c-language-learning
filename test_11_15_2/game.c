#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("********************\n");
	printf("*****  1.play  *****\n");
	printf("*****  0.exit  *****\n");
	printf("********************\n");
	printf("请输入0或1以继续>");
}

void init(char arr[ROW][LINE],int row,int line) 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			arr[i][j] = ' ';
		}
	}
}

void print(char arr[ROW][LINE], int row, int line)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			printf(" %c ", arr[i][j]);
			if(j<line-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < line; j++) {
				printf("---", arr[i][j]);
				if (j < line - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void human_move(char arr[ROW][LINE], int row, int line)
{
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入落子坐标>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= line) {
			if (arr[x - 1][y - 1] == ' ') {
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用，请重新落子\n");
		}
		else
			printf("输入错误，请输入棋盘中坐标！\n");
	}
}

void computer_move(char arr[ROW][LINE], int row, int line)
{
	printf("电脑落子\n");
	while (1) {
		int x = rand() % row;
		int y = rand() & line;
		if (arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
	}
}

char is_full(char arr[ROW][LINE], int row, int line) 
{
	for (int i = 0; i < row ; i++) {
		for (int j = 0; j < line ; j++) {
			if (arr[i][j] == ' ') {
				return 'C';
			}
		}
	}
	return 'T';
}

char is_win(char arr[ROW][LINE], int row, int line)
{
	//判断横行连线
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < line-1; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j]!=' ') {
				if (j == line - 2)
					return arr[i][j];
				continue;
			}
			break;
		}
	}
	//判断竖行连线
	for (int j = 0; j < line - 1; j++) {
		for (int i = 0; i < row - 1; i++) {
			if (arr[i][j] == arr[i+1][j] && arr[i][j]!=' ') {
				if (i == row - 2)
					return arr[i][j];
				continue;
			}
			break;
		}
	}
	//判断对角线
	for (int i = 0, j = 0; i < row - 1, j < line - 1; i++, j++) {
		if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != ' ') {
			if (i == row - 2)
				return arr[i][j];
			continue;
		}
		break;
	}
	for (int i = row-1, j = 0; i >=0, j < line - 1; i--, j++) {
		if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] != ' ') {
			if (j == line - 2)
				return arr[i][j];
			continue;
		}
		break;
	}
	//判断是否平局,非平局就继续
	return is_full(arr, ROW, LINE);
}