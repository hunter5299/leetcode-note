#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"ListNode.h"
int* plusOne(int* digits, int digitsSize, int* returnSize){
	if (digits == NULL){
		return NULL;
	}
	//flag为进位标志，t为临时变量，i为数组下标
	int flag = 0, t = 0, i = 0;
	int* arr = (int*)malloc(sizeof(int)*(digitsSize + 1));

	//先将末尾元素加一，完成题目要求
	digits[digitsSize - 1] += 1;

	//对数组每个元素移植到新数组
	for (i = digitsSize - 1; i >= 0; i--){
		t = digits[i] + flag;
		flag = 0;

		//若t>=10，则进位
		if (t >= 10){
			flag = 1;
			t = t % 10;
		}
		arr[i] = t;
	}

	//若数字最高位完成移植后，flag为仍需进位，则依次将元素往后移动一位，最高位补1
	if (i<0 && flag){
		for (int j = digitsSize; j>0; j--){
			arr[j] = arr[j - 1];
		}
		arr[0] = 1;
	}
	*returnSize = digitsSize + flag;
	return arr;
}