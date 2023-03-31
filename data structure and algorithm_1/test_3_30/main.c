#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinaryTree.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

//二叉树的前序遍历
int BinaryTreeSize(struct TreeNode* root) {
    if (!root)
        return 0;
    return BinaryTreeSize(root->left)
        + BinaryTreeSize(root->right) + 1;
}

void prevord(struct TreeNode* root, int* arr, int* pi) {
    if (!root)
        return;
    arr[(*pi)++] = root->val;
    prevord(root->left, arr, pi);
    prevord(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = BinaryTreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * *returnSize);
    int i = 0;
    prevord(root, arr, &i);
    return arr;
}



//对称二叉树
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right)
        return true;
    if (!(left && right))
        return false;
    if (left->val != right->val)
        return false;
    return _isSymmetric(left->left, right->right)
        && _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return _isSymmetric(root->left, root->right);
}



//另一颗树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //当两棵树同步访问空子树返回真，只有一个空返回假
    if (!p && !q)
        return true;
    else if (!(p && q))
        return false;
    if (p->val != q->val)
        return false;


    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    //前序遍历
    if (!root)
        return false;
    if (root->val == subRoot->val) {
        if (isSameTree(root, subRoot))
            return true;
    }
    bool left = isSubtree(root->left, subRoot);
    bool right = isSubtree(root->right, subRoot);
    return left || right;
}



//二叉树的构建及遍历
typedef char BTDataType;

typedef struct BinaryTreeNode {
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
} BTNode;

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

BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
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

void BinaryTreeDestory(BTNode* root) {
    //后序
    if (!root)
        return;
    BinaryTreeDestory(root->_left);
    BinaryTreeDestory(root->_right);
    free(root);
    root = NULL;
}

void BinaryTreeInOrder(BTNode* root) {
    if (!root) {
        return;
    }
    BinaryTreeInOrder(root->_left);
    printf("%c ", root->_data);
    BinaryTreeInOrder(root->_right);
}

int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    BTNode* tree = BinaryTreeCreate(str, &i);
    BinaryTreeInOrder(tree);
    printf("\n");
    BinaryTreeDestory(tree);
    tree = NULL;
    return 0;
}