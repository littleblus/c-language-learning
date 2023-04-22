#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

//计算给定二叉树的左叶子之和
int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root)
        return 0;
    int res = 0;
    //是否有子节点
    if (root->left || root->right) {
        //左子节点是否为叶子节点
        if (root->left && !root->left->left && !root->left->right)
            res += root->left->val;
        int lsum = sumOfLeftLeaves(root->left);
        int rsum = sumOfLeftLeaves(root->right);
        return res + lsum + rsum;
    }
    else
        return 0;
}

//环形链表的约瑟夫问题
typedef struct listnode {
	int num;
	struct listnode* next;
}Node;

Node* BuyNode(int val) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp) {
		tmp->next = NULL;
		tmp->num = val;
		return tmp;
	}
	else
		return NULL;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	//初始化环形链表
	Node* guard = BuyNode(0);
	Node* cur = guard;
	for (int i = 1; i <= n; i++) {
		Node* new = BuyNode(i);
		cur->next = new;
		cur = cur->next;
	}
	cur->next = guard->next;//首尾相接
	cur = guard->next;
	int count = 1;
	while (cur != cur->next) {//保证人数大于1
		if (count != m) {//下一个人
			cur = cur->next;
			count++;
		}
		else {
			//删除此节点
			//与下一节点互换num
			int val = cur->num;
			cur->num = cur->next->num;
			cur->next->num = val;
			//删除下一节点
			Node* tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
			//重置计数器
			count = 1;
		}
	}
	free(guard);
	guard = NULL;
	printf("%d\n", cur->num);
	free(cur);
	cur = NULL;
	return 0;
}