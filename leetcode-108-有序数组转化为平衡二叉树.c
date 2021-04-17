#define _CRT_SECURE_NO_WARNINGS 1
#include"treeNode.h"


struct TreeNode* createNode(int val){
	struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = val;
	t->left = NULL;
	t->right = NULL;
	return t;
}

//letf��right�����ڵݹ������Ԫ���������е�����Χ
struct TreeNode* createTree(int *nums, int left, int right){
		//��ȡ�����±�λ��
	int root = left + (right - left) / 2;
	if (root>right || root<left){
		return NULL;
	}
	struct TreeNode * node = createNode(nums[root]);
	//������
	node->left = createTree(nums, left, root - 1);
	//������
	node->right = createTree(nums, root + 1, right);

	return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	//ƽ�����������������Ķ�����������������ƽ�������������ڵ���������м�numsSize/2��
	//��ǰ��������������������������
	int rootPos = (numsSize - 1) / 2;

	//���������
	struct TreeNode* root = createNode(nums[rootPos]);

	//�ݹ鴴����������
	struct TreeNode* leftC = createTree(nums, 0, rootPos - 1);
	struct TreeNode* rightC = createTree(nums, rootPos + 1, numsSize - 1);

	root->left = leftC;
	root->right = rightC;

	return root;
}