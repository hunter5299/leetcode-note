#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��

����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��


*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//����һ���Ǵ��м俪ʼ�ԳƵģ�����Ѱ��������м��㣬Ȼ�������м䵽β���Ľ�㷴ת���ٴ�ͷ�����м俪ʼ
		//���αȽϣ���ȫ��ȣ����ǻ���

		//1.����ָ��Ѱ���е�

		ListNode* fast = A, *slow = A;

		while (fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* mid = slow;

		//2.ͷ�巨��ת�м䵽ĩβ�Ľ��

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

		//3.�ӱ�ͷ���м俪ʼ�Ա�

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