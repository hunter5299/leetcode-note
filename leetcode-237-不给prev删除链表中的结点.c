#define _CRT_SECURE_NO_WARNINGS 1

/*
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
*/
#include"ListNode.h"
//由于不能获得node的前一个结点，删除只能是逻辑上的删除，即将后面结点的值往前依次覆盖，
//再删除最后一个结点
void deleteNode(struct ListNode* node) {
	if (node == NULL){
		return;
	}
	//获得将node当成前一项，cur指向后一项
	struct ListNode* prev = node, *cur = node->next;
	//
	while (cur->next != NULL){
		prev->val = cur->val;
		prev = prev->next;
		cur = cur->next;
	}
	//删除最后一个节点
	prev->val = cur->val;
	prev->next = NULL;
	free(cur);
}