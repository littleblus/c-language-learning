//
// Created by 10604 on 2023/3/26.
//
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
    if(root == NULL)
        return 0;
    int leftdepth = maxDepth(root->left);
    int rightdepth = maxDepth(root->right);

    return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}