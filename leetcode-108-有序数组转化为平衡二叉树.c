#define _CRT_SECURE_NO_WARNINGS 1
#include"treeNode.h"


struct TreeNode* createNode(int val){
	struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = val;
	t->left = NULL;
	t->right = NULL;
	return t;
}

//letf与right是正在递归的子树元素在数组中的区域范围
struct TreeNode* createTree(int *nums, int left, int right){
		//获取根的下标位置
	int root = left + (right - left) / 2;
	if (root>right || root<left){
		return NULL;
	}
	struct TreeNode * node = createNode(nums[root]);
	//左子树
	node->left = createTree(nums, left, root - 1);
	//右子树
	node->right = createTree(nums, root + 1, right);

	return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	//平衡二叉树是中序遍历的二叉树排序树，且是平衡二叉树，则根节点必在数组中间numsSize/2；
	//根前面是左子树，跟后面是右子树
	int rootPos = (numsSize - 1) / 2;

	//创建根结点
	struct TreeNode* root = createNode(nums[rootPos]);

	//递归创建左右子树
	struct TreeNode* leftC = createTree(nums, 0, rootPos - 1);
	struct TreeNode* rightC = createTree(nums, rootPos + 1, numsSize - 1);

	root->left = leftC;
	root->right = rightC;

	return root;
}