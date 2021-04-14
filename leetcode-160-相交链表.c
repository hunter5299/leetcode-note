#define _CRT_SECURE_NO_WARNINGS 1
/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
*/
#include"ListNode.h"
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	/*�ȼ������������Ȳ�k��Ȼ�󳤵���������k������һ����*/
	struct ListNode* cur;
	int lenA = 0, lenB = 0, k = 0;

	cur = headA;
	//������������ĳ���
	while (cur){
		lenA++;
		cur = cur->next;
	}
	cur = headB;
	while (cur){
		lenB++;
		cur = cur->next;
	}

	//����������K��

	//��b����a���򽻻�������ͷ��ָ�򣬷���������߲�
	if (lenA<lenB){
		cur = headA;
		headA = headB;
		headB = cur;
	}
	k = lenA>lenB ? lenA - lenB : lenB - lenA;
	while (k--){
		headA = headA->next;
	}

	//��������ͬʱ���Աȵ�ַ
	while (headA && headB){
		if (headB == headA){
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}