#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "BinaryTree.h"

int main() {
	//char str[100] = "ABD##E#H##G##";
	char str[100] = "ABD##E##G##";

	int i = 0;
	BTNode* tree = BinaryTreeCreate(str, &i);

	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeLevelOrder(tree);
	printf("\n");

	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelKSize(tree, 2));

	if (BinaryTreeComplete(tree))
		printf("YES\n");
	else
		printf("NO\n");
	BinaryTreeDestory(tree);
	tree = NULL;
	return 0;
}