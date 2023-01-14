#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
int flag = 0;
void initboard(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col) {
	memset(myboard, ' ', row * col * sizeof(char));
	memset(playboard, '*', row * col * sizeof(char));
}

void print(char playboard[ROWS][COLS], int row, int col) {
	for (int i = 0; i < row - 1; i++) {
		printf(" %d ", i);
		printf("|");
	}
	printf("\n");
	for (int i = 1; i < row - 1; i++) {
		for (int j = 0; j < (row - 1) * 3 + row - 1; j++) {
			printf("-");
		}
		printf("\n");
		printf(" %d ", i);
		printf("|");
		for (int j = 1; j < col - 1; j++) {
			printf(" %c ", playboard[i][j]);
			printf("|");
		}
		printf("\n");
	}
}

void setmines(char myboard[ROWS][COLS], int row, int col) {
	int count = MINE;
	while (count) {
		int i = rand() % (row - 2) + 1;
		int j = rand() % (col - 2) + 1;
		if (myboard[i][j] == ' ') {
			myboard[i][j] = '*';
			count--;
		}
	}
}

static int countmine(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col, int i, int j) {
	int count = 0;
	for (int a = i - 1; a <= i + 1; a++) {
		for (int b = j - 1; b <= j + 1; b++) {
			if (myboard[a][b] == '*')
				count++;
		}
	}
	return count;
}

void usercheck(char myboard[ROWS][COLS], char playboard[ROWS][COLS], int row, int col) {
	int i = 0, j = 0;
	int count;
start:
	printf("输入想要排查雷的坐标>");
	scanf("%d%d", &i, &j);
	if (i<1 || i>row - 2 || j<1 || j>col - 2) {
		printf("输入超出范围，请重新输入！\n");
		goto start;
	}
	if (myboard[i][j] == '*') {
		flag = -1;
		return;
	}
	if (playboard[i][j] != '*') {
		printf("此坐标您已经排查过了，请重新输入！\n");
		goto start;
	}
	else {
		count = countmine(myboard, playboard, row, col, i, j);
		if (count != 0)
			playboard[i][j] = count + '0';
		else
			playboard[i][j] = ' ';
	}
}

int iswin(char playboard[ROWS][COLS], int row, int col) {
	int count = 0;
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			if (playboard[i][j] == '*')
				count++;
		}
	}
	if (count == MINE)
		flag = 1;
	return flag;
}