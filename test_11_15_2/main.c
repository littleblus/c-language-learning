#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char ret;
	//����*�����Ӯ��break
	//����#������Ӯ��break
	//����C��������Ϸ
	//����T��ƽ�֣�break
	char arr[ROW][LINE];
	init(arr,ROW,LINE);
	print(arr, ROW, LINE);
	srand((unsigned int)time(NULL));
	while (1) {
		human_move(arr, ROW, LINE);
		print(arr, ROW, LINE);
		ret = is_win(arr, ROW, LINE);
		if (ret == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (ret == '#') {
			printf("����Ӯ\n");
			break;
		}
		else if (ret == 'T') {
			printf("ƽ��\n");
			break;
		}
		computer_move(arr, ROW, LINE);
		print(arr, ROW, LINE);
		ret = is_win(arr, ROW, LINE);
		if (ret == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (ret == '#') {
			printf("����Ӯ\n");
			break;
		}
		else if (ret == 'T') {
			printf("ƽ��\n");
			break;
		}
		printf("\n");
	}
}

//�ж���������Ƿ�����Ϸ
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
			printf("��Ϸ��ʼ\n\n");
			game();
			goto start;
		case 0:
			printf("��Ϸ����\n");
			goto end;
		default:
			printf("�Ƿ����룬����������\n");
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