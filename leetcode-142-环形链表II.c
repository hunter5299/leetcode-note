



#define _CRT_SECURE_NO_WARNINGS 1

/*3.求环的入口点？
设：链表头到环入口点的距离是L
环的大小是C
入口到相遇点的距离是X
slow到入口时，fast已经走了N圈
当slow进环后，一圈内就会被fast追上
则到相遇时，slow走了L + X的距离
fast走了L + N*C + X

fast走了2倍slow的路程
此时得到一个等式 : 2(L + X) = L + N*C + X
		   = >      L = N*C - X;
即，一个指针meet从相遇点开始往后走，一个指针head从表头开始走
meet与head相遇的时候就是入口点*/
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* slow = head, *fast = head;

	while (fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow){
			/*根据公式 L = N*C - X ,
			即从相遇点往后到入口点的环的长度等于表头到入口点的
			长度，两位置同时往后走，相遇的时候就是环入口点*/
			struct ListNode* meet = fast;
			while (head != meet){
				head = head->next;
				meet = meet->next;
			}
			return head;
		}
	}
	return NULL;
}