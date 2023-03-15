#include <stdio.h>
#include <stdlib.h>

struct ListNode *detectCycle(struct ListNode *head) {
    //检测是否有环
	struct ListNode* slow, *fast;
	slow = fast = head;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			//有环
			struct ListNode* meet, *start;
			meet = slow;
			start = head;
			while(meet != start) {
				meet = meet->next;
				start = start->next;
			}
			return meet;
		}
	}
	//无环
	return NULL;
}

struct Node {
     int val;
     struct Node *next;
     struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
	if(!head) {
		return NULL;
	}
	struct Node* cur = head; 
	struct Node* guard = (struct Node*)malloc(sizeof(struct Node));//哨兵位
	guard->val = -1;
	struct Node* prev = guard;
	while(cur) {
		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->val = cur->val;//拷贝值
		prev->next = newnode;
		prev = newnode;
		cur = cur->next;
	}
	prev->next = NULL;
	cur = head;
	struct Node* curnew = guard->next;
	while(cur) {
		//找到random指向的pos，并拷贝
		if(cur->random == NULL) {
			curnew->random = NULL;
			curnew = curnew->next;
		}
		else {
			int pos = 0;
			struct Node* search = head;
			while(1) {
				if(search == cur->random) {
					break;
				}
				else {
					search = search->next;
					pos++;
				}
			}
			struct Node* ret = guard->next;
			while(pos--) {
				ret = ret->next;
			}
			curnew->random = ret;
			curnew = curnew->next;
		}
		//cur递增
		cur = cur->next;
	}
	struct Node* ret = guard->next;
	free(guard);
	guard = NULL;
	return ret;
}

int main() {
	struct Node n1 = { 0 };
	struct Node n2 = { 0 };
	struct Node n3 = { 0 };
	struct Node n4 = { 0 };
	struct Node n5 = { 0 };

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;

	n1.val = 7;
	n2.val = 13;
	n3.val = 11;
	n4.val = 10;
	n5.val = 1;

	n1.random = NULL;
	n2.random = &n1;
	n3.random = &n5;
	n4.random = &n3;
	n5.random = &n1;

	struct Node* new = copyRandomList(&n1);

	return 0;
}