#define _CRT_SECURE_NO_WARNINGS 1

#include"treeNode.h"
/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/

int minDepth(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpl = minDepth(root->left);
	int dpr = minDepth(root->right);
	//若有子树深度为0，则返回另一子树的深度+本层的度数1
	if (dpl == 0){
		return dpr + 1;
	}
	else if (dpr == 0){
		return dpl + 1;
	}
	else{
		//返回最短路径
		return dpr>dpl ? dpl + 1 : dpr + 1;
	}
}