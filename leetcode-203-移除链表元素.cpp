#define _CRT_SECURE_NO_WARNINGS 1
/*给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。*/

#include"ListNode.h"
/*使用哨兵结点*/
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