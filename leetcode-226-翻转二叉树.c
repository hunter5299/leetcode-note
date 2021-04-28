#define _CRT_SECURE_NO_WARNINGS 1
#include"treeNode.h"
/*
翻转一棵二叉树。

示例：

输入：

4
/   \
2     7
/ \   / \
1   3 6   9
输出：

4
/   \
7     2
/ \   / \
9   6 3   1


*/

struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL){
		return NULL;
	}
	struct TreeNode* t = root->left;
	root->left = root->right;
	root->right = t;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}