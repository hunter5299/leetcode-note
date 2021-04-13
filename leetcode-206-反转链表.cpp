#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*反转一个单链表。*/

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL){
		return head;
	}
	/*对第一个结点，将后面的结点依次头插完成逆转*/
	struct ListNode* t, *rest;
	t = head->next;
	head->next = NULL;
	while (t){
		rest = t->next;
		t->next = head;
		head = t;
		t = rest;
	}
	return head;
}

