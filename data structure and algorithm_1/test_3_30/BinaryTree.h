#pragma once

#include <stdbool.h>

typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
} BTNode;

//创建一个二叉树节点
BTNode* BuyNewNode(BTDataType val);

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树，pi为全局数组下标
BTNode* BinaryTreeCreate(BTDataType* a, int *pi);

// 二叉树销毁
void BinaryTreeDestory(BTNode *root);

// 二叉树节点个数
int BinaryTreeSize(BTNode *root);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode *root);

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode *root, int k);

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode *root, BTDataType x);

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode *root);

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode *root);

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode *root);

// 层序遍历
void BinaryTreeLevelOrder(BTNode *root);

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode *root);