#define _CRT_SECURE_NO_WARNINGS 1

#include"ListNode.h"
//��Ŀͬleetcode-237һģһ��
/*
ʵ��һ���㷨��ɾ�����������м��ĳ���ڵ㣨�����ǵ�һ�������һ���ڵ㣩���ٶ���ֻ�ܷ��ʸýڵ㡣
*/
if (node == NULL){
	return;
}
//��ý�node����ǰһ�curָ���һ��
struct ListNode* prev = node, *cur = node->next;
//
while (cur->next != NULL){
	prev->val = cur->val;
	prev = prev->next;
	cur = cur->next;
}
//ɾ�����һ���ڵ�
prev->val = cur->val;
prev->next = NULL;
free(cur);