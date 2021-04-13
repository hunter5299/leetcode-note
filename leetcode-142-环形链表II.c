



#define _CRT_SECURE_NO_WARNINGS 1

/*3.�󻷵���ڵ㣿
�裺����ͷ������ڵ�ľ�����L
���Ĵ�С��C
��ڵ�������ľ�����X
slow�����ʱ��fast�Ѿ�����NȦ
��slow������һȦ�ھͻᱻfast׷��
������ʱ��slow����L + X�ľ���
fast����L + N*C + X

fast����2��slow��·��
��ʱ�õ�һ����ʽ : 2(L + X) = L + N*C + X
		   = >      L = N*C - X;
����һ��ָ��meet�������㿪ʼ�����ߣ�һ��ָ��head�ӱ�ͷ��ʼ��
meet��head������ʱ�������ڵ�*/
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
			/*���ݹ�ʽ L = N*C - X ,
			����������������ڵ�Ļ��ĳ��ȵ��ڱ�ͷ����ڵ��
			���ȣ���λ��ͬʱ�����ߣ�������ʱ����ǻ���ڵ�*/
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