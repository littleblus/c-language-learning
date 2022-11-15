#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char ret;
	//返回*，玩家赢，break
	//返回#，电脑赢，break
	//返回C，继续游戏
	//返回T，平局，break
	char arr[ROW][LINE];
	init(arr,ROW,LINE);
	print(arr, ROW, LINE);
	srand((unsigned int)time(NULL));
	while (1) {
		human_move(arr, ROW, LINE);
		print(arr, ROW, LINE);
		ret = is_win(arr, ROW, LINE);
		if (ret == '*') {
			printf("玩家赢\n");
			break;
		}
		else if (ret == '#') {
			printf("电脑赢\n");
			break;
		}
		else if (ret == 'T') {
			printf("平局\n");
			break;
		}
		computer_move(arr, ROW, LINE);
		print(arr, ROW, LINE);
		ret = is_win(arr, ROW, LINE);
		if (ret == '*') {
			printf("玩家赢\n");
			break;
		}
		else if (ret == '#') {
			printf("电脑赢\n");
			break;
		}
		else if (ret == 'T') {
			printf("平局\n");
			break;
		}
		printf("\n");
	}
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
			printf("游戏开始\n\n");
			game();
			goto start;
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