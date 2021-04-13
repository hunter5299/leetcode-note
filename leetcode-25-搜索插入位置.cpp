#define _CRT_SECURE_NO_WARNINGS 1

/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。*/


int searchInsert(int* nums, int numsSize, int target){
	/*复杂度为n，暴力法
	if(nums==NULL||numsSize==0){
	return -1;
	}
	int i=0;
	for(i=0;i<numsSize;i++){
	if(nums[i]>=target){
	return i;
	}
	else if((i+1)==numsSize){
	return numsSize;
	}
	}*/
	/*二分查找 时间复杂度logn*/
	int right = numsSize - 1;
	int left = 0;
	int mid;
	int ans = numsSize;
	while (left <= right){
		mid = (right - left) / 2 + left;
		if (nums[mid] >= target){
			ans = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return ans;
}