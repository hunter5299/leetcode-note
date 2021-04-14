#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
��дһ�δ��뽫����С��x�Ľ������������֮ǰ��
�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
*/
#include"ListNode.h"
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		/*��С��x�Ľ�������x�Ľ��ֱ������������Ȼ���ٽ�������β�嵽С����*/
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

		/*�ؼ�һ������������һ������next��ΪNULL������ṹ�����*/
		greatTail->next = NULL;

		ListNode* ret = lessHead->next;
		free(lessHead);
		free(greatHead);

		return ret;
	}
};