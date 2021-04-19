#define _CRT_SECURE_NO_WARNINGS 1
#include"treeNode.h"
/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
*/


/*能完成功能，但是冗余代码太多*/
int childTreeDp1(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpR = childTreeDp(root->right);
	int dpL = childTreeDp(root->left);

	//若其中有一方子节点深度差为-1，则表示返回的高度差>1，不是平衡二叉树
	if (dpR == -1 || dpL == -1){
		return -1;
	}

	int ret = 0;
	//交换深度更深的结点到dpR，方便计算
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
	//右子树的深度
	int depr = childTreeDp(root->right);
	//左子树的深度
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



/*优化后*/
int checkTreeDp(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpR = checkTreeDp(root->right);
	int dpL = checkTreeDp(root->left);

	//若其中有一方子节点深度差为-1，则表示返回的高度差>1，不是平衡二叉树
	if (dpR == -1 || dpL == -1){
		return -1;
	}

	int ret = 0;
	//交换深度更深的结点到dpR，方便计算
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
	//递归检查每一颗子树的深度，若深度差大于1，则返回-1；否则返回平衡二叉树的最大深度
	int ret = checkTreeDp(root);

	if (ret == -1){
		flag = false;
	}
	else{
		flag = true;
	}
	return flag;
}