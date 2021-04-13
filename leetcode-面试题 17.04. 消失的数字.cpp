#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

注意：本题相对书上原题稍作改动
*/
int missingNumber(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int ret = 0, arr = 0;
	int i;
	//从0到nums依次异或
	for (i = 0; i<numsSize; i++){
		arr ^= nums[i];
	}
	//从0到nums+1依次异或
	for (i = 0; i<numsSize + 1; i++){
		ret ^= i;
	}
	//两结果异或得到缺失的数字
	ret = ret^arr;
	return ret;
}