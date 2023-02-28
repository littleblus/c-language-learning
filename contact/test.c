#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu() {
	printf("************ 通讯录 ***************\n");
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
		printf("请选择>");
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
			printf("当前容量为:%d\n", con.capacity);
			break;
		case EXIT:
			savecon(&con);
			destorycon(&con);
			printf("关闭通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);

	return 0;
}