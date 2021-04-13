#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int removeDuplicates(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	//辅助指针p、q
	int q, p;
	p = 0;
	q = 1;
	//当q还未指向最后元素时，执行功能
	while (q<numsSize){
		//若两元素不相等时，则将p往前移一位，q赋值给p
		if (nums[q] != nums[p]){
			p++;
			nums[p] = nums[q];
		}
		q++;
	}
	return p + 1;
}