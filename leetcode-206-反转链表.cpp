#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*��תһ��������*/

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL){
		return head;
	}
	/*�Ե�һ����㣬������Ľ������ͷ�������ת*/
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

