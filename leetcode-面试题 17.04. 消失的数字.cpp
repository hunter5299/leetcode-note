#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������

ע�⣺�����������ԭ�������Ķ�
*/
int missingNumber(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int ret = 0, arr = 0;
	int i;
	//��0��nums�������
	for (i = 0; i<numsSize; i++){
		arr ^= nums[i];
	}
	//��0��nums+1�������
	for (i = 0; i<numsSize + 1; i++){
		ret ^= i;
	}
	//��������õ�ȱʧ������
	ret = ret^arr;
	return ret;
}