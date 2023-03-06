#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//链表分割
struct ListNode* partition(struct ListNode* pHead, int x) {
    //哨兵位
    struct ListNode* guardlow = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* guardhigh = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* lowlist = guardlow, * highlist = guardhigh;
    lowlist->next = guardlow->next = NULL;
    highlist->next = guardhigh->next = NULL;
    //依次尾插
    struct ListNode* cur = pHead;
    while (cur) {
        if (cur->val < x) {
            lowlist->next = cur;
            lowlist = lowlist->next;
        }
        else {
            highlist->next = cur;
            highlist = highlist->next;
        }
        cur = cur->next;
    }
    highlist->next = NULL;
    lowlist->next = guardhigh->next;
    struct ListNode* ret = guardlow->next;
    free(guardlow);
    free(guardhigh);
    return ret;
}

//链表的回文序列
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
bool chkPalindrome(struct ListNode* A) {
    // write code here
    struct ListNode* mid = middleNode(A);
    struct ListNode* rmid = reverseList(mid);
    while (rmid) {
        if (A->val != rmid->val) {
            return false;
        }
        A = A->next;
        rmid = rmid->next;
    }
    return true;
}

//相交链表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!(headA && headB)) {
        return NULL;
    }
    struct ListNode* cur1 = headA, * cur2 = headB;
    int len1 = 1, len2 = 1;
    while (cur1->next) {
        cur1 = cur1->next;
        len1++;
    }
    while (cur2->next) {
        cur2 = cur2->next;
        len2++;
    }
    if (cur1 != cur2) {
        return NULL;
    }
    int gap = abs(len1 - len2);
    if (len1 > len2) {
        struct ListNode* tmp = headB;
        headB = headA;
        headA = tmp;
    }
    while (--gap >= 0) {
        headB = headB->next;
    }
    while (headA && headB) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

//判断单链表是否带环
bool hasCycle(struct ListNode* head) {
    //快慢指针追逐
    if (!head) {
        return false;
    }
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next) {
        fast = fast->next;
        if (fast == slow) {
            return true;
        }
        fast = fast->next;
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
    }
    return false;
}