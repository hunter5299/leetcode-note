#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����*/
 struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;

};



int maxDepth(struct TreeNode* root){
	int deepl = 0, deepr;
	if (root == NULL){
		return 0;
	}
	deepl = maxDepth(root->left) + 1;
	deepr = maxDepth(root->right) + 1;
	return deepl>deepr ? deepl : deepr;
}