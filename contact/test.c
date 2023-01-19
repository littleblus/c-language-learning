#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu() {
	printf("************ ͨѶ¼ ***************\n");
	printf("***** 1.add        2.del      *****\n");
	printf("***** 3.search     4.modify   *****\n");
	printf("***** 5.show       6.sort     *****\n");
	printf("***** 7.capacity   0.exit     *****\n");
	printf("***********************************\n");
}

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	CAPACITY,
};

int main() {
	int input = 0;
	Contact con;
	initcon(&con);
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			addcon(&con);
			break;
		case DEL:
			delcon(&con);
			break;
		case SEARCH:
			searchcon(&con);
			break;
		case MODIFY:
			modifycon(&con);
			break;
		case SHOW:
			showcon(&con);
			break;
		case SORT:
			sortcon(&con);
			break;
		case CAPACITY:
			printf("��ǰ����Ϊ:%d\n", con.capacity);
			break;
		case EXIT:
			savecon(&con);
			destorycon(&con);
			printf("�ر�ͨѶ¼\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);

	return 0;
}