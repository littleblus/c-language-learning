#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//ÒÆ³ýÁ´±íÔªËØ
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