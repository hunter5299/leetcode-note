#define _CRT_SECURE_NO_WARNINGS 1
/*����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�*/


int maxSubArray(int* nums, int numsSize){
	//̰���㷨
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