//
// Created by 10604 on 2023/3/30.
//

#include "BinaryTree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

BTNode* BuyNewNode(BTDataType val) {
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (!tmp) {
		perror("malloc failed");
		return NULL;
	}
	tmp->_data = val;
	tmp->_left = tmp->_right = NULL;
	return tmp;
}

BTNode* BinaryTreeCreate(BTDataType* a, int *pi) {
	assert(a);
	if (a[*pi] == '#') {
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (!root) {
		perror("malloc failed");
		return NULL;
	}
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);
	return root;
}

void BinaryTreeDestory(BTNode *root) {
	//后序
	if (!root)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode *root) {
	if (!root)
		return 0;
	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode *root) {
	if (!root)
		return 0;
	if (!root->_left && !root->_right)
		return 1;
	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode *root, int k) {
	if (!root)
		return 0;
	if (k == 1)
		return 1;
	int leftsize = BinaryTreeLevelKSize(root->_left, k - 1);
	int rightsize = BinaryTreeLevelKSize(root->_right, k - 1);
	return leftsize + rightsize;
}

BTNode* BinaryTreeFind(BTNode *root, BTDataType x) {
	if (!root)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right)
		return right;
	return NULL;
}

void BinaryTreePrevOrder(BTNode *root) {
	if (!root) {
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode *root) {
	if (!root) {
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreePostOrder(BTNode *root) {
	if (!root) {
		printf("NULL ");
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode *root) {
	Queue tree;
	QInit(&tree);
	//将根节点入队列
	if(root)
		QPush(&tree, root);
	while (!QEmpty(&tree)) {
		//出队头
		BTNode* tmp = QFront(&tree);
		QPop(&tree);
		printf("%c ", tmp->_data);
		//入tmp的左右子树
		if (tmp->_left)
			QPush(&tree, tmp->_left);
		if (tmp->_right)
			QPush(&tree, tmp->_right);
	}
	QDestory(&tree);
}

bool BinaryTreeComplete(BTNode *root) {
	Queue tree;
	QInit(&tree);
	if (root)
		QPush(&tree, root);
	while (!QEmpty(&tree)) {
		//出队头
		BTNode* tmp = QFront(&tree);
		QPop(&tree);
		//入左右子树
		if (tmp == NULL) {
			break;
		}
		else {
			QPush(&tree, tmp->_left);
			QPush(&tree, tmp->_right);
		}
	}
	//判断是否为完全二叉树
	while (!QEmpty(&tree)) {
		BTNode* tmp = QFront(&tree);
		QPop(&tree);
		if (tmp) {
			QDestory(&tree);
			return false;
		}
	}
	QDestory(&tree);
	return true;
}