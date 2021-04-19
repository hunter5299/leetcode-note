#define _CRT_SECURE_NO_WARNINGS 1
#include"treeNode.h"
/*
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
*/


/*����ɹ��ܣ������������̫��*/
int childTreeDp1(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpR = childTreeDp(root->right);
	int dpL = childTreeDp(root->left);

	//��������һ���ӽڵ���Ȳ�Ϊ-1�����ʾ���صĸ߶Ȳ�>1������ƽ�������
	if (dpR == -1 || dpL == -1){
		return -1;
	}

	int ret = 0;
	//������ȸ���Ľ�㵽dpR���������
	if (dpR<dpL){
		int t = dpR;
		dpR = dpL;
		dpL = t;
	}
	if (dpR - dpL <= 1){
		ret = dpR>dpL ? dpR + 1 : dpL + 1;
	}
	else{
		ret = -1;
	}
	return ret;
}

bool isBalanced1(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	int flag = false;
	//�����������
	int depr = childTreeDp(root->right);
	//�����������
	int depl = childTreeDp(root->left);

	if (depr == -1 || depl == -1){
		return false;
	}
	if (depr>depl){
		if (depr - depl <= 1){
			flag = true;
		}
	}
	else{
		if (depl - depr <= 1){
			flag = true;
		}
	}
	return flag;
}



/*�Ż���*/
int checkTreeDp(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpR = checkTreeDp(root->right);
	int dpL = checkTreeDp(root->left);

	//��������һ���ӽڵ���Ȳ�Ϊ-1�����ʾ���صĸ߶Ȳ�>1������ƽ�������
	if (dpR == -1 || dpL == -1){
		return -1;
	}

	int ret = 0;
	//������ȸ���Ľ�㵽dpR���������
	if (dpR<dpL){
		int t = dpR;
		dpR = dpL;
		dpL = t;
	}
	if (dpR - dpL <= 1){
		ret = dpR>dpL ? dpR + 1 : dpL + 1;
	}
	else{
		ret = -1;
	}
	return ret;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	bool flag = false;
	//�ݹ���ÿһ����������ȣ�����Ȳ����1���򷵻�-1�����򷵻�ƽ���������������
	int ret = checkTreeDp(root);

	if (ret == -1){
		flag = false;
	}
	else{
		flag = true;
	}
	return flag;
}