#define _CRT_SECURE_NO_WARNINGS 1
/*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。*/


int maxSubArray(int* nums, int numsSize){
	//贪心算法
	int     i = 0;
	int     iMax = nums[0];
	int     iBig = nums[0];

	for (i = 1; i < numsSize; i++)
	{
		iBig = (iBig + nums[i] > nums[i]) ? (iBig + nums[i]) : (nums[i]);
		if (iBig > iMax)
		{
			iMax = iBig;
		}
	}
	return iMax;
}