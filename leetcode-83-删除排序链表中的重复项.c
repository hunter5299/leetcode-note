#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ�����������е�����������������ͷ�ڵ� head ������ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��

����ͬ�����������еĽ������


*/
#include"ListNode.h"
struct ListNode* deleteDuplicates(struct ListNode* head){

	struct ListNode* cur = head;

	while (cur&& cur->next){
		//����ǰ������һ��ֵ��ȣ���ɾ����һ��
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