#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 

进阶：

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/



/*189-旋转数组暴力法*/
void rotate(int* nums, int numsSize, int k){
	if (nums == NULL){
		return;
	}
	int t;
	while (k--){
		int j = numsSize - 1;
		t = nums[j];
		while (j){
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = t;
	}
}
/*三次翻转法*/
/*
解题思路：使用三次逆转法，让数组旋转k次
1. 先整体逆转
2. 逆转子数组[0, k - 1]
3. 逆转子数组[k, size - 1]
*/
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		++begin;
		--end;
	}
}

// 三趟逆置倒的思路
void rotate(int* nums, int numsSize, int k){
	if (k > numsSize)
	{
		k %= numsSize;
	}

	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}
void test(){
	int nums[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	rotate(nums, 7, 3);
	int i = 0;
	while (i<7){
		printf("%d\n", nums[i]);
		i++;
	}
}
int main(){
	test();
	system("pause");
	return 0;
}