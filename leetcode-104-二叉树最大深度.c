#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。*/
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