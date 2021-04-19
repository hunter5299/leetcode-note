#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
已知函数 signFunc(x) 将会根据 x 的正负返回特定值：

如果 x 是正数，返回 1 。
如果 x 是负数，返回 -1 。
如果 x 是等于 0 ，返回 0 。
给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。

返回 signFunc(product) 。
*/

//这题若直接相乘，会造成数值溢出，只能将数组每个元素的符号取出相乘就行

int arraySign(int* nums, int numsSize){
	//初始negative是1
	int sign = 1;
	for (int i = 0; i<numsSize; i++){
		//若有元素是0，则直接返回0
		if (nums[i] == 0){
			return 0;
		}

		//若元素二进制的最高位是1，则是负数，negat乘以-1
		else if (((nums[i] >> 31) & 1) == 1){
			sign *= -1;
		}
		//若最高位不是1，则是0，是正数，negative乘以1；
		else{
			sign *= 1;
		}
	}
	return sign;
}