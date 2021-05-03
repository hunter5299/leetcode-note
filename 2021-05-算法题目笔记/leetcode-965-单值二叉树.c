#define _CRT_SECURE_NO_WARNINGS 1
#include"TreeNode.h"
/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
*/

bool getChildVal(int val, struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	bool flag = val == root->val;
	//���˽ڵ�ֵ����ڵ�ֵ����ȣ���ֱ�ӷ���false����Լ���µ�ʱ��
	if (!flag){
		return false;
	}
	bool cleft = getChildVal(val, root->left);
	bool cright = getChildVal(val, root->right);

	return cleft && cright;
}
bool isUnivalTree(struct TreeNode* root){
	if (root == NULL){
		return false;
	}
	bool flag = getChildVal(root->val, root);
	return flag;
}