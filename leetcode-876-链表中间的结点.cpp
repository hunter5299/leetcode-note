#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣*/

struct ListNode* middleNode(struct ListNode* head){
	/*����ָ��*/
	struct ListNode* low, *fast;
	low = head;
	fast = head;
	while (fast && fast->next){
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}