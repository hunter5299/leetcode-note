#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。*/

struct ListNode* middleNode(struct ListNode* head){
	/*快慢指针*/
	struct ListNode* low, *fast;
	low = head;
	fast = head;
	while (fast && fast->next){
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}