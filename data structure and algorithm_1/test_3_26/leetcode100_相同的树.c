//
// Created by 10604 on 2023/3/26.
//

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    //当两棵树同步访问空子树返回真，只有一个空返回假
    if (!p && !q)
        return true;
    else if (!(p && q))
        return false;
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}