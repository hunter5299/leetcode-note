#define _CRT_SECURE_NO_WARNINGS 1

#include"ListNode.h"
//题目同leetcode-237一模一样
/*
实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。
*/
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