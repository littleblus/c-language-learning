#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void game()
{
	printf("扫雷游戏\n");
}

void test()
{
	int input = 0;
	do {
		menu();
		printf("请选择是否开始游戏>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}