#define _CRT_SECURE_NO_WARNINGS 1

#include"treeNode.h"
/*
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

int minDepth(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	int dpl = minDepth(root->left);
	int dpr = minDepth(root->right);
	//�����������Ϊ0���򷵻���һ���������+����Ķ���1
	if (dpl == 0){
		return dpr + 1;
	}
	else if (dpr == 0){
		return dpl + 1;
	}
	else{
		//�������·��
		return dpr>dpl ? dpl + 1 : dpr + 1;
	}
}