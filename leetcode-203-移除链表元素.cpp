#define _CRT_SECURE_NO_WARNINGS 1
/*����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��*/

#include"ListNode.h"
/*ʹ���ڱ����*/
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL){
		return head;
	}
	struct ListNode* gaurd = (struct ListNode*)malloc(sizeof(struct ListNode));
	gaurd->next = head;
	struct ListNode* t;
	t = gaurd;
	while (t->next){
		if (head->val == val){
			t->next = head->next;
			free(head);
			head = t->next;
		}
		else{
			t = t->next;
			head = head->next;
		}
	}
	head = gaurd->next;
	free(gaurd);
	return head;
}