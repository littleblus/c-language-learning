#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game() {
	char myboard[ROWS][COLS];
	char playboard[ROWS][COLS];
	srand((unsigned int)time(NULL));
	initboard(myboard, playboard, ROWS, COLS);
	setmines(myboard, ROWS, COLS);
	//print(myboard, ROWS, COLS);
	print(playboard, ROWS, COLS);
	while (1) {
		usercheck(myboard, playboard, ROWS, COLS);
		//print(myboard, ROWS, COLS);
		print(playboard, ROWS, COLS);
		if (iswin(playboard, ROWS, COLS) != 0)
			break;
	}
	if (iswin(playboard, ROWS, COLS) == 1)
		printf("¹§Ï²Äú£¬É¨À×³É¹¦£¡\n");
	else {
		printf("ºÜÒÅº¶£¬Äú±»Õ¨ËÀÁË!\n");
		print(myboard, ROWS, COLS);
	}
}

void menu() {
	printf("***********É¨À×ÓÎÏ·*********\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
	printf("ÇëÊäÈëÊı×Ö>");
}

int main() {
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ÊäÈë´íÎó\n");
			break;
		}
	} while (input);
	printf("ÓÎÏ·½áÊø\n");

	return 0;
}