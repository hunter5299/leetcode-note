#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
using namespace std;

/*
	给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，
	并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		for (i = 0; i<nums.size() - 1; i++)
		{
			for (j = i + 1; j<nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return{ i, j };
				}
			}
		}
		return{ i, j };
	}
};
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//建立hash表存放数组元素
		vector<int> b(2, -1);//存放结果
		for (int i = 0; i<nums.size(); i++)
			a.insert(map<int, int>::value_type(nums[i], i));
		for (int i = 0; i<nums.size(); i++)
		{
			if (a.count(target - nums[i])>0 && (a[target - nums[i]] != i))
				//判断是否找到目标元素且目标元素不能是本身
			{
				b[0] = i;
				b[1] = a[target - nums[i]];
				break;
			}
		}
		return b;
	}

};