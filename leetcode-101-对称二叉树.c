#define _CRT_SECURE_NO_WARNINGS 1

#include"treeNode.h"

//定义一个辅助函数，类似与求相同的子树
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

	//根据镜像的定义，即左子树的右子子树和右子树的左子树相等，左子树的左子树和右子树的右子树相等
	//即判断这两对树是否相等
	bool retl = che(left->right, right->left);
	bool retr = che(left->left, right->right);
	return retl && retr;
}

bool isSymmetric(struct TreeNode* root){
	return che(root->left, root->right);
}