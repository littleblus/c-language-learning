#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void game()
{
	printf("ɨ����Ϸ\n");
}

void test()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ���Ƿ�ʼ��Ϸ>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}