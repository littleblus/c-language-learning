#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//移除链表元素
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (!head) {
		return NULL;
	}
	int flag = 0;
	struct ListNode* new = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* cur = head;
	while (cur) {
		if (cur->val == val) {
			cur = cur->next;
		}
		else {
			if (flag == 0) {
				tail = new = cur;
				cur = cur->next;
				tail->next = NULL;
				flag = 1;
			}
			else {
				tail->next = cur;
				cur = cur->next;
				tail = tail->next;
				tail->next = NULL;
			}
		}
	}
	return new;
}

//反转单链表
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while (cur) {
		struct ListNode* tmp = prev;
		prev = cur;
		cur = cur->next;
		prev->next = tmp;
	}
	return prev;
}

//链表查找中间节点
struct ListNode* middleNode(struct ListNode* head) {
	//快慢指针
	if (head == NULL) {
		return NULL;
	}
	struct ListNode* slow, * fast;
	slow = fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//输出倒数第k个节点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	if (pListHead == NULL) {
		return NULL;
	}
	struct ListNode* slow, * fast;
	slow = fast = pListHead;
	while (k--) {
		//判断是否k大于链表长度
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//合并两个升序链表
struct ListNode* CreateNewNode(int val) {
	struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
	new->val = val;
	new->next = NULL;
	return new;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1) {
		return list2;
	}
	if (!list2) {
		return list1;
	}
	struct ListNode* prev1, * cur1, * prev2, * cur2, * ret, * curnew;
	int flag = 0;
	prev1 = cur1 = list1;
	prev2 = cur2 = list2;
	while (cur1 && cur2) {
		int val = 0;
		if (cur1->val >= cur2->val) {
			val = cur2->val;
			prev2 = cur2;
			cur2 = cur2->next;
			free(prev2);
		}
		else {
			val = cur1->val;
			prev1 = cur1;
			cur1 = cur1->next;
			free(prev1);
		}
		if (flag == 0) {
			ret = curnew = CreateNewNode(val);
			flag = 1;
		}
		else {
			curnew = curnew->next = CreateNewNode(val);
		}
	}
	if (!cur1) {
		//cur2全部插入后面
		while (cur2) {
			curnew->next = cur2;
			cur2 = cur2->next;
			curnew = curnew->next;
		}
	}
	else {
		//cur1全部插入后面
		while (cur1) {
			curnew->next = cur1;
			cur1 = cur1->next;
			curnew = curnew->next;
		}
	}
	return ret;
}