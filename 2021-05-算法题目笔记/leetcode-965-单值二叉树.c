#define _CRT_SECURE_NO_WARNINGS 1
#include"TreeNode.h"
/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/

bool getChildVal(int val, struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	bool flag = val == root->val;
	//若此节点值与根节点值不相等，则直接返回false，节约往下的时间
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