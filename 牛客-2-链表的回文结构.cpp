#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。


*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//回文一定是从中间开始对称的，首先寻找链表的中间结点，然后将链表中间到尾部的结点反转，再从头部与中间开始
		//依次比较，若全相等，则是回文

		//1.快慢指针寻找中点

		ListNode* fast = A, *slow = A;

		while (fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* mid = slow;

		//2.头插法反转中间到末尾的结点

		ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
		guard->next = NULL;
		ListNode* cur;
		cur = mid;

		while (cur){
			ListNode* next = cur->next;

			cur->next = guard->next;
			guard->next = cur;
			cur = next;
		}

		//3.从表头与中间开始对比

		cur = guard->next;
		while (A && cur){
			if (A->val != cur->val){
				return false;
			}
			A = A->next;
			cur = cur->next;
		}
		return true;
	}
};