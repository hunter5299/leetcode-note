#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ��
*/
 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
#define bool int 
#define true 1
#define false 0
 //�������µݹ�Ա��������Ķ�Ӧ���
 bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	 //�����ǿ�����������true
	 if (p == NULL && q == NULL){
		 return true;
	 }
	 //����һ��Ϊ�գ�false
	 if (p == NULL || q == NULL){
		 return false;
	 }

	 //�ԱȽ���ֵ�����������ֱ�����Ϸ���false���������½��жԱ���
	 if (p->val != q->val){
		 return false;
	 }

	 //�ݹ����¶Ա�
	 bool retl = isSameTree(p->left, q->left);
	 bool retr = isSameTree(p->right, q->right);

	 //��������������true���򷵻�true
	 return retl && retr;
 }