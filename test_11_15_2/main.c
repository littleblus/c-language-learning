#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char arr[ROW][LINE];
	init(arr,ROW,LINE);
	print(arr, ROW, LINE);
}

//判断输入决定是否玩游戏
void test()
{
	int p = 0;

	do {
	start:
		menu();
		scanf("%d", &p);
		switch (p)
		{
		case 1:
			printf("游戏开始\n");
			game();
			goto end;
		case 0:
			printf("游戏结束\n");
			goto end;
		default:
			printf("非法输入，请重新输入\n");
			goto start;
		}
	} while (1);
end:;
}

int main()
{
	test();
	return 0;
}