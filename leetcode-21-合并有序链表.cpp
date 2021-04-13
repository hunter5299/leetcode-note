#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (!l1&&!l2){
		return NULL;
	}
	if (l1 == NULL){
		return l2;
	}
	else if (l2 == NULL){
		return l1;
	}
	struct ListNode* ret, *tmp;
	if (l1->val <= l2->val){
		ret = l1;
		l1 = l1->next;
	}
	else{
		ret = l2;
		l2 = l2->next;
	}
	tmp = ret;
	while (l1&&l2){
		if (l1->val < l2->val){
			ret->next = l1;
			l1 = l1->next;
		}
		else{
			ret->next = l2;
			l2 = l2->next;
		}
		ret = ret->next;
	}
	ret->next = l1 == NULL ? l2 : l1;
	return tmp;
}