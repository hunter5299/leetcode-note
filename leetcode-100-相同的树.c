#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
*/
 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
#define bool int 
#define true 1
#define false 0
 //从上往下递归对比两颗树的对应结点
 bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	 //若都是空子树，返回true
	 if (p == NULL && q == NULL){
		 return true;
	 }
	 //其中一方为空，false
	 if (p == NULL || q == NULL){
		 return false;
	 }

	 //对比结点的值，若不相等则直接往上返回false，不用往下进行对比了
	 if (p->val != q->val){
		 return false;
	 }

	 //递归往下对比
	 bool retl = isSameTree(p->left, q->left);
	 bool retr = isSameTree(p->right, q->right);

	 //若两颗子树都是true，则返回true
	 return retl && retr;
 }