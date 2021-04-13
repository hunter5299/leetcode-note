#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int removeElement(int* nums, int numsSize, int val){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int i = 0;
	int n = numsSize;

	while (i < n) {
		//若相等，则和最后一个元素交换，
		if (nums[i] == val) {
			nums[i] = nums[n - 1];
			n--;
		}
		else {
			i++;
		}
	}
	return n;
}