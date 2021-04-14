#define _CRT_SECURE_NO_WARNINGS 1
/*
编写一个程序，找到两个单链表相交的起始节点。
*/
#include"ListNode.h"
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	/*先计算两个链表长度差k，然后长的链表先走k步，再一起走*/
	struct ListNode* cur;
	int lenA = 0, lenB = 0, k = 0;

	cur = headA;
	//计算两个链表的长度
	while (cur){
		lenA++;
		cur = cur->next;
	}
	cur = headB;
	while (cur){
		lenB++;
		cur = cur->next;
	}

	//长链表先走K步

	//若b长于a，则交换两个表头的指向，方便后面先走步
	if (lenA<lenB){
		cur = headA;
		headA = headB;
		headB = cur;
	}
	k = lenA>lenB ? lenA - lenB : lenB - lenA;
	while (k--){
		headA = headA->next;
	}

	//两个链表同时向后对比地址
	while (headA && headB){
		if (headB == headA){
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}