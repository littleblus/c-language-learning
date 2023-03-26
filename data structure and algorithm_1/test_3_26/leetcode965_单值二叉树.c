//
// Created by 10604 on 2023/3/26.
//
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//leetcode:965 单值二叉树
bool isUnivalTree(struct TreeNode *root) {
    if (root == NULL)
        return true;
    if (root->left && root->val != root->left->val)
        return false;
    if (root->right && root->val != root->right->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}