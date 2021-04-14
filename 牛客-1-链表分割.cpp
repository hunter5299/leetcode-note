#define _CRT_SECURE_NO_WARNINGS 1
/*
现有一链表的头指针 ListNode* pHead，给一定值x，
编写一段代码将所有小于x的结点排在其余结点之前，
且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
*/
#include"ListNode.h"
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		/*将小于x的结点与大于x的结点分别放入两个链表，然后再将大链表尾插到小链表*/
		ListNode* lessHead, *lessTail;
		lessTail = lessHead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* greatHead, *greatTail;
		greatHead = greatTail = (ListNode*)malloc(sizeof(ListNode));

		while (pHead){
			if (pHead->val < x){
				lessTail->next = pHead;
				lessTail = lessTail->next;
			}
			else{
				greatTail->next = pHead;
				greatTail = greatTail->next;
			}
			pHead = pHead->next;
		}

		lessTail->next = greatHead->next;

		/*关键一步。必须把最后一个结点的next置为NULL，否则结构会打乱*/
		greatTail->next = NULL;

		ListNode* ret = lessHead->next;
		free(lessHead);
		free(greatHead);

		return ret;
	}
};