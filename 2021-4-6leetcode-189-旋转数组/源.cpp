#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*189-��ת���鱩����*/
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
/*���η�ת��*/
/*
����˼·��ʹ��������ת������������תk��
1. ��������ת
2. ��ת������[0, k - 1]
3. ��ת������[k, size - 1]
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

// �������õ���˼·
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