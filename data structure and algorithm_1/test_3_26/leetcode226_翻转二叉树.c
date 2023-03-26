//
// Created by 10604 on 2023/3/26.
//

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
    if(root == NULL)
        return root;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}