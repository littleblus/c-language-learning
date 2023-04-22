#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

//�����������������Ҷ��֮��
int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root)
        return 0;
    int res = 0;
    //�Ƿ����ӽڵ�
    if (root->left || root->right) {
        //���ӽڵ��Ƿ�ΪҶ�ӽڵ�
        if (root->left && !root->left->left && !root->left->right)
            res += root->left->val;
        int lsum = sumOfLeftLeaves(root->left);
        int rsum = sumOfLeftLeaves(root->right);
        return res + lsum + rsum;
    }
    else
        return 0;
}

//���������Լɪ������
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
	//��ʼ����������
	Node* guard = BuyNode(0);
	Node* cur = guard;
	for (int i = 1; i <= n; i++) {
		Node* new = BuyNode(i);
		cur->next = new;
		cur = cur->next;
	}
	cur->next = guard->next;//��β���
	cur = guard->next;
	int count = 1;
	while (cur != cur->next) {//��֤��������1
		if (count != m) {//��һ����
			cur = cur->next;
			count++;
		}
		else {
			//ɾ���˽ڵ�
			//����һ�ڵ㻥��num
			int val = cur->num;
			cur->num = cur->next->num;
			cur->next->num = val;
			//ɾ����һ�ڵ�
			Node* tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
			//���ü�����
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