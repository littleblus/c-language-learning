#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char arr[ROW][LINE];
	init(arr,ROW,LINE);
	print(arr, ROW, LINE);
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
			printf("��Ϸ��ʼ\n");
			game();
			goto end;
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