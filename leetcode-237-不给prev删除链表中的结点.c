#define _CRT_SECURE_NO_WARNINGS 1

/*
���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㡣���뺯����Ψһ����Ϊ Ҫ��ɾ���Ľڵ� ��
*/
#include"ListNode.h"
//���ڲ��ܻ��node��ǰһ����㣬ɾ��ֻ�����߼��ϵ�ɾ���������������ֵ��ǰ���θ��ǣ�
//��ɾ�����һ�����
void deleteNode(struct ListNode* node) {
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
}