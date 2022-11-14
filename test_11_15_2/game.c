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
			arr[i][j] = '*';
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
	}
}
