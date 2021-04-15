#define _CRT_SECURE_NO_WARNINGS 1

/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

返回同样按升序排列的结果链表。


*/
#include"ListNode.h"
struct ListNode* deleteDuplicates(struct ListNode* head){

	struct ListNode* cur = head;

	while (cur&& cur->next){
		//若当前项与下一项值相等，则删除后一项
		if (cur->val == cur->next->val){
			struct ListNode* t = cur->next;
			cur->next = cur->next->next;
			free(t);
			t = NULL;
		}
		else{
			cur = cur->next;
		}
	}
	return head;
}