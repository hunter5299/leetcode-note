#define _CRT_SECURE_NO_WARNINGS 1

#include"treeNode.h"

//����һ����������������������ͬ������
//
bool che(struct TreeNode* left, struct TreeNode* right){
	if (left == NULL&&right == NULL){
		return true;
	}
	if (left == NULL || right == NULL){
		return false;
	}
	if (left->val != right->val){
		return false;
	}

	//���ݾ���Ķ��壬������������������������������������ȣ����������������������������������
	//���ж����������Ƿ����
	bool retl = che(left->right, right->left);
	bool retr = che(left->left, right->right);
	return retl && retr;
}

bool isSymmetric(struct TreeNode* root){
	return che(root->left, root->right);
}